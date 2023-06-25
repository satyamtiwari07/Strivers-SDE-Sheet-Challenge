#include<bits/stdc++.h>

string longestCommonPrefix(vector<string> &all, int n)
{
    // Write your code here
        
        sort(all.begin(),all.end());
        
        string str1=all[0];
        string str2=all[all.size()-1];
        
        string ans="";
        for(int x=0;x<min(str1.size(),str2.size());x++){
            if(str1[x]!=str2[x])
               break;
            ans+=str1[x];
        }  
        return ans;
}


