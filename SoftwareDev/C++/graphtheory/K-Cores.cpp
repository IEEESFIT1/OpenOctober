// Contributed by Kartikey Sharma
// Contributed to OpenOctober	
#include<bits/stdc++.h> 
using namespace std; 

class Graph 
{ 
	int V; 
	list<int> *adj; 
	public: 
		Graph(int V);  
		void addEdge(int u, int v); 
		bool DFSUtil(int, vector<bool> &, vector<int> &, int k); 
		void printKCores(int k); 
}; 

bool Graph::DFSUtil(int v, vector<bool> &visited, 
					vector<int> &vDegree, int k) 
{ 
	visited[v] = true; 

	list<int>::iterator i; 
	for (i = adj[v].begin(); i != adj[v].end(); ++i) 
	{ 
		if (vDegree[v] < k) 
			vDegree[*i]--; 

		if (!visited[*i]) 
		{ 
			if (DFSUtil(*i, visited, vDegree, k)) 
				vDegree[v]--; 
		} 
	} 

	return (vDegree[v] < k); 
} 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int u, int v) 
{ 
	adj[u].push_back(v); 
	adj[v].push_back(u); 
} 

void Graph::printKCores(int k) 
{ 
	vector<bool> visited(V, false); 
	vector<bool> processed(V, false); 

	int mindeg = INT_MAX; 
	int startvertex; 
 
	vector<int> vDegree(V); 
	for (int i=0; i<V; i++) 
	{ 
		vDegree[i] = adj[i].size(); 

		if (vDegree[i] < mindeg) 
		{ 
			mindeg = vDegree[i]; 
			startvertex=i; 
		} 
	} 

	DFSUtil(startvertex, visited, vDegree, k); 

	for (int i=0; i<V; i++) 
		if (visited[i] == false) 
			DFSUtil(i, visited, vDegree, k); 

	cout << "K-Cores : \n"; 
	for (int v=0; v<V; v++) 
	{ 
		if (vDegree[v] >= k) 
		{ 
			cout << "\n[" << v << "]"; 
			list<int>::iterator itr; 
			for (itr = adj[v].begin(); itr != adj[v].end(); ++itr) 
				if (vDegree[*itr] >= k) 
					cout << " -> " << *itr; 
		} 
	} 
} 

int main() 
{ 
	int k = 3; 
	Graph g1(9); 
	g1.addEdge(0, 1); 
	g1.addEdge(0, 2); 
	g1.addEdge(1, 2); 
	g1.addEdge(1, 5); 
	g1.addEdge(2, 3); 
	g1.addEdge(2, 4); 
	g1.addEdge(2, 5); 
	g1.addEdge(2, 6); 
	g1.addEdge(3, 4); 
	g1.addEdge(3, 6); 
	g1.addEdge(3, 7); 
	g1.addEdge(4, 6); 
	g1.addEdge(4, 7); 
	g1.addEdge(5, 6); 
	g1.addEdge(5, 8); 
	g1.addEdge(6, 7); 
	g1.addEdge(6, 8); 
	g1.printKCores(k); 

	cout << endl << endl; 

	Graph g2(13); 
	g2.addEdge(0, 1); 
	g2.addEdge(0, 2); 
	g2.addEdge(0, 3); 
	g2.addEdge(1, 4); 
	g2.addEdge(1, 5); 
	g2.addEdge(1, 6); 
	g2.addEdge(2, 7); 
	g2.addEdge(2, 8); 
	g2.addEdge(2, 9); 
	g2.addEdge(3, 10); 
	g2.addEdge(3, 11); 
	g2.addEdge(3, 12); 
	g2.printKCores(k); 

	return 0; 
} 

