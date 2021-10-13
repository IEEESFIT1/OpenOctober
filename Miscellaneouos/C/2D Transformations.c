#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void translate();
void scale();
void rotate();
void reflect();
void shear();
void main()
{
int ch;
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
setcolor(6);
outtextxy (100,88,"Object.");
rectangle(100,150,150,100);
printf("--------MENU--------");
printf("\n 1)Translate\t 2)Scale\t 3)Rotate\t 4)Reflect\t 5)shear");
printf("\nEnter your choice: ");
scanf("%d",&ch);
cleardevice();
switch(ch)
{
case 1: translate();
break;
case 2: scale();
break;
case 3: rotate();
break;
case 4: reflect();
break;
case 5: shear();
break;
default: printf("you have enterd wrong choice");
break;
}
getch();
closegraph();
}

void translate()
{
int tx,ty;
setcolor(2);
outtextxy(240,10,"TRANSLATION");
outtextxy(238,20,"------------");
printf("\nEnter tx: ");
scanf("%d",&tx);
printf("\nEnter ty: ");
scanf("%d",&ty);
rectangle(200,250,250,200);
printf("\nAfter Translation");
rectangle(200+tx,250+ty,250+tx,200+ty);
}
void scale()
{
int sx,sy;
setcolor(2);
outtextxy(240,10,"SCALING");
outtextxy(238,20,"--------");
printf("Enter sx: ");
scanf("%d",&sx);
printf("Enter sy: ");
scanf("%d",&sy);
rectangle(100,150,150,100);
outtextxy(50,200,"After Scaling");
rectangle(100*sx,150*sy,150*sx,100*sy);
}
void rotate()
{
float theta;
int x1,x2,x3,x4;
int y1,y2,y3,y4;
int ax1,ax2,ax3,ax4,ay1,ay2,ay3,ay4;
int refx,refy;
setcolor(2);
outtextxy(240,10,"ROTATE");
outtextxy(238,20,"-------");
printf("\nEnter the angle for rotation: ");
scanf("%f",&theta);
theta=theta*(3.14/180);
refx=100;
refy=100;
x1=100;
y1=100;
x2=150;
y2=100;
x3=150;
y3=150;
x4=100;
y4=150;
ax1=refy+(x1-refx)*cos(theta)-(y1-refy)*sin(theta);
ay1=refy+(x1-refx)*sin(theta)+(y1-refy)*cos(theta);
ax2=refy+(x2-refx)*cos(theta)-(y2-refy)*sin(theta);
ay2=refy+(x2-refx)*sin(theta)+(y2-refy)*cos(theta);
ax3=refy+(x3-refx)*cos(theta)-(y3-refy)*sin(theta);
ay3=refy+(x3-refx)*sin(theta)+(y3-refy)*cos(theta);
ax4=refy+(x4-refx)*cos(theta)-(y4-refy)*sin(theta);
ay4=refy+(x4-refx)*sin(theta)+(y4-refy)*cos(theta);
rectangle(100,150,150,100);
line(ax1,ay1,ax2,ay2);
line(ax2,ay2,ax3,ay3);
line(ax3,ay3,ax4,ay4);
line(ax4,ay4,ax1,ay1);
}
void reflect()
{
int x1,x2,x3,x4;
int y1,y2,y3,y4;
int a;
int refx,refy;
cleardevice();
setcolor(2);
outtextxy(240,10,"REFLECT");
outtextxy(238,20,"-------");
refx=100;
refy=100;
x1=200;
y1=200;
x2=250;
y2=200;
x3=250;
y3=250;
x4=200;
y4=250;
rectangle(200,250,250,200);
printf("\n1 --> x-axis\t 2 --> y-axis\nEnter the axis of reflection: ");
scanf("%d",&a);
if(a==1)
{
line(100,300,350,300);
outtextxy(400,300,"x-axis");
y1=y1+150;
y2=y2+150;
y3=y3+150;
y4=y4+150;
}
else if(a==2)
{
line(350,100,350,350);
outtextxy(350,400,"y-axis");
x1+=250;
x2+=250;
x3+=250;
x4+=250;
}
getch();
printf("\n\n After reflection: ");
line(x1,y1,x2,y2);
line(x2,y2,x3,y3);
line(x3,y3,x4,y4);
line(x4,y4,x1,y1);
}
void shear()
{
int x1,x2,x3,x4;
int y1,y2,y3,y4;
int a;
float shx,shy;
cleardevice();
setcolor(2);
outtextxy(240,10," shear");
outtextxy(238,20,"----------");
x1=200;
y1=200;
x2=250;
y2=200;
x3=250;
y3=250;
x4=200;
y4=250;
rectangle(200,250,250,200);
printf("\n1 --> x-axis\t 2 --> y-axis\nEnter the axis of reflection: ");
scanf("%d",&a);
if(a==1)
{
printf("enter the value for x-axis shear( can be fraction too):");
scanf("%f",&shx);
}
else
{
printf("enter the value for y-axis shear( can be fraction too):");
scanf("%f",&shy);
}
getch();
setcolor(58);
if(a==1)
{
line(x1+shx*y1,y1,x2+shx*y2,y2);
line(x2+shx*y2,y2,x3,y3);
line(x3,y3,x4,y4);
line(x4,y4,x1+shx*y1,y1);
}
else
{
line(x1,y1,x2,y2+shy*x2);
line(x2,y2+shy*x2,x3,y3+shy*x3);
line(x3,y3+shy*x3,x4,y4);
line(x4,y4,x1,y1);
}
}