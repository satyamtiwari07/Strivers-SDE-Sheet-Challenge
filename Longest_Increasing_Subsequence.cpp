#include<vector>

int f(int idx,int arr[],int n, vector<int>&dp){
    if(idx>=n) return 0;
    if(dp[idx]!=-1) return dp[idx];

    int ans=1;
    
    for(int x=idx+1;x<n;x++){
        if(arr[x]>arr[idx]){
            ans=max(ans,1+f(x,arr,n,dp));
        }
    }
    return dp[idx]=ans;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    // vector<int>dp(n+1,-1);
    // int ans=0;
    // for(int x=0;x<n;x++){
    //     ans=max(ans,f(x,arr,n,dp));
    // }
    // return ans;

    // vector<int>dp(n+1,1);
    // int ans=1;

    // for(int x=0;x<n;x++){

    //   for (int idx = n - 1; idx >= x; idx--) {
    //     int a = 1;
    //     for(int y=idx+1;y<n;y++){
    //         if(arr[y]>arr[idx]){
    //             a=max(a,1+dp[y]);
    //         }
    //     }

    //     dp[idx]=a;
    //   }

    // int a=1;
    
    // for(int y=0;y<x;y++){
    //     if(arr[y]<arr[x]){
    //         dp[x]=max(dp[x],1+dp[y]);
    //     }
    // }
    // // dp[x]=a;


    //   ans=max(ans,dp[x]);
    // }
    // return ans;

  /**
    using binary search TC -> O(NlogN) SC->O(N)
  */
  vector<int>temp;
  temp.push_back(arr[0]);
  for(int x=1;x<n;x++){
      if(temp.back()<arr[x]){
          temp.push_back(arr[x]);
      }
      else{
          auto it = lower_bound(temp.begin(),temp.end(),arr[x])-temp.begin();
          temp[it]=arr[x];
      }
  }
  return temp.size();

}
