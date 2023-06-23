int f(int idx,int w,vector<int> &values, vector<int> &weights, int n,vector<vector<int>>&dp){

	if(idx==n) return 0;	

	if(dp[idx][w]!=-1) return dp[idx][w];

	//2 choices are avaiable (i) either pick that weight
	int notPick = f(idx+1,w,values,weights,n,dp);

	//(ii) pick that weight
	int pick=0;
	if(weights[idx]<=w){
		pick = values[idx]+f(idx+1,w-weights[idx],values, weights, n,dp);
	}

	return dp[idx][w]=max(pick,notPick);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	// vector<vector<int>>dp(n+1,vector<int>(w+1,-1));

	// return f(0,w,values, weights, n, dp);
	vector<vector<int>>dp(n+1,vector<int>(w+1,0));
	for(int x=0;x<=w;x++) dp[n][x]=0;

	for(int idx=n-1;idx>=0;idx--){
		for(int W=0;W<=w;W++){
			int notPick = dp[idx+1][W];
			int pick=0;
            if (weights[idx] <= W) {
                pick = values[idx] + dp[idx + 1][W - weights[idx]];
            }
			dp[idx][W] = max(pick, notPick);
        }
    }
	return dp[0][w];
}
