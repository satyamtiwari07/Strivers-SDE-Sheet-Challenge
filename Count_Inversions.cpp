#include <bits/stdc++.h>
long long ans=0;
void merge(int l, int mid, int r, long long *arr){

  int n1 = mid-l+1;
  int n2 = r-mid;
  vector<long long> arr1(n1);
  vector<long long> arr2(n2);

  for(int x=0;x<n1;x++) arr1[x] = arr[l+x];
  for(int x=0;x<n2;x++) arr2[x] = arr[mid+x+1];

  int x=0, y=0;
  int val=l; 
  while(x<n1 and y<n2){
      if(arr1[x]<=arr2[y]){
        arr[val++] = arr1[x++];
      }
      else{
          ans+=(n1-x);
          arr[val++] = arr2[y++];
      }
  }
  while(x<n1)arr[val++] = arr1[x++];
  while(y<n2)arr[val++] = arr2[y++];
  
}
void mergesort(int l,int r,long long *arr){
  
  if(l>=r) return ;

  int mid = (l + r)/2;
  mergesort(l,mid,arr);
  mergesort(mid+1,r,arr);
  merge(l,mid,r,arr);
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    ans=0;
    mergesort(0,n-1,arr);
    return ans;
}
