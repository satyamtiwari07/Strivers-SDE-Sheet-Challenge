#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    
    // Write your code here
    
    stack<int>st;
    vector<int>ans(n,-1);

    for(int x=0;x<n;x++){
        while(!st.empty() and arr[st.top()] < arr[x]){
            ans[st.top()]=arr[x];
            st.pop();
        }
        st.push(x);
    }

    return ans;

}
