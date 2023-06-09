#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int> arr = {1000,500,100,50,20,10,5,2,1};
    int ans=0;
    for(int x=0;x<arr.size();x++){
        if(amount>=arr[x]){
            ans+=amount/arr[x];
            amount = amount%arr[x];
        }
    }
    return ans;
}
