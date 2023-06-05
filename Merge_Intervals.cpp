#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    sort(intervals.begin(),intervals.end());
    
    int n=intervals.size();
    vector<vector<int>>ans;
    ans.push_back(intervals[0]);

    for(int x=1;x<n ; x++){
        vector<int>t1 = ans.back();
        if(t1[1]>=intervals[x][0]){
            ans.pop_back();
            ans.push_back({t1[0],max(t1[1],intervals[x][1])});
        }
        else ans.push_back(intervals[x]);
    }
    return ans;
}
