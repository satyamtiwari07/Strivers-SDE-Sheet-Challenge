#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    sort(arr.begin(),arr.end());
    for(int x=0 ; x<n-3 ; x++){
        for(int y=x+1; y<n-2 ;y++){

            int rem = target-arr[x]-arr[y];
            int lo=y+1;
            int hi=n-1;
            
            while(hi>=lo){
                if(arr[hi]+arr[lo]==rem) return "Yes";
                if(arr[hi]+arr[lo]>rem) hi--;
                else lo++;
            }
        }
    }
    return "No";
}
