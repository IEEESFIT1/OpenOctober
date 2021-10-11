#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main()
{
 int gd=DETECT,gm;
 float p,x,y,xc,yc,a,b;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 cleardevice();
 printf("Enter center coordinates: ");
 scanf("%f%f",&xc,&yc);
 printf("Enter two radius: ");
 scanf("%f%f",&a,&b);
 x=0;
 y=b;
 
 p=(b*b)-(a*a*b)+(0.25*a*a);
 while(2*b*b*x<2*a*a*y)
 {
  putpixel(xc+x,yc+y,WHITE);
  putpixel(xc+x,yc-y,WHITE);
  putpixel(xc-x,yc+y,WHITE);
  putpixel(xc-x,yc-y,WHITE);
  if(p<0)
  {
   x=x+1;
   p=p+2*b*b*x+b*b;
  }
  else
  {
   x=x+1;
   y=y-1;
   p=p+2*b*b*x-2*a*a*y+b*b;
  }
 }

 p=(b*b*(x+0.5)*(x+0.5))+((y-1)*(y-1)*a*a-a*a*b*b);
 while(y!=0)
 {
  putpixel(xc+x,yc+y,WHITE);
  putpixel(xc+x,yc-y,WHITE);
  putpixel(xc-x,yc+y,WHITE);
  putpixel(xc-x,yc-y,WHITE);
  if(p>0)
  {
   y=y-1;
   p=p-2*a*a*y+a*a;
  }
  else
  {
   x=x+1;
   y=y-1;
   p=p-2*a*a*y+2*b*b*x+a*a;
  }
 }
 setcolor(WHITE);
 line(xc,yc-b,xc,yc+b);
 line(xc-a,yc,xc+a,yc);

 setfillstyle(1,6);
 floodfill(xc+10,yc-10,15);
 setfillstyle(1,3);
 floodfill(xc+10,yc+10,15);
 setfillstyle(1,4);
 floodfill(xc-10,yc-10,15);
 setfillstyle(1,8);
 floodfill(xc-10,yc+10,15);

 getch();
 closegraph();
 restorecrtmode();
}
