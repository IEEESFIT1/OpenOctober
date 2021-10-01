/* C++ Program to find LCA of u and v by reducing the problem to RMQ */
#include<bits/stdc++.h> 
#define V 9			 

int euler[2*V - 1];	
int level[2*V - 1];	 
int firstOccurrence[V+1];  
int ind;				  

struct Node 
{ 
	int key; 
	struct Node *left, *right; 
}; 

Node * newNode(int k) 
{ 
	Node *temp = new Node; 
	temp->key = k; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

int Log2(int x) 
{ 
	int ans = 0 ; 
	while (x>>=1) ans++; 
	return ans ; 
} 

int RMQUtil(int index, int ss, int se, int qs, int qe, int *st) 
{ 
	if (qs <= ss && qe >= se) 
		return st[index]; 

	else if (se < qs || ss > qe) 
		return -1; 

	int mid = (ss + se)/2; 

	int q1 = RMQUtil(2*index+1, ss, mid, qs, qe, st); 
	int q2 = RMQUtil(2*index+2, mid+1, se, qs, qe, st); 

	if (q1==-1) return q2; 

	else if (q2==-1) return q1; 

	return (level[q1] < level[q2]) ? q1 : q2; 
} 

int RMQ(int *st, int n, int qs, int qe) 
{ 
	if (qs < 0 || qe > n-1 || qs > qe) 
	{ 
		printf("Invalid Input"); 
		return -1; 
	} 

	return RMQUtil(0, 0, n-1, qs, qe, st); 
} 

void constructSTUtil(int si, int ss, int se, int arr[], int *st) 
{ 
	if (ss == se)st[si] = ss; 

	else
	{ 
		int mid = (ss + se)/2; 
		constructSTUtil(si*2+1, ss, mid, arr, st); 
		constructSTUtil(si*2+2, mid+1, se, arr, st); 

		if (arr[st[2*si+1]] < arr[st[2*si+2]]) 
			st[si] = st[2*si+1]; 
		else
			st[si] = st[2*si+2]; 
	} 
} 

int *constructST(int arr[], int n) 
{ 
	int x = Log2(n)+1; 
	int max_size = 2*(1<<x) - 1;

	int *st = new int[max_size]; 

	constructSTUtil(0, 0, n-1, arr, st); 
	return st; 
} 

void eulerTour(Node *root, int l) 
{ 
	if (root) 
	{ 
		euler[ind] = root->key;  
		level[ind] = l;		  
		ind++;				
		
		if (firstOccurrence[root->key] == -1) 
			firstOccurrence[root->key] = ind-1; 

		if (root->left) 
		{ 
			eulerTour(root->left, l+1); 
			euler[ind]=root->key; 
			level[ind] = l; 
			ind++; 
		} 

		if (root->right) 
		{ 
			eulerTour(root->right, l+1); 
			euler[ind]=root->key; 
			level[ind] = l; 
			ind++; 
		} 
	} 
} 

int findLCA(Node *root, int u, int v) 
{ 
	memset(firstOccurrence, -1, sizeof(int)*(V+1)); 
	ind = 0; 
	eulerTour(root, 0); 
	int *st = constructST(level, 2*V-1); 
	if (firstOccurrence[u]>firstOccurrence[v]) 
	std::swap(u, v); 
	int qs = firstOccurrence[u]; 
	int qe = firstOccurrence[v]; 
	int index = RMQ(st, 2*V-1, qs, qe); 
	return euler[index]; 
} 

int main() 
{ 
	Node * root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->left = newNode(6); 
	root->right->right = newNode(7); 
	root->left->right->left = newNode(8); 
	root->left->right->right = newNode(9); 

	int u = 4, v = 9; 
	printf("The LCA of node %d and node %d is node %d.\n", 
			u, v, findLCA(root, u, v)); 
	return 0; 
} 

