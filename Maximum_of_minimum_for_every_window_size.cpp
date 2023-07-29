#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    vector<int> nse(n), pse(n), res(n, INT_MIN);
    for(int i=0; i<n; i++){
        pse[i] = i;
        nse[i] = n-i-1;
    }

    stack<int> st;
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && a[st.top()]>a[i])
        {
            nse[st.top()] = i-st.top()-1;
            st.pop();
        }
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && a[st.top()]>a[i])
        {
            pse[st.top()] = st.top()-i-1;
            st.pop();
        }
        st.push(i);
    }

    for(int i=0; i<n; i++)
    {
        int d = nse[i]+pse[i];
        res[d] = max(res[d], a[i]);
    }

    for(int i=n-2; i>=0; i--)
    if (res[i]<res[i+1]) res[i] = res[i+1];

    return res;
}
