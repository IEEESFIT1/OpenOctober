#include<bits/stdc++.h>
using namespace std;

bool check_cycle_DFS(int s, vector<int> adj[], vector<int> &vis, vector<int> &dfsvis){
	//mark visited in both
	vis[s]=1;
	dfsvis[s]=1;
	
	//for all neighbours of 's'
	for(auto it: adj[s]){
		//if node not visited
		if(!vis[it]){
			if(check_cycle_DFS(it,adj,vis,dfsvis)){
				return true;
			}
		}
		else if(vis[it]==1 && dfsvis[it]==1){
			return true;
		}
	}
	//no neighbours present so again mark as unvisited
	dfsvis[s]=0;  
	return false;
}

bool isCyclic(int n, vector<int> adj[]){
	//two vectors for hashing
	vector<int> vis(n,0);
	vector<int> dfsvis(n,0);  //status of node in every recursion branch of 'check_cycle_DFS'
	for(int i=0;i<n;i++){
		if(!vis[i]){
			if(check_cycle_DFS(i,adj,vis,dfsvis)){
				return true;
			}
		}
	}
	return false;
}

int main(){
	//graph input
	//no. of nodes and no. of edges
	int m,n; 
	cin>>m>>n;
	vector<int> adj[m+1];
	
	for(int i=0;i<n;i++){
		//two nodes
		int u,v; 
		cin>>u>>v; 
		adj[u].push_back(v); //u has a directed edge towards v
	}
	
	if(isCyclic(n,adj)){
		cout<<"Cycle is present in the graph!!"<<endl;
	}
	else{
		cout<<"Cycle is not present in the graph!!"<<endl;
	}
	return 0;
}
