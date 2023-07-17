#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int n=arr.size();
    int cnt1=0,cnt2=0;
    int ele1=0,ele2=0;

    for(int x=0;x<n;x++){
        if(cnt1==0 and arr[x]!=ele2){
            cnt1++;
            ele1=arr[x];
        }
        else if(cnt2==0 and arr[x]!=ele1){
            cnt2++;
            ele2=arr[x];
        }
        else if(arr[x]==ele1) cnt1++;
        else if(arr[x]==ele2) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    
    int count1=0,count2=0;
    vector<int>ans;
    // cout<<ele1<<" "<<ele2<<endl;
    for(int x=0;x<n;x++){
        if(arr[x]==ele1) count1++;
        if(arr[x]==ele2) count2++;
    }

    // cout<<count1<<" "<<count2;
    if(count1 > (n/3)) ans.push_back(ele1);
    if(count2 > (n/3)) ans.push_back(ele2);

    return ans;

}
