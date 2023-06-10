#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    set<int>s(arr.begin(),arr.end());
    int a=*s.begin();
    int ans=1;
    int maxi=1;
    for(auto &it:s){
        if(it==a)continue;
        else if(it-a==1){
            ans++;
        }
        else ans=1;
        a=it;
        maxi=max(maxi,ans);
    }
    return maxi;
}
