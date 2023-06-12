#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    map<int,int>mpp;
    for(auto &it:arr)mpp[it]++;

    vector<pair<int,int>>temp;
    for(auto &it:mpp){
        temp.push_back({it.second,it.first});
    }
    
    sort(temp.rbegin(),temp.rend());

    vector<int>ans;
    for(int x=0;x<k;x++){
        ans.push_back(temp[x].second);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
/**
this can be futher solved with the help of heap(min)
which reduce the futher time complexity 
*/
