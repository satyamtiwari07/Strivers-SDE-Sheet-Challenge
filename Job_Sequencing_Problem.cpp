#include <bits/stdc++.h> 
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    /**
        60->5
        50->3
        40->4;
        25->2;
    */

    vector<bool>arr(3001,false);
    //profit,job
    priority_queue<pair<int,int>>pq;
    int n=jobs.size();
    int sum=0;

    for(int x=0;x<n;x++){
      pq.push({jobs[x][1],jobs[x][0]});
    }

    while(!pq.empty()){
        pair<int,int>temp =pq.top();
        pq.pop();
        int profit = temp.first;
        int deadLine = temp.second;

        for(int x=deadLine;x>0;x--){
          if (!arr[x]) {
            arr[x] = true;
            sum += profit;
            break;
          }
        }
    }
    
    return sum;

}
