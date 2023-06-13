#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.
	priority_queue<int,vector<int>,greater<int>>pq;
	  
	for(int x=0;x<size;x++){
		if(pq.size()<K)
		  pq.push(arr[x]);
		else if(pq.top()<arr[x]){
			pq.pop();
			pq.push(arr[x]);
		}
	}
	return pq.top();
}
