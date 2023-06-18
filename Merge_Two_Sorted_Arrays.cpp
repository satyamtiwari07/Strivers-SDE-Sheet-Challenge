#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
  
	int k= m+n-1;
	int x=m-1;
	int y=n-1;
	while(x>=0 and y>=0){
		if(arr1[x]>=arr2[y]){
			arr1[k--]=arr1[x];
			x--;
		}
		else{
			arr1[k--]=arr2[y];
			y--;
		}
	}
	
	while(x>=0) arr1[k--]=arr1[x--];
	while(y>=0) arr1[k--]=arr2[y--];
	
	return arr1;
}
