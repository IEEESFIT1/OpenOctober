/* Implementation of Bresenhem's Line Drawing Algorithm
*
*  @author Pranav Yadav
*/

#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>

// user defined function to get sign
float sign(float s)
{
	if(s < 0)
	    return -1;
	else if(s == 0)
	    return 0;
	else
	    return 1;
}

// user defined function used to draw a line
void bresenhem(int x1, int y1, int x2, int y2)
{
	int i, x, y, s1, s2, e;
	float dx, dy, p, temp;
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	x = x1;
	y = y1;
	s1 = sign(x2 - x1);
	s2 = sign(y2 - y1);
	
	if(dy > dx)
	{
		temp = dx;
		dx = dy;
		dy = temp;
		e = 1;
	}
	else
	{
		e = 0;
	}
	
	// calculation of initial decision parameter
	p = 2*dy - dx;
	i = 1;
	
	while(i <= dx)
	{
		/* putpixel() is a predefined function, 
		*  used to plot a point on the graph initiated by 'initgraph()'
		*  It is provided in 'graphics.h' header file
		*/
		putpixel(x,y,WHITE);
		
		//delay(10); can be used to delay plotting of next pixel
		
		while(p >= 0)
		{
			if(e == 1)
			{
			    x = x + s1;
			}
			else
			{
				y = y + s2;
				p = p + 2*dy - 2*dx;
			}
		}
		
		if(e == 1)
		{
		    y = y + s2;
		}
		else
		{
			x = x + s1;
			p = p + 2*dy;
			i++;
		}
	}
}

// driver function
int main()
{
	// request auto detect for graphics driver
	int gd = DETECT, gm;
	int x1, y1, x2, y2;
	
	/* initgraph() is a predefined function, used to initiate graph, privided in
	*  'graphics.h' header file
	*/
	initgraph(&gd,&gm,"c:\\tcplus\\bgi");
	
	//clrscr(); can be used to clear screen before drawing on graph
	// setbkcolor(RED); can be used to set background color of graph, here RED
	
	printf("Bresenham's Line Drawing Algorithm\n");
	printf("Enter starting points co-ordinates of line : ");
	scanf("%d%d",&x1,&y1);
	printf("\nEnter ending points co-ordinates of line : ");
	scanf("%d%d",&x2,&y2);
	
	// function call by passing starting and ending point coordinates of line
	bresenhem(x1,y1,x2,y2);
	
	/* getch() is a predefined function, used to 
	*  stop the output of program before closing the graph 
	*  in this case, untill any character is entered
	*/
	getch();
	
	/* closegraph() is a predefined fuction,
	*  used to close the graph provided in 'graphics.h' header file
	*/
	closegraph();
	
	return 0;
}