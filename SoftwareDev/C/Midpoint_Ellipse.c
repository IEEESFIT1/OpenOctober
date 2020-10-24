/* Implementation of Midpoint Ellipse Generation Algorithm
*  
*  @author Pranav Yadav
*/

#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>

/* user defined function used to project (plot) points on quadrant,
*  by using symmetry of ellipse
*/
void plot(int xc, int yc, int x, int y)
{
	putpixel(xc+x, yc+y, WHITE);
	putpixel(xc-x, yc-y, WHITE); 
	putpixel(xc+x, yc-y, WHITE);
	putpixel(xc-x, yc+y, WHITE);
}

/* midpt_ellipse() is a user defined function used to, 
*  calculate the decision parameter, 
*  on basis which, first point is plotted
*/
void midpt_ellipse(int xc, int yc, int rx, int ry)
{
	int x, y;
	float d1, d2, dx, dy;
	x = 0
	y = ry;
	
	// calculation of decision parameter
	d1 = pow(ry, 2)- (pow(rx,2) * ry) + (0.25*pow(rx,2));
	
	dx = 2 * pow(ry,2) * x;
	dy = 2 * pow(rx,2) * y;
	
	//Starting of Region - I 
	do
	{
		plot(xc, yc, x, y);
		
		if(d1 < 0)
		{
			x++;
			dx += 2 * (pow(ry, 2));
			d1 += dx + (pow(ry, 2));
		}
		else
		{
			x++;
			y--;
			dx += 2 * (pow(ry, 2));
			dy -= 2 * (pow(rx, 2));
			d1 += dx - dy + (pow(ry, 2));	
		}
		//when dx >= dy ==> End of Region - I
	}while(dx < dy);
	
	//Starting of Region - II
	do
	{
		plot(xc, yc, x, y);
		
		if(d2 > 0)
		{
			//x remains unchanged
			y--;
			dy -= 2 * (pow(rx, 2));
			d2 -= dy + (pow(rx, 2));
		}
		else
		{
			x++;
			y--;
			dx += 2 * (pow(ry, 2));
			dy -= 2 * (pow(rx, 2));
			d2 += dx - dy + (pow(ry, 2));	
		}	
	}while(y > 0);
	
}

// driver function
int main()
{
	// request auto detect for graphics driver
	int gd = DETECT, gm;
	int xc, yc;
	float rx, ry;
	
	/* initgraph() is a predefined function, used to initiate graph,
	*  privided in 'graphics.h' header file
	*  path of graphics libraries must be provided
	*/
	initgraph(&gd,&gm,"c:\\tcplus\\bgi");
	
	//clrscr(); user specific
	
	printf("Midpoint Ellipse Generation Algorithm\n");
	printf("Enter co-ordinates of center of ellipse : ");
	scanf("%d%d",&xc,&yc);
	printf("\nEnter value of 'rx' and 'ry' : ");
	scanf("%f%f",&rx,&ry);
	
	/* function call through which coordinates of center of ellipse and
	 * it's semi-major and semi-minor axes are passed
	*/
	midpt_ellipse(xc,yc,rx,ry);
	
	/* getch() is a predefined function, used to pause the execution of program
	*  before closing the graph, untill any character is entered 
	*/
	getch();
	
	/* closegraph() is a predefined function, used to close the graph
	*  provided in 'graphics.h' header file
	*/
	closegraph();
	
	return 0;
}