#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
	// Write your code here.
	if(n==1) return "1";
	string str = writeAsYouSpeak(n-1);

	string temp;
	int x=0; 
	while(x<str.length()){
		int count = 1;
		while(x+1<str.length() and str[x]==str[x+1]){
			count++;
			x++;
		}
		temp+=to_string(count);
		temp+=str[x];
		x++;
	}	

	return temp;
}
