#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	// Write your code here
	int prod=1;
	int ans=INT_MIN;

	for(int x=0;x<n;x++){
		prod*= arr[x];
		ans=max(ans,prod);
		if(prod==0) prod=1;
	}
	
	prod=1;
	for(int x=n-1;x>=0;x--){
		prod*=arr[x];
		ans=max(ans,prod);
		if(prod==0) prod=1;
	}

	return ans;
}
