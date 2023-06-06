#include <bits/stdc++.h> 
// Stack class.
class Stack {
    vector<int>arr;
    int t;
public:
    
    Stack(int capacity) {
        // Write your code here.
        arr.resize(capacity,0);
        t=-1;
    }

    void push(int num) {
        // Write your code here.
        if (t != arr.size()) {
          t++;
          arr[t] = num;
        }
    }

    int pop() {
        // Write your code here.
        if(t==-1) return -1;
        int val=arr[t];
        t--;
        return val;
    }
    
    int top() {
        // Write your code here.
        if(t==-1) return -1;
        return arr[t];
    }
    
    int isEmpty() {
        // Write your code here.
        return t==-1;
    }
    
    int isFull() {
        // Write your code here.
        return t==arr.size();
    }
    
};
