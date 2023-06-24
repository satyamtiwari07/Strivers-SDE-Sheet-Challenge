#include <bits/stdc++.h> 
int ans=0;
void merge(int l, int mid, int r, vector<int>&arr){
	int n1=mid-l+1;
	int n2= r-mid;
	vector<long long> arr1(n1);
  	vector<long long> arr2(n2);
	int x=0;
	int y=0;

	for(int x=0;x<n1;x++) arr1[x] = arr[x+l];
	for(int y=0;y<n2;y++) arr2[y] = arr[mid+1+y];

	int idx=l;
	x=0,y=0;

	while(x<n1 and y<n2){
		if(arr1[x] <= arr2[y]) arr[idx++] = arr1[x++];
		else arr[idx++] = arr2[y++];
	}

	while(x<n1) arr[idx++] = arr1[x++];
	while(y<n2) arr[idx++] = arr2[y++];
}
 

void countPairs(int l, int mid, int r, vector<int>&arr){
	int left=l;
	int right=mid+1;
	// int ans=0;
	while(left<=mid){
		while(right<=r and arr[left]>2*arr[right]) right++;
		ans+=(right-(mid+1));
		left++;
	}
}

void mergesort(int l,int r,vector<int>&arr){
  
  if(l>=r) return ;

  int mid = (l + r)/2;
  mergesort(l,mid,arr);
  mergesort(mid+1,r,arr);
  countPairs(l,mid,r,arr);
  merge(l,mid,r,arr);
}

int reversePairs(vector<int> &arr, int n){
	// Write your code here.
	ans=0;
	mergesort(0,n-1,arr);
	return ans;

}
