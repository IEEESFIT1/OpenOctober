#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

void drawcircle(int xc,int yc,int r,int color)
{
   int x,y;
   float pk;
   x=0;
   y=r;
   
   pk=1.25-r;
   do{
      putpixel((int)(x+xc),(int)(y+yc),color);
      putpixel((int)(x+xc),(int)(-y+yc),color);
      putpixel((int)(-x+xc),(int)(y+yc),color);
      putpixel((int)(-x+xc),(int)(-y+yc),color);
      putpixel((int)(y+yc),(int)(x+xc),color);
      putpixel((int)(-y+yc),(int)(x+xc),color);
      putpixel((int)(y+yc),(int)(-x+xc),color);
      putpixel((int)(-y+yc),(int)(-x+xc),color);
      {
      if(pk<0)
      {
         x=x+1;
         pk=pk+(2*x)+1;
      }
      else
      {
         x=x+1;
         y=y-1;
    pk=pk+(2*x)-(2*y)+1;
      }
      


   } 

   }
   while(x<=y);
    
   delay(10);



}
void increasingcircle(int x1,int y1,int radius,int color,int condition)
{  
   int incr=0;
   while(incr!=(radius/condition))
   {
      drawcircle(x1,y1,incr,color);
      incr=incr+1;
   }
}
void decreasingcircle(int x1,int y1,int radius,int color,int condition)
{
   while(radius>0)
   {
       drawcircle(x1,y1,radius,color);
       radius-=1;
   }
}

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode;
    int x1,y1,radius,i,temp,second=0,third=0;
 /*  int midx, midy;
   int radius = 100;*/
   initgraph(&gdriver, &gmode, "C:\\TC\\BGI");

   printf("Enter x1,y1 and and radius: ");
   scanf("%d %d %d",&x1,&y1,&radius);
   increasingcircle(x1,y1,radius,BLUE,1); 
   increasingcircle(x1,y1,radius,GREEN,2); 

   increasingcircle(x1,y1,radius,RED,3); 

   increasingcircle(x1,y1,radius,GREEN,1);
   decreasingcircle(x1,y1,radius,RED,1);
   increasingcircle(x1,y1,radius,RED,1);
   decreasingcircle(x1,y1,radius,BLUE,1);
   increasingcircle(x1,y1,radius,GREEN,1);
   decreasingcircle(x1,y1,radius,BLUE,1);
   increasingcircle(x1,y1,radius,GREEN,1);
   decreasingcircle(x1,y1,radius,BLUE,1);
   increasingcircle(x1,y1,radius,RED,1);
   decreasingcircle(x1,y1,radius,BLUE,1);
   increasingcircle(x1,y1,radius,GREEN,1);
   decreasingcircle(x1,y1,radius,BLUE,1);
    
    increasingcircle(x1,y1,radius,BLUE,1); 
   increasingcircle(x1,y1,radius,GREEN,2); 
   
   increasingcircle(x1,y1,radius,RED,3); 


   

   

   /* initialize graphics and local variables */
   
   

   /* clean up */
   getch();
   closegraph();
   return 0;
}
