#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int l=0;
    int r=0;
    int n=input.size();
    unordered_map<char,int>mpp;
    int ans=0;
    while(r<n){
        mpp[input[r]]++;
        if(mpp.size()==r-l+1){
            ans=max(ans,r-l+1);
        }
        else{
            while(mpp.size()!=r-l+1){
                mpp[input[l]]--;
                if(mpp[input[l]]==0){
                    mpp.erase(input[l]);
                }
                l++;
            }
            ans=max(ans,r-l+1);
        }
        r++;
    }
    return ans;
}
