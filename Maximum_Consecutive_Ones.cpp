int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int one=0;
    int zero=0;
    int l=0;
    int r=0;
    int ans=0;
    while(r<n){
        if(arr[r]==1)one++;
        else zero++;
        if(zero<=k){
            ans=max(ans,r-l+1);
        }
        else{
            while(zero>k){
                if(arr[l]==1)one--;
                else zero--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        r++;
    }
    return ans;
}
