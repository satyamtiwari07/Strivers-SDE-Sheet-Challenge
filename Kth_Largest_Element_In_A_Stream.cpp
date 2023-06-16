#include <bits/stdc++.h> 
class Kthlargest {
    priority_queue<int,vector<int>,greater<int>>pq;
public:
    Kthlargest(int k, vector<int> &arr) {
       // Write your code here.
       /**
            5 4 3 9 8 7  k=3;
            3 4 5 7 8 9  ans=7
            pq = 7 8 9
       */
       int val=0;
       for(auto &it:arr){
         if (val < k) {
           pq.push(it);
           val++;
         } else if (it > pq.top()) {
           pq.pop();
           pq.push(it);
         }
       } 
    }

    void add(int num) {
        // Write your code here.
        if(num>pq.top()){
            pq.pop();
            pq.push(num);
        }
    }

    int getKthLargest() {
       // Write your code here.
       return pq.top();
    }

};
