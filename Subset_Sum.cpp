#include <bits/stdc++.h> 
void f(int idx,vector<int>&num,int sum,vector<int>&ans){
    if(idx>=num.size()){
        ans.push_back(sum);
        return;
    }
    //2-choices pick and not pick
    
    //(i) pick
    sum+=num[idx];
    f(idx+1,num,sum,ans);
    
    //backtracking step
    sum-=num[idx];
    
    //(ii) not pick;
    f(idx+1,num,sum,ans);

}
vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int>ans;
    int sum=0;
    f(0,num,sum,ans);
    sort(ans.begin(),ans.end());
    return ans;
}
