#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

						// sum,indices
        // max-heap stores {sum,{x,y}}
    priority_queue<pair<int,pair<int,int>>>pq;

	// used to se whether this {x,y} are present or not
	set<pair<int,int>>s; 

    pq.push({a[n-1]+b[n-1], {n-1,n-1}});
    s.insert({n-1,n-1});

	vector<int>ans;
	for(int x = 0; x < k; x++){
		auto it =pq.top();
		pq.pop();

		ans.push_back(it.first);

		pair<int,int>temp1 = it.second;
		int nx=temp1.first-1;
		int ny=temp1.second;

        if(!s.count({nx,ny})){
          pq.push({a[nx] + b[ny], {nx,ny}});
          s.insert({nx,ny});
        }

		nx=temp1.first;
		ny=temp1.second-1;

		if(!s.count({nx,ny})){
          pq.push({a[nx] + b[ny], {nx,ny}});
          s.insert({nx,ny});
        }
    }
	return ans;
}
