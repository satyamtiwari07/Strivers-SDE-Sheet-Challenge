#include <bits/stdc++.h>
long long pow(int x,int n,int m){
	if(n==0) return 1;
	
	if(n%2==0){
		long long a = pow(x,n/2,m)%m;
		return (a%m * a%m )%m;
	}
	
	return (x%m * pow(x,n-1,m)%m) % m;
}
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	return pow(x,n,m)%m;
}
