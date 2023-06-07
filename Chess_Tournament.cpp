#include <bits/stdc++.h> 

bool possible(int mid, vector<int>postions, int n, int c){
	int cnt=1;
	int curpos=0;
	for(int x=1;x<n;x++){
		if(postions[x]-postions[curpos]>=mid){
			cnt++;
			curpos=x;
		}
		if(cnt>=c) break;
	}
	return cnt>=c;
}

int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
	// monotonic function like -->t t t t t f f f
	sort(positions.begin(),positions.end());

	int lo=0;
	int hi=1e9+5;
	int ans=0;
	while(lo<=hi){
		int mid=hi-(hi-lo)/2;

		if(possible(mid,positions,n,c)){
			ans=mid;
			lo=mid+1;
		}
		else
		  hi=mid-1;
	}
	return ans;
	
}
