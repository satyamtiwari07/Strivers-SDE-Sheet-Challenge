#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	unordered_map<int,int>mpp;
	for(int x=0;x<n;x++){
		if(mpp[arr[x]]==0) mpp[arr[x]]++;
		else return arr[x];
	}
	return -1;
}
