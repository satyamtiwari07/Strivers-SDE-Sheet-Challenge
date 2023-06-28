#include<vector>

int f(int idx1,int idx2, string&s, string &t){
	if(idx1>=s.size() || idx2>=t.size()) return 0;

	if(s[idx1]==t[idx2]) return 1+f(idx1+1,idx2+1,s,t);

	return max( f(idx1+1,idx2,s,t), f(idx1,idx2+1,s,t));
}
int lcs(string s, string t)
{
	//Write your code here
	// for(int )
	// return f(0,0,s,t);
	int n=s.size();
	int m=t.size();
	vector<vector<int>>dp(n+1,vector<int>(m+1,0));

	for(int x=0;x<=n;x++) dp[x][m]=0;
	for(int x=0;x<=m;x++) dp[n][x]=0;

	
	for(int idx1=n-1; idx1>=0;idx1--){
		for(int idx2=m-1;idx2>=0;idx2--){
			if(s[idx1]==t[idx2]) dp[idx1][idx2] = 1+dp[idx1+1][idx2+1];
			else dp[idx1][idx2] = max( dp[idx1+1][idx2], dp[idx1][idx2+1]);
		}
	}

	return dp[0][0];

}
