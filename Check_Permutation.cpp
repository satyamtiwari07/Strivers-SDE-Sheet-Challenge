#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
   unordered_map<char,int>mpp1;
   for(auto &it:str1) mpp1[it]++;
   for(auto &it:str2) mpp1[it]--;
   for(auto &it:mpp1) if(it.second) return false;
   return true;
}
