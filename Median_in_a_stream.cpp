#include<bits/stdc++.h>

vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	
	/**
		16 4 17 10 12 
		maxheap > minheap
		5		  17 
		
		1>.Size of mxheap>minheap
		2>.differece btw size maintain 1
	*/
	
	vector<int>ans;
	priority_queue<int>maxheap;
	priority_queue<int,vector<int>,greater<int>>minheap;
	
	for(int x=0;x<n;x++){
		if(maxheap.size() == 0){
			maxheap.push(arr[x]);
		}
		else if(maxheap.size() > minheap.size()){
			if(maxheap.top()>arr[x]){
				//it wants to go in maxheap
				minheap.push(maxheap.top());
				maxheap.pop();
				maxheap.push(arr[x]);
			}
			else minheap.push(arr[x]);
		}

		//both have same size now
		else{
			if(arr[x]<minheap.top()) maxheap.push(arr[x]);
            else {
                // it wants to go in minheap
                maxheap.push(minheap.top());
				minheap.pop();
				minheap.push(arr[x]);
			}
		}
		
		//median calculate
		if(maxheap.size()>minheap.size()) ans.push_back(maxheap.top());
		else ans.push_back((minheap.top()+maxheap.top())/2);
	}

	return ans;

}
