#include <bits/stdc++.h>
int f(int idx, vector<int> &track, int n,vector<int>&dp){
	if(idx>=n) return 0;
	
	if(dp[idx]!=-1) return dp[idx];
	
	int ans=track[idx];
	// track[idx];
	int sum=track[idx];

	for(int x=idx+1;x<n;x++){
		if(track[x]>track[idx]){
			ans=max(ans,sum+f(x,track,n,dp));
		}
	}
	return dp[idx]=ans;
} 

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	// Write your code here
	int ans = 0;
	vector<int>dp(n+1,-1);
	for(int x = 0; x < n; x++){
		// cout<<f(x,rack,n)<<" ";
		ans=max(ans,f(x,rack,n,dp));
	}
	return ans;

}
