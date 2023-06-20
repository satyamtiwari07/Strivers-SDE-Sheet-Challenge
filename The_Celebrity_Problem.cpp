#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
	 stack<int>s;
	 for(int x=0;x<n;x++){
		 s.push(x);
	 }

	 while(s.size()>1){
		 int a=s.top();
		 s.pop();
		 int b=s.top();
		 s.pop();

		 if(knows(a,b)){
			 s.push(b);
		 }
		 else{
			 s.push(a);
		 }
	 }

	 int a=s.top();
	 int cntc=0;
	 int cntp=0;
	 for(int x=0;x<n;x++){
		 if(knows(a,x)) cntc++;
		 if(knows(x,a)) cntp++;
	 }
	 if(cntc==0 and cntp==n-1) return a;
	 return -1;

}
