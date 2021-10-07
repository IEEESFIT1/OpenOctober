// C++ Program to check whether a graph is bipartite or not
#include<bits/stdc++.h>
using namespace std;

int is_bipartite= 1;

// BFS function
void bfs(int node, vector<int>& color, vector<int> adj[]){
    queue<int> q;
    q.push(node);
    color[node]=0;

    while(!q.empty()){
        auto top= q.front(); q.pop();
        // For all nodes connected to the current node
        for(auto el: adj[top]){
            // If the node hasn't been visited, color it 
            // as the opposite of the current node's color
            if(color[el]==-1){
                color[el]= color[top]^1;
                q.push(el);
            }
            // otherwise check if the colors of the two nodes
            // are different. If not different, the graph cannot be bipartite
            else{
                is_bipartite &= (color[el]!=color[top]);
            }
        }
    }
}

int main(){
    // Input: 
    // n (Number of nodes)
    // m (Number of edges)
    int n,m; cin>>n>>m;
    vector<int> adj[n+1];

    // Input the edges
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Color of the nodes
    // -1 implies that the node hasn't been visited yet
    vector<int> color(n+1,-1);

    // Apply BFS on all nodes and color them
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            bfs(i,color,adj);
        }
    }

    // If the graph is bipartite, output YES
    if(is_bipartite) cout<<"YES";
    else cout<<"NO";
}
