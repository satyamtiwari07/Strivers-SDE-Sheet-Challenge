#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int ans=arr[0];
	int cnt=1;
	for(int x=1;x<n;x++){
		if(arr[x]==ans) cnt++;
		else cnt--;

        if (cnt == 0) {
            ans = arr[x];
            cnt = 1;
        }
    }
	
	cnt=0;
	for(int x=0;x<n;x++){
		if(arr[x]==ans) cnt++;
	}

	return cnt > n/2 ? ans : -1;
}
