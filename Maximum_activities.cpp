#include<bits/stdc++.h>

bool comp(pair<int,int>&a,pair<int,int>&b){
    return a.second<b.second;
}
int maximumActivities(vector<int> &start, vector<int> &end) {
    // Write your code here.
    vector<pair<int,int>>arr;
    int n=start.size();

    for(int x=0;x<n;x++){
      arr.push_back({start[x],end[x]});
    }
    
    sort(arr.begin(),arr.end(),comp);
    
    int ans=1;
    int ed=arr[0].second;
    
    for(int x=1;x<n;x++){
        if(arr[x].first>=ed){
            ans++;
            ed=arr[x].second;
        }
    }
    return ans;

}
