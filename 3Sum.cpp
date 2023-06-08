#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.(
	vector<vector<int>>ans;

	sort(arr.begin(),arr.end());

	for(int x=0;x<n-2;){
		int rem = K-arr[x];
		int l = x+1;
		int r = n-1;
		while(l<r){
			if(arr[l]+arr[r]==rem){
				ans.push_back({arr[x],arr[l],arr[r]});
				int curPosl = l;
				int curPosR = r;
				while(l<r and arr[curPosl]==arr[l]) l++;
				while(l<r and arr[curPosR]==arr[r]) r--;
				continue;
			}
			else if(l<r and arr[l]+arr[r]<rem) l++;
			else r--;
		}
		int y=x;
		while(x<n-2 and arr[x]==arr[y]) x++;
	}
	return ans;
}
