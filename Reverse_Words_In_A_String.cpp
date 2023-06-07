#include<bits/stdc++.h>

string reverseString(string &str){
	// Write your code here.	
	int n=str.length();
	int x=0;
	string ans="";
	stack<string>st;
	string temp="";

	while(x<n){
		while(x<n && str[x]==' ') x++;
		while(x<n && str[x]!=' ') temp+=str[x++];
		if(temp!="")
			st.push(temp);
		temp="";
	}
	// if(temp.size())ans+=temp;

	while(!st.empty()){
		ans+=st.top();
		ans+=' ';
		st.pop();
	}
	return ans;
}
