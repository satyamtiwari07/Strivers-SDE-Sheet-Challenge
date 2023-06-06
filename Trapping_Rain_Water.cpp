#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    /**
    arr =  3 0 0 2 0 4
    lmax = 3 3 3 3 3 4
    rmax = 4 4 4 4 4 4 

    arr  = 5 1 5
    lmax = 5 5 5
    rmax = 5 5 5

    0 1 2 3 4 5
    n-(x-1)-1 = n-n+1-1
    */

    vector<long>lmax(n,0);
    vector<long>rmax(n,0);

    lmax[0]=arr[0];
    rmax[n-1]=arr[n-1];
    
    for(int x=1;x<n;x++){
        lmax[x]=max(lmax[x-1],arr[x]);
        rmax[n-x-1]=max(rmax[n-x],arr[n-x-1]);
    }

    long ans=0;
    for(int x=1;x<n-1;x++){
        ans+=abs(min(lmax[x],rmax[x])-arr[x]);
    }

    return ans;

}
