#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	stack<int>s;
	stack<int>s1;
	int mini;
	public:
		
		// Constructor
		minStack() 
		{ 
			mini=INT_MAX;
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			
                mini = min(mini, num);
                s1.push(mini);
                s.push(num);
            
        }
		
		// Function to remove the top element of the stack.
		int pop()
		{
			if(s.empty())return -1;

			int a=s.top();
			s.pop();
			s1.pop();
			if(!s1.empty()) mini=s1.top();
			else mini=INT_MAX;
			return a;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(s.empty()) return -1;
			int a=s.top();
			return a;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
                int getMin() {
                  // Write your code here.
                  if (s.empty())
                    return -1;
                  return s1.top();
                }
};

/**
can be solved using 
in push mini = 2*cur-mini
in pop 2*mini-cur;
*/
