#include <bits/stdc++.h> 
class Queue {
    vector<int>arr;
    int f,rear;
public:
    Queue() {
        // Implement the Constructor
        arr.resize(1e4,0);
        f=-1,rear=-1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return f==-1 and rear==-1; 
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(f==-1)
            f++;
        rear++;
        arr[rear]=data;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(f==-1) return -1;
        int val = arr[f];
        if(f==rear){
            f=rear=-1;
        }
        else f++;
        return val;
    }

    int front() {
        // Implement the front() function
        if(f==-1) return -1;
        return arr[f];
    }
};
