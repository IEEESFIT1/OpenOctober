/* Implementation of Boundary Fill Algorithm
*
*  @author Pranav Yadav
*/

#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

//user defined func, used to fill the area of polygon
void boundaryFill4(int x, int y, int fill, int boundary)
{
	int current;
	
	/* getpixel() is a predefined func in graphics.h,
	* it returns the colour of pixel; of coordinate passed
	*/
	current = getpixel(x, y);
	if ((current != boundary) && (current != fill))
	{
		setcolor(fill);
		putpixel(x, y, fill);
		delay(5);
		boundaryFill4(x + 1, y, fill, boundary);
		boundaryFill4(x, y + 1, fill, boundary);
		boundaryFill4(x - 1, y, fill, boundary);
		boundaryFill4(x, y - 1, fill, boundary);
	}
}

//driver function
int main()
{
	// request auto detect for graphics driver
	int gd = DETECT, gm;
	
	/* initgraph() is predefined func in graphics.h, 
	*  it is used to initialize the graph
	*/
	initgraph(&gd, &gm, "C://Turboc3//BGI");
	setcolor(15);

	// calling rectangle function, it is predefined func provided in graphics.h
	rectangle(250,200,300,255);
	
	// function call passing coordinates of vertices
	boundaryFill4(280, 250, 13, 15);
	getch();
	
	/* closegraph() is a predefined fuction, used to close the graph provided in 
	*  'graphics.h' header file
	*/
	closegraph();

	return 0;
}
