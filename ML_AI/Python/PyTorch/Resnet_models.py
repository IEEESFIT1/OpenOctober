
#This module defines the ResNet model (built from scratch)
#It contains several classes representing the building blocks of the model,
#and the full ResNet34 and ResNet50 models

import math
import torch
import torch.nn as nn

#the datatype of the variables(tensor)
DTYPE = torch.cuda.FloatTensor


class Flatten(nn.Module):
    """
    NN module to flatten a tensor from 4D to 2D
    Flattens a 4D tensor outputed from a Convolution (N,C,H,W),
    to a 2D tensor ready to be consumed by a Linear layer (N,C*H*W)
    """

    def forward(self, x):
        """
        Get the dimensions of the input and reshape it to (N,-1)
        Use PyTorch's Tensor view method to reshape the input to (N,C*H*W)
        """
        num = x.shape[0]
        return x.view(num, -1)


class ResidualLayer(nn.Module):
    """
    NN module that performs the residual mapping

    This module performs the operation of element-wise sum that takes places
    at the end of each residual block

    Attributes:
        downsampling (boolean): indicates if dimension downsampling occurred
        res_input (Tensor): the residual block input (identity)
    """

    def __init__(self, res_input, projection, downsampling=False):
        super().__init__()
        self.downsampling = downsampling
        self.projection = projection
        self.res_input = res_input

    def forward(self, x):
        """
        Perform residual mapping

        Does the element-wise sum between the residual block identity and
        the input of this module. If downsampling occurs, perform a 1x1
        convolution to match dimensions and number of channels

        Returns
            Tensor: sum between residual block identity and input
        """
        if self.projection:
            stride = 2 if self.downsampling else 1
            shortcut_conv = nn.Sequential(
                nn.Conv2d(
                    self.res_input.shape[1],
                    x.shape[1],
                    kernel_size=1,
                    stride=stride,
                    padding=0), nn.BatchNorm2d(x.shape[1])).type(DTYPE)
            output = shortcut_conv(self.res_input) + x
        else:
            output = self.res_input + x
        return output


class ResidualBlock(nn.Module):
    """
    NN module containing a full residual block

    Init the model with the first part of the block, then call the residual
    layer and final relu in the forward method

    Attributes:
        input_channels (int): number of channels in the input
        output_channels (int): number of channels to output
        downsampling (boolean): indicates if dimension downsampling occurs
    """

    def __init__(self,
                 input_channels,
                 output_channels,
                 downsampling=False,
                 bottleneck=False,
                 bottleneck_factor=4,
                 pre_activation=False):
        super().__init__()

        self.downsampling = downsampling
        self.projection = input_channels != output_channels
        self.pre_activation = pre_activation
        stride = 2 if downsampling else 1
        bottleneck_channels = int(input_channels / bottleneck_factor)
        if bottleneck:
            if pre_activation:
                self.model = nn.Sequential(
                    nn.BatchNorm2d(input_channels), nn.ReLU(),
                    nn.Conv2d(
                        input_channels,
                        bottleneck_channels,
                        kernel_size=1,
                        stride=stride,
                        padding=0), nn.BatchNorm2d(bottleneck_channels),
                    nn.ReLU(),
                    nn.Conv2d(
                        bottleneck_channels,
                        bottleneck_channels,
                        kernel_size=3,
                        stride=1,
                        padding=1), nn.BatchNorm2d(bottleneck_channels),
                    nn.ReLU(),
                    nn.Conv2d(
                        bottleneck_channels,
                        output_channels,
                        kernel_size=1,
                        stride=1,
                        padding=0))
            else:
                self.model = nn.Sequential(
                    nn.Conv2d(
                        input_channels,
                        bottleneck_channels,
                        kernel_size=1,
                        stride=stride,
                        padding=0), nn.BatchNorm2d(bottleneck_channels),
                    nn.ReLU(),
                    nn.Conv2d(
                        bottleneck_channels,
                        bottleneck_channels,
                        kernel_size=3,
                        stride=1,
                        padding=1), nn.BatchNorm2d(bottleneck_channels),
                    nn.ReLU(),
                    nn.Conv2d(
                        bottleneck_channels,
                        output_channels,
                        kernel_size=1,
                        stride=1,
                        padding=0), nn.BatchNorm2d(output_channels))
        else:
            self.model = nn.Sequential(
                nn.Conv2d(
                    input_channels,
                    output_channels,
                    kernel_size=3,
                    stride=stride,
                    padding=1), nn.BatchNorm2d(output_channels), nn.ReLU(),
                nn.Conv2d(
                    output_channels,
                    output_channels,
                    kernel_size=3,
                    stride=1,
                    padding=1), nn.BatchNorm2d(output_channels))

    def forward(self, x):
        """
        Run the initial part of the residual block, then instantiate and run
        the residual mapping layer and the final relu

        Returns:
            Tensor: final output of the residual block
        """
        output = self.model(x)
        residual_layer = ResidualLayer(x, self.projection,
                                       self.downsampling).type(DTYPE)
        output = residual_layer(output)
        relu = nn.ReLU()
        return output if self.pre_activation else relu(output)


class ResNet34(nn.Module):
    """
    NN Module containing a full ResNet34 model
    """

    def __init__(self, num_classes):
        super().__init__()
        self.name = 'ResNet34'
        self.model = nn.Sequential(
            nn.Conv2d(3, 64, kernel_size=7, stride=2, padding=2),
            nn.AvgPool2d(3, stride=2, padding=1), ResidualBlock(64, 64),
            ResidualBlock(64, 64), ResidualBlock(64, 64),
            ResidualBlock(64, 128, downsampling=True), ResidualBlock(128, 128),
            ResidualBlock(128, 128), ResidualBlock(128, 128),
            ResidualBlock(128, 256, downsampling=True), ResidualBlock(
                256, 256), ResidualBlock(256, 256), ResidualBlock(256, 256),
            ResidualBlock(256, 256), ResidualBlock(256, 256),
            ResidualBlock(256, 512, downsampling=True), ResidualBlock(
                512, 512), ResidualBlock(512, 512), nn.AdaptiveAvgPool2d(1),
            Flatten(), nn.Linear(512, num_classes))
        self._init_weights()

    def forward(self, x):
        return self.model(x)

    def _init_weights(self):
        for m in self.modules():
            if isinstance(m, nn.Conv2d):
                n = m.kernel_size[0] * m.kernel_size[1] * m.out_channels
                m.weight.data.normal_(0, math.sqrt(2. / n))
            elif isinstance(m, nn.BatchNorm2d):
                m.weight.data.fill_(1)
                m.bias.data.zero_()


class ResNet50(nn.Module):
    
    #NN Module containing a full ResNet34 model
    

    def __init__(self, num_classes, pre_activation=False):
        super().__init__()
        self.name = 'ResNet50_PreAct' if pre_activation else 'ResNet50'
        self.model = nn.Sequential(
            nn.Conv2d(3, 64, kernel_size=7, stride=2, padding=3),
            nn.MaxPool2d(3, stride=2, padding=1),
            ResidualBlock(
                64,
                256,
                bottleneck=True,
                bottleneck_factor=1,
                pre_activation=pre_activation),
            ResidualBlock(
                256, 256, bottleneck=True, pre_activation=pre_activation),
            ResidualBlock(
                256, 256, bottleneck=True, pre_activation=pre_activation),
            ResidualBlock(
                256,
                512,
                bottleneck=True,
                downsampling=True,
                bottleneck_factor=2,
                pre_activation=pre_activation),
            ResidualBlock(
                512, 512, bottleneck=True, pre_activation=pre_activation),
            ResidualBlock(
                512, 512, bottleneck=True, pre_activation=pre_activation),
            ResidualBlock(
                512, 512, bottleneck=True, pre_activation=pre_activation),
            ResidualBlock(
                512,
                1024,
                bottleneck=True,
                downsampling=True,
                bottleneck_factor=2,
                pre_activation=pre_activation),
            ResidualBlock(
                1024, 1024, bottleneck=True, pre_activation=pre_activation),
            ResidualBlock(
                1024, 1024, bottleneck=True, pre_activation=pre_activation),
            ResidualBlock(
                1024, 1024, bottleneck=True, pre_activation=pre_activation),
            ResidualBlock(
                1024, 1024, bottleneck=True, pre_activation=pre_activation),
            ResidualBlock(
                1024, 1024, bottleneck=True, pre_activation=pre_activation),
            ResidualBlock(
                1024,
                2048,
                bottleneck=True,
                downsampling=True,
                bottleneck_factor=2,
                pre_activation=pre_activation),
            ResidualBlock(
                2048, 2048, bottleneck=True, pre_activation=pre_activation),
            ResidualBlock(
                2048, 2048, bottleneck=True, pre_activation=pre_activation),
            nn.AvgPool2d(7, stride=1), Flatten(), nn.Linear(2048, num_classes))
        self._init_weights()

    def forward(self, x):
        return self.model(x)

    def _init_weights(self):
        for m in self.modules():
            if isinstance(m, nn.Conv2d):
                n = m.kernel_size[0] * m.kernel_size[1] * m.out_channels
                m.weight.data.normal_(0, math.sqrt(2. / n))
            elif isinstance(m, nn.BatchNorm2d):
                m.weight.data.fill_(1)
                m.bias.data.zero_()
