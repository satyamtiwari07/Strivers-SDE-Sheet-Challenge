#include <bits/stdc++.h> 

bool ispossible(long long mid,int m, vector<int>&time){
	long long count=1;
	long long sum=0;
	int n=time.size();

	for(int x=0;x<n;x++){
		if(time[x]>mid) return false; 
		if(sum + time[x] <= mid){
			sum += time[x];
		}
		else{
			sum = time[x];
			count++;
		}
	}
	
	return count<=m;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
	//T T T T T T F F F F F F
	long long lo=0;
	long long hi=1e18;
	long long ans=-1;
	while(hi>=lo){
		long long mid = (lo+hi)/2;
		// cout<<lo<<" "<<mid<<" "<<hi<<endl;
		if(ispossible(mid,n,time)){
			ans=mid;
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
	return ans;
}
