#include <bits/stdc++.h> 
int distinctSubstring(string &word) {
    //  Write your code here.
    unordered_set<string>s;
    for(int x=0;x<word.length();x++){
        for(int y=1;y<=word.length()-x;y++){
            string t = word.substr(x,y);
            s.insert(t);
     }
    }
    return s.size();
}
