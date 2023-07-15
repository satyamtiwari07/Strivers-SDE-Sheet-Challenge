int f(int idx,int rem,vector<int>&price, vector<vector<int>>&dp){

	if(idx>=price.size() || rem==0) return 0;

	if(dp[idx][rem]!=-1) return dp[idx][rem];
	
	int notPick = f(idx+1,rem,price,dp);
	
	int pick=0;

	if(rem-idx-1>=0){
		pick = price[idx]+f(idx,rem-idx-1,price,dp);
	}

	return dp[idx][rem]=max(pick,notPick);
}


int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>>dp(n+1,vector<int>(n+1,0));
	// return f(0,n,price,dp);

	//base case
	for(int x=0;x<=n;x++) dp[n][x]=0;
	for(int x=0;x<=n;x++) dp[x][0]=0;

	for(int idx=n-1 ; idx>=0 ; idx--){
		
		for(int rem=0 ; rem<=n ; rem++){
		
			int notPick = dp[idx+1][rem];
	
			int pick=0;

			if(rem-idx-1>=0){
				pick = price[idx]+dp[idx][rem-idx-1];
			}
		
			dp[idx][rem]=max(pick,notPick);
		}
	}


	return dp[0][n];
}
