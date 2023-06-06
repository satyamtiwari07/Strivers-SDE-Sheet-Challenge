#include <bits/stdc++.h> 

bool comp(pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b){
    if(a.second.second == b.second.second) return a.first<b.first;
    return a.second.second<b.second.second;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    vector<pair<int,pair<int,int>>>arr;
    int n=start.size(); 
    
    for(int x=0;x<n;x++){
      arr.push_back({x, {start[x], end[x]}});
    }

    sort(arr.begin(),arr.end(),comp);
    vector<int>ans;
    
    int st=arr[0].second.first;
    int ed=arr[0].second.second;
    int idx = arr[0].first;
    ans.push_back(idx+1);

    for (int x = 1; x < n; x++) {
        if(arr[x].second.first>ed){
            st=arr[x].second.first;
            ed=arr[x].second.second;
            idx=arr[x].first;
            ans.push_back(idx+1);
        }
    }

    return ans;
}
