/* Maximum number of edges that can be added in a ADG. */
#include <stdio.h>
#include <stdlib.h>

struct xe
{
	int d;
	int p1;
	int p2;
};


int main()
{
	int graph[50][50];
	#int v, i, j, k, dst, x; // Number of vertices
	int unvisit[50], dist[50], prev[50], count, temp[50], ct, min, prevs[50], dists[50], path[50];
	int gtemp[50][50], r, s, jj, ii, disttemp[50][50], prevtemp[50][50], m;
	int g1, g2, mo, cnt = 0;
	struct xe arr[20], h, final[50];
	printf("Enter the number of vertices in the graph:\n");
	scanf("%d", &v);
	for(i = 0; i < v; i++)
	{
		for(j = 0; j < v; j++)
		{
			graph[i][j] = 0;
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
		arr[m].p1 = i;
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
	for(i = 0; i < m; i++)
	{	
		x = arr[i].p1;
		for(j = 0; j < m; j++)
		{
			if(arr[j].p2 == arr[i].p2 || x == arr[j].p2)
			{
				continue;
			}
			cnt++;
		}
	}
	printf("\n The max number is %d.", cnt);
}
