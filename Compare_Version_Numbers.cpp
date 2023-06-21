#include <bits/stdc++.h> 
int compareVersions(string a, string b) 
{
    // Write your code here
    string t;
    int n = a.length();
    int m = b.length();
    int x = 0;
    int y = 0;
    while(x<n or y<m){
        while(x<n and a[x]=='0') x++;
        while(y<m and b[y]=='0') y++;

        long long num1=0,num2=0;
        while(x<n and a[x]!='.') num1=num1*10+a[x++]-'0';
        while(y<m and b[y]!='.') num2=num2*10+b[y++]-'0';

        if(num1>num2) return 1;
        else if(num2>num1) return -1;

        x++;
        y++;
    }
    return 0;
}
