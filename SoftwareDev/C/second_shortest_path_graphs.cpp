//This program contains the code to find the second shortest path.
//The source is always 0, so only taking the destination as input.

#include<limits.h>
#include<stdio.h>
#define infi INT_MAX
#define MAX 4
int parent[MAX]; 	//contains the parents of every element
int parent2[MAX];


int dijkstra(int adj_matrix[MAX][MAX], int dest);
void secondShortestPath(int adj_matrix[MAX][MAX], int dest);
int minDistance(int dist[MAX], int visited[MAX]);
void printPath(int path[MAX],int dest);

//The main driver code.

int main()
{
	//fixing the destination to two.
	int n, i, j;
    int dest=2;
	
	
	//HAving a prewritten cost matrix.
	int adj_matrix[MAX][MAX]  = { {infi, 1 , 3, 4},
						{1, infi, infi , 2},
						{3, infi , infi , 2},
						{4, 2, 2, infi}};
	n = 4;
	
	
	printf("\n Select a destination :");//Using this we can select any other elemnt as destination to check the path details.
    scanf("%d",&dest);
	
	
	printf("\n The adjacency matrix entered is :\n");
	for(i=0;i<n;i++)
	{
		for(j = 0; j < n; j++)
		{
            if(adj_matrix[i][j]!=infi)
			    printf("%d\t", adj_matrix[i][j]);
            else
                printf("inf\t");
            
		}
		printf("\n");
	}

	
	printf("\nThe shortest path from source %d to dest %d is: \n",0,dest);
	printf("Distance of source to dest is %d and the path is \n", dijkstra(adj_matrix,dest));
	printPath(parent,dest);

	secondShortestPath(adj_matrix,dest);

	return(0);
	
}


//This function calculates the min distance.
//Inputs include 1.The dist array.
//2. The visited array.
int minDistance(int dist[MAX], int visited[MAX])
{
	int min= infi;//initially the distance is huge.
	int index; // A return variable.

	for(int i=0;i<MAX;i++)
		if(!visited[i] && dist[i]<=min)//if its not yet visited and the dist is less than the minimum, it can updated or relaxed.
		{
			min = dist[i];//the minimum is getting updated.
			index = i;//index is changed to ith element in the visited array.
		}
	
	return index;
}


//Implementing dijkstras algorithm for finding the shortest path.
//Input include: 1. The adj matrix.
// 2. The destination vertex.
int dijkstra(int adj_matrix[MAX][MAX], int dest)
{
	int visited[MAX];		//to check if each node has been visited
	int dist[MAX];			//to check distance of each node


	for(int i=0;i<MAX;i++)	//initialize all the visited and distances(priorly as in dijkstras we need to have all the distances as infinite and change them as we go).
	{
		visited[i]=0;
		dist[i]=infi;
	}

	parent[0]=-1;           
	dist[0] = 0; //source is always at minimum distance to self

	for(int j=0;j<MAX-1;j++)
	{
		int c = minDistance(dist,visited);
		visited[c] = 1;//marking it as 1/visited.

		for(int adj=0;adj<MAX;adj++)
			if(!visited[adj] && adj_matrix[c][adj]!=infi && dist[c]+adj_matrix[c][adj]<dist[adj])//This is updating the previously taken distance.
			{
				parent[adj] = c;
				dist[adj] = dist[c] + adj_matrix[c][adj];//updating the distance by a smaller value.
			}
	}

	
	return dist[dest];
}

//This function is used to print the path.
//Inputs include 1. path array
// 2. The dest vertex.

void printPath(int path[MAX],int dest)
{
	if (path[dest]==-1)
	{	
		printf("%d",dest);
		return;
	}

	printPath(path,path[dest]);
	printf(" -> %d",dest);

}

//This function calculates the second shortest path avialable from source to destination.
//Inputs include 1. The adj matrix
// 2. The dest vertex.
void secondShortestPath(int adj_matrix[MAX][MAX], int dest)
{
	int mindist=infi;//initially the min dist is infi
	for(int i=dest;i!=0;i=parent[i])
	{
		
		//int temp = adj_matrix[i][parent[i]];
		int temp2 = adj_matrix[parent[i]][i];
		//adj_matrix[i][parent[i]] = inf;
		adj_matrix[parent[i]][i] = infi;

		
		if (dijkstra(adj_matrix,dest)<mindist)//checking with the dijsktras algo for the dist(min).
		{
			mindist = dijkstra(adj_matrix,dest);//updating the distance
			for(int j=0;j<MAX;j++)
				parent2[j]=parent[j];// Initializing another parent array.
		}

		//adj_matrix[i][parent[i]] = temp;
		adj_matrix[parent[i]][i] = temp2;
	}


	printf("\n\n\nThe second shortest path from source %d to dest %d is: \n",0,dest);
	printf("Distance of source to dest is %d and the path is \n",mindist);//This basically is before the final updation of the minimum distance from the source to dest.
	printPath(parent2,dest);//Printing the second smallest path.
}
