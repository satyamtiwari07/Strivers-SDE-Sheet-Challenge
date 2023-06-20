#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    stack<int>st;
    int n=price.size();
    vector<int>ans(n,0);

    for(int x=n-1;x>=0;x--){
        while(!st.empty() and price[st.top()]<price[x]){
            ans[st.top()]=st.top()-x;
            st.pop();
        }
        st.push(x);
    }
    while(!st.empty()){
        ans[st.top()]=st.top()+1;
        st.pop();
    }

    return ans;
}
