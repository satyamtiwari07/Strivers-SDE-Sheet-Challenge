double multiply(double mid,int n){
  double mul=1;
  while(n--){
    mul*=(long long)mid;
  }
  return mul;
}

int NthRoot(int n, int m) {
  // Write your code here.
  int lo=1;
  int hi=m;

  while(hi>=lo){
    double mid = (lo+hi)/2;
    double a = multiply(mid, n);
    if(a==m ) return mid; 
    else if(a<m)  lo=mid+1;
    else hi=mid-1;
  }
  return -1;
}
