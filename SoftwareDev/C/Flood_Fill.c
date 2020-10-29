/* Implementation of Flood Fill Algorithm
*
*  @author Pranav Yadav
*/

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

// user defined func to fill the polygon are
void floodfill4(int x, int y, int fillcolor, int oldcolor)
{
	/* getpixel() is a predefined func in graphics.h,
	   it returns the colour of pixel; of coordinate passed
	*/
	if (getpixel(x, y) == oldcolor)
	{
		setcolor(fillcolor);
		putpixel(x, y, fillcolor);
		putpixel(x, y, fillcolor);
		
		floodfill4(x + 1, y, fillcolor, oldcolor)
		floodfill4(x - 1, y, fillcolor, oldcolor);
		floodfill4(x, y + 1, fillcolor, oldcolor)
		floodfill4(x, y - 1, fillcolor, oldcolor);

	}

}

//driver function
int main()
{
	// request auto detect for graphics driver
	int gd = DETECT, gm;
	
	/* initgraph() is predefined func in graphics.h, 
	   it is used to initialize the graph
	*/
	initgraph(&gd, &gm, "C://Turboc3//BGI");

	// calling rectangle() func, it is predefined in graphics.h
	rectangle(50, 50, 100, 100);

	// calling floodfill() func, it is user defined func
	floodfill4(55, 55, 9, 0);
	getch();
	
	/* closegraph() is a predefined fuction, used to close the graph provided in 
	*  'graphics.h' header file
	*/
	closegraph();
	
	return 0;
}
