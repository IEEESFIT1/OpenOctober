/*This program addresses the procedure and code for detecting a cycle in a directed graph. */
#include <stdio.h>
#include <stdlib.h>

//These are the edges of the graph
// Inputs include 1. d = The weight or the distance
// 2. p1 & p2 are the vertices that this edge connects.
struct xe
{
	int d;
	int p1;
	int p2;
};

int main()
{
	int graph[50][50];// This will show the distances between the edges or these are called the edge weights.
	#int v, i, j, k, dst, x; // v= Number of vertices
	int dist[50], prev[50], count, temp[50], ct, min, prevs[50], dists[50], path[50];
	int gtemp[50][50], r, s, jj, ii, disttemp[50][50], prevtemp[50][50], m;
	int g1, g2, mo;
	struct xe arr[20], h, final[50];//These are the edges.
	printf("Enter the number of vertices in the graph:\n");
	scanf("%d", &v);
	for(i = 0; i < v; i++)
	{
		for(j = 0; j < v; j++)
		{
			graph[i][j] = 0;// Initializing all the distances/weights to be zero.
		}
	}
	// Assume that the graph is undirected
	k = 1;
	m = 0;
	while(k)
	{
		printf("Which two vertices do you want to connect:\n");
		scanf("%d", &i);
		scanf("%d", &j);
		arr[m].p1 = i;//m=0, these are the edges that have 2 pointers p1 and p2 that act like an edge and have a variable d that is the distance.
		arr[m].p2 = j;
		printf("Distance between %dth and %dth node:\n", i, j);
		scanf("%d", &dst);
		arr[m].d = dst;
		graph[i-1][j-1] = dst;
		printf("Do you want to connect more (1:Yes; 0:No):\n");
		scanf("%d", &k);
		m++;
	}
	printf("There are %d connections.\n", m);
	for(i = 0; i < v; i++) // Printing the graph.
	{
		for(j = 0; j < v; j++)
		{
			printf("  %d  ", graph[i][j]);
		}
		printf("\n\n");
	}
	
	for(i = 0; i < m; i++) //Sorting the edges in ascending order according to weights.
	{
		for(j = 0; j < m-1; j++)
		{
			if(arr[j].d >= arr[j+1].d)
			{
				h.d = arr[j].d;
				h.p1 = arr[j].p1;
				h.p2 = arr[j].p2;
				arr[j].d = arr[j+1].d;
				arr[j].p1 = arr[j+1].p1;
				arr[j].p2 = arr[j+1].p2;
				arr[j+1].d = h.d;
				arr[j+1].p1 = h.p1;
				arr[j+1].p2 = h.p2;
			}
		}
	}
	i = 0;
	j = 0;
	mo = 0;
	
	// v is the number of vertices
	while(i != v)
	{
		r = 0;
		s = 0;
		if(i == 0 || i == 1)
		{
			final[i].d = arr[i].d;
			final[i].p1 = arr[i].p1;
			final[i].p2 = arr[i].p2;
		}
		else
		{
			g1 = arr[j].p1;// p1 and p2 represent the nodes.
			g2 = arr[j].p2;
			
			//We will be checking the cycle here by comparing the edges
			for(ii = 0; ii < i; ii++)
			{
				if(g1 == final[ii].p2)
				{
					r = 1;
				}
			}
			for(ii = 0; ii < i; ii++)
			{
				if(g2 == final[ii].p1)
				{
					s = 1;
				}
			}
			if(r+s == 2)//If there is a cycle only the sum will come out to be 2
			{
				j++;
				mo = 1;
				break;
			}
			else
			{
				final[i].d = arr[j].d;
				final[i].p1 = arr[j].p1;
				final[i].p2 = arr[j].p2;
			}
		}
		i++;
		j++;
	}
	if(mo == 1)
	{
		printf("Cycle is present.");
	}
	else
	{
		printf("Cycle is not present.");
	}
}
