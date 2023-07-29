#include<bits/stdc++.h>
void f(int ind,vector<int>& arr,set<vector<int>>& ans,vector<int>& path,int target){

	if(target==0){
			ans.insert(path);
			return;
	}
	if(ind>=arr.size()){
		return;
	}
	for(int i=ind;i<arr.size();i++){
		if(i!=ind && arr[i]==arr[i-1]) continue;
		if(arr[i]>target) continue;
		path.push_back(arr[i]);
		f(i+1,arr,ans,path,target-arr[i]);
		path.pop_back();
		
	}
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	// Write your code here.
	sort(arr.begin(),arr.end());
	vector<vector<int>> res;
	set<vector<int>> ans;
	vector<int> path;
	f(0,arr,ans,path,target);
	for(auto x:ans){
		res.push_back(x);
	}
	sort(res.begin(),res.end());
	return res;
}
