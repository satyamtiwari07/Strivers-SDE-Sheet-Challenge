#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	unordered_set<int>rowChange;
	unordered_set<int>columnChange;

   int r=matrix.size();
   int c=matrix[0].size();

	for(int x=0;x<matrix.size();x++){
		for(int y=0;y<matrix[0].size();y++){
			if(matrix[x][y]==0){
				rowChange.insert(x);
				columnChange.insert(y);
			}
		}
	}

	//each column change
	for(auto &it:rowChange){
		for(int y=0;y<c;y++){
			matrix[it][y]=0;
		}
	}
    

	//each row change
	for(auto &it:columnChange){
		for(int y=0;y<r;y++){
			matrix[y][it]=0;
		}
	}
  
//this solution can be further optimized 
//this is using t.c=O(r*c) s.c=o(r+c) unordered_map
//optimized approach
//1>.check each 1 row and column and mark them using variable
//2>.iterate through row 1 and column 1 and if there is matrix[r][c]==0 we can do one thing matrix[r][0]=0 and matrix[0][c]=0 
//3>.iterate through whole matrix if there is any 0 make the row and column equal to zero
//4>.check the first cnondition if first row or column maked as true by variables 
//5>.iterate in that row(first) or column(first) and mark all the elements of that row or column as 0;
//6> T.C->O(R*C) AND S.C->O(1);
}


