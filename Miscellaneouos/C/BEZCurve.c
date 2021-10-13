#include <stdio.h>
#include<conio.h>
#include <graphics.h>
#include <math.h>

void main()
{
int gd = DETECT, gm;
initgraph (&gd, &gm, "C:\\TURBOC3\\BGI");
int z;
/*int x1[4], y1[4],x2[4],y2[4];
printf("First half coordinates : ");
printf("Enter points P1(x1,y1),P2(x2,y2),P3(x3,y3),P4(x4,y4): ");
for(z=0;z<4;z++)
{
scanf("%d",&x1[z]);
scanf("%d",&y1[z]);
}
printf("Coordinates for second part: ");
for(z=0;z<4;z++)
{
scanf("%d",&x2[z]);
scanf("%d",&y2[z]);
}



/*int x[4]={200,130,200,200};
int y[4]={400,150,75,280};*/
int x1[4] = {200,130,110,200};
int y1[4] = {300,200,100,180};
int x2[4] = {200,270,290,200};
int y2[4] = {300,200,100,180};
int i;
double t,xt,yt,xtt,ytt;
for (t = 0.0; t < 1.0; t += 0.001)
{
xt = pow(1-t,3)*x1[0]+3*t*pow(1-t,2)*x1[1]+3*pow(t,2)*(1-t)*x1[2]+pow(t,3)*x1[3];
yt = pow(1-t,3)*y1[0]+3*t*pow(1-t,2)*y1[1]+3*pow(t,2)*(1-t)*y1[2]+pow(t,3)*y1[3];

putpixel (xt, yt,WHITE);
}
for (t = 0.0; t < 1.0; t += 0.001)
{
xtt = pow(1-t,3)*x2[0]+3*t*pow(1-t,2)*x2[1]+3*pow(t,2)*(1-t)*x2[2]+pow(t,3)*x2[3];
ytt = pow(1-t,3)*y2[0]+3*t*pow(1-t,2)*y2[1]+3*pow(t,2)*(1-t)*y2[2]+pow(t,3)*y2[3];

putpixel (xtt, ytt,WHITE);
}

setfillstyle(1,13);
floodfill(x1[0],y1[0]-50,15);


for (i=0; i<4; i++)
 putpixel (x1[i], y1[i], YELLOW);
 putpixel (x2[i], y2[i], YELLOW);

getch();
closegraph();
}