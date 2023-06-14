#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n=prices.size();
    int profit=0;
    int mini=prices[0];
    for(int x=1;x<n;x++){
        profit=max(profit,prices[x]-mini);
        mini=min(mini,prices[x]);
    }
    return profit;

}
