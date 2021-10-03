# -*- coding: utf-8 -*-
"""

The entire code is based on pytorch, please refer to this link for more info: https://pytorch.org/tutorials/beginner/data_loading_tutorial.html

"""

#importing necessary packages
import torch
import torchvision.datasets as dset
from torch.utils.data import DataLoader
from torch.utils.data import sampler
import torchvision.transforms as transforms


# Sampler to iterate on dataset, given size and start point
class ChunkSampler(sampler.Sampler):
    def __init__(self, num_samples, start=0):
        self.num_samples = num_samples
        self.start = start

    #this function iterates throught the dataset and gives examples 
    def __iter__(self):
        return iter(range(self.start, self.start + self.num_samples))

    #this function returns the size of the dataset
    def __len__(self):
        return self.num_samples

#declare all the presets
NUM_TRAIN = 49000 
NUM_VAL = 1000
BATCH_SIZE = 40
dtype = torch.cuda.FloatTensor

#using this class train, test, and validation dataloaders can be made
class Cifar10DataLoader:
    def __init__(self):
        #defining transformations, you may apply your own
        transform = transforms.Compose(
            [transforms.Resize((224, 224)),
             transforms.ToTensor()])
        self.name = 'cifar10'
        print('Downloading dataset...')
        train_set = dset.CIFAR10(
            './dataloaders/datasets/cifar10', #replace with your own path
            train=True,
            download=True,
            transform=transform)
        self.train = DataLoader(
            train_set,
            batch_size=BATCH_SIZE,
            sampler=ChunkSampler(NUM_TRAIN, 0),
            num_workers=4)
        val_set = dset.CIFAR10(
            './dataloaders/datasets/cifar10', #replace with your own path
            train=True,
            download=True,
            transform=transform)
        self.val = DataLoader(
            val_set,
            batch_size=BATCH_SIZE,
            sampler=ChunkSampler(NUM_VAL, NUM_TRAIN),
            num_workers=4)
        test_set = dset.CIFAR10(
            './dataloaders/datasets/cifar10', #replace with your own path
            train=False,
            download=True,
            transform=transform)
        self.test = DataLoader(test_set, batch_size=BATCH_SIZE, num_workers=4)
