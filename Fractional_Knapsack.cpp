#include <bits/stdc++.h> 
bool comp(pair<int,int>&a,pair<int,int>&b){
    
    return (a.second*1.0/a.first)>(b.second*1.0/b.first);
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),comp);
    double ans=0;
    // for(auto it:items) cout<<it.first<<" "<<it.second<<endl;
    for(int x=0;x<n;x++){
        if(items[x].first<w){
            ans=ans+ (double)items[x].second;
            w-=items[x].first;
        }
        else{
            ans = ans + ((double)(items[x].second*1.0/items[x].first)*w*1.0);
            break;
        }
    }
    return ans;
}
