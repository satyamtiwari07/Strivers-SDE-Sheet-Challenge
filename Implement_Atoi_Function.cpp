#include <bits/stdc++.h> 
int atoi(string str) {
    // Write your code here.
    int flag=0;
    int a=0;
    for(auto &it:str){
        if(it=='-') flag++;
        else if(it>='0' and it<='9'){
            a=a*10+(it-'0');
        }
    }
    if(flag==1) return -a;
    return a;
}
