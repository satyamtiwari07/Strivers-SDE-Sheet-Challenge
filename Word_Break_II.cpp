#include <bits/stdc++.h>
void f(int idx,string &s,string &temp,vector<string>&ans,unordered_map<string,bool>&mpp){
    if(idx>=s.size()){
        ans.push_back(temp);
        return ;
    }

    string t="";
    for(int x=idx;x<s.size();x++){
        t+=s[x];
        if(mpp.count(t)){
            int n=temp.size();
            temp+=t+" ";
            f(x+1,s,temp,ans,mpp);
            temp.erase(n);
        }
    }
} 
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    unordered_map<string,bool>mpp;
    for(auto it:dictionary) mpp[it]++;
    vector<string>ans;
    string temp;
    f(0,s,temp,ans,mpp);
    return ans;

}
