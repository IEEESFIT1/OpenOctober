#include<bits/stdc++.h>
using namespace std;

bool isSafe(int n, int row, int col, vector<int> &left_rowHash, vector<int> &bottom_leftHash, vector<int> &top_leftHash){
	//checking if Queen was placed before
	if(left_rowHash[row]==1 || bottom_leftHash[row+col]==1 || top_leftHash[n-1 + row-col]==1){
		return false;
	}
	return true;
}

bool NQueens(int col, int n, vector< vector<int> > &matrix, vector<int> &left_rowHash, vector<int> &bottom_leftHash, vector<int> &top_leftHash){
	//if 'col' exceeds the number of column on the board
	if(col==n){
		//printing the placement of Queens on the board
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}
	
	//checking placement of Queen in each 'row' of a column
	for(int row=0;row<n;row++){
		
		//if the above placement of queen is safe
		if(isSafe(n, row, col, left_rowHash, bottom_leftHash, top_leftHash)){
			//assuming the Queen's position
			matrix[row][col]=1;  
			
			//mark hashes
			left_rowHash[row]=1;
			bottom_leftHash[row+col]=1;
			top_leftHash[n-1 + row-col]=1;
			
			//checking if further Queen's placement is possible
			if(NQueens(col+1, n, matrix, left_rowHash, bottom_leftHash, top_leftHash)){
				return true;
			}
			
			//backtracking
			matrix[row][col]=0;   //the assumed position of queen is wrong
			
			//unmarking the hashes
			left_rowHash[row]=0;
			bottom_leftHash[row+col]=0;
			top_leftHash[n-1 + row-col]=0;
		}
		
	}
	
	return false;
}

int main(){
	int n;
	cin>>n;
	vector< vector<int> > matrix(n,vector<int>(n,0));  //main matrix (chess board)
	
	//hashes for O(1) complexity
	vector<int> left_rowHash(n,0);
	vector<int> top_leftHash(n,0);
	vector<int> bottom_leftHash(n,0);
	
	NQueens(0, n ,matrix, left_rowHash, bottom_leftHash, top_leftHash);
	
	return 0;
}
