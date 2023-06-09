#include <bits/stdc++.h> 
void f(int idx,string s,vector<string>&ans){
    if(idx>=s.size()){
        ans.push_back(s);
        return ;
    }

    for(int x=idx;x<s.size();x++){
        swap(s[x],s[idx]);
        f(idx+1,s,ans);
        swap(s[x],s[idx]);
    }
}

vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string>ans;
    f(0,s,ans);
    return ans;
}
