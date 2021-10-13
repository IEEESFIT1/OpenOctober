#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

void draw(float xc, float yc, float r)
{
   float x = 0;
   float y = r;
   float pk;
   pk = 1 - r;

   while(x < y){
      delay(10);
      putpixel((xc+x),(yc+y),WHITE);
      putpixel((xc+x),(yc-y),WHITE);
      putpixel((xc-x),(yc+y),WHITE);
      putpixel((xc-x),(yc-y),WHITE);
      putpixel((xc+y),(yc+x),WHITE);
      putpixel((xc+y),(yc-x),WHITE);
      putpixel((xc-y),(yc+x),WHITE);
      putpixel((xc-y),(yc-x),WHITE);

      if(pk<0){
	 x += 1;
	 pk = pk + (2 * x) + 1;
      }
      else{
	 x += 1; y -= 1;
	 pk = pk + (2 * x) + 1 - (2 * y);
      }
   }
   line (xc,yc+r,xc,yc-r);
   line (xc+r,yc,xc-r,yc);
   line (xc+x,yc+y,xc-x,yc-y);
   line (xc-x,yc+y,xc+x,yc-y);

   setfillstyle(1,1);
   floodfill(xc+1, yc+(r/2), WHITE);
   setfillstyle(1,2);
   floodfill(xc-1, yc+(r/2), WHITE);
   setfillstyle(1,3);
   floodfill(xc+1, yc-(r/2), WHITE);
   setfillstyle(1,4);
   floodfill(xc-1, yc-(r/2), WHITE)
   ;
   setfillstyle(1,5);
   floodfill(xc+(r/2), yc+1, WHITE);
   setfillstyle(1,6);
   floodfill(xc+(r/2), yc-1, WHITE);
   setfillstyle(1,7);
   floodfill(xc-(r/2), yc+1, WHITE);
   setfillstyle(1,8);
   floodfill(xc-(r/2), yc-1, WHITE);

}

void main()
{
   clrscr();
   int gdriver = DETECT, gmode;
   float xc, yc,r;

   initgraph(&gdriver,&gmode,"C:\\TC\\BGI");

   printf("Enter the center coordinate : ");
   scanf("%f %f",&xc,&yc);
   printf("Enter the Radius : ");
   scanf("%f",&r);
   draw(xc,yc,r);

   getch();
   closegraph();

}
