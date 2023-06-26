#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    
    int i=0;
    int j=0;
    int n = nums.size();
    list<int>l;
    vector<int>ans;

    while(j<n){
        while(l.size() and l.back()<nums[j]) l.pop_back();
        l.push_back(nums[j]);

        if(j-i+1<k) j++;
        else{
            ans.push_back(l.front());
            if(l.front()==nums[i]) l.pop_front();
            i++;
            j++;
        }
    }
    return ans;
}
