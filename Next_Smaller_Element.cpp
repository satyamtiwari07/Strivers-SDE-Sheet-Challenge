#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int>ans(n,-1);
    stack<int>st;
    for(int x=0;x<n;x++){
        while(!st.empty() and arr[st.top()] > arr[x]){
            ans[st.top()]=arr[x];
            st.pop();
        }
        st.push(x);
    }
    return ans;
}
