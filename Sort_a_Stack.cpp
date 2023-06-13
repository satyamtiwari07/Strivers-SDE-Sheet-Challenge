#include <bits/stdc++.h>

void place(stack<int>&st,int val){
	if(st.empty() || st.top()<val){
		st.push(val);
		return ;
	}
	int a=st.top();
	st.pop();
	place(st,val);
	st.push(a);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()) return;
	int a = stack.top();
	stack.pop();
	sortStack(stack);
	place(stack,a);

}
