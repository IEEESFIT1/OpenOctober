/* Implementation of DDA Line Drawing Algorithm
*  
*  @author Pranav Yadav
*/

#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>

void dda(int x1, int y1, int x2, int y2)
{
	int i, dx, dy, steps;
	float x, y, xinc, yinc;
	dx = x2 - x1;
	dy = y2 - y1;
	
	if(abs(dx) >= abs(dy))
	{
		steps = dx;
	}
	else
	{
		steps = dy;
	}
	
	xinc = dx / (float)steps;
	yinc = dy / (float)steps;
	x = x1;
	y = y1;
	
	/* putpixel() is a predefined function, used to plot a
	*  point on the graph, initiated by 'initgraph()'
	*  It is provided in 'graphics.h' header file
	*/
	putpixel(x,y,WHITE);
	
	for(i=1; i<steps; i++)
	{
		x = x + xinc;
		y = y + yinc;
		x1 = x + 0.5;
		y1 = y + 0.5;
		putpixel(x1,y1,WHITE);
	}
}

// driver function
int main()
{
	// request auto detect for graphics driver
	int gd = DETECT, gm;
	int x1, y1, x2, y2;
	
	/* initgraph() is a predefined function, used to initiate graph, privided in
	* 'graphics.h' header file
	*  Path for graphics libraries must be provided
	*/
	initgraph(&gd,&gm,"c:\\tcplus\\bgi");
	
	//clrscr(); can be used to clear the screen before drawing on graph
	
	//setbkcolor(RED); can be used to set background color, here RED
	printf("Enter starting points co-ordinates of line : ");
	scanf("%d%d",&x1,&y1);
	printf("\nEnter ending points co-ordinates of line : ");
	scanf("%d%d",&x2,&y2);
	
	dda(x1, y1, x2, y2);
	
	/* getch() is a predefined function, used to pause the execution of program 
	* before closing the graph, untill any character is entered 
	*/
	getch();
	
	/* closegraph() is a predefined fuction, used to close the graph 
	* provided in 'graphics.h' header file
	*/
	closegraph();
	
	return 0;
}