#include<bits/stdc++.h>

void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<int>>minh;
    /**
        1>.Always (maxheap size) > (minheap size) and their absolute difference is <=1

        6 2 1 3 7 5

        maxheap    minheap
        1,2,3        5,6,7

    */
    for(int x=0;x<n;x++){
        int val=arr[x];

        if(maxh.size()==0) maxh.push(val);
        
        else if(maxh.size()>minh.size()){
            if(maxh.top()>val){
                minh.push(maxh.top());
                maxh.pop();
                maxh.push(val);
            }
            else minh.push(val);
        }

        else{
            //both are of equal size
            if(val<minh.top()) maxh.push(val);
            else{
                maxh.push(minh.top());
                minh.pop();
                minh.push(val);
            }
        }

        if(maxh.size()==minh.size()) cout<<((maxh.top()+minh.top())/2)<<" ";
        else cout<<maxh.top()<<" ";
    }

}
