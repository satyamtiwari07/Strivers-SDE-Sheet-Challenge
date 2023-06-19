#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here
	
	long long s = (long long)(n*(n+1)*1ll)/2;
	long long s1 = 0ll;

	long long p = ((long long) n * (long long) (n+1) * (long long)(2*n+1)*1ll)/6;
	long long p1 = 0ll;
	
	for(auto &it:arr){
		s1 += (long long)it;
		p1 += (long long)it * (long long)it * 1ll;
	}

	long long  x = ((long long)(s-s1) + (long long)((p-p1)/(s-s1)))/2;

	long long y = (long long)x - (long long)(s-s1);

    return {(int)x,(int)y};
}
