#include <bits/stdc++.h> 
bool palindrome(string &s,int i,int j){

    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
void f(int idx,string& s, vector<string>& temp, vector<vector<string>>& ans){

    if(idx>=s.size())
    {
        ans.push_back(temp);
        return;
    }

    string tmp="";
    for(int x=idx;x<s.size();x++){
        tmp+=s[x];
        if(palindrome(s,idx,x)){
            temp.push_back(tmp);
            f(x+1,s,temp,ans);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>>ans;
    vector<string> temp;

    f(0,s,temp,ans);
    return ans;
}
