int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    vector<pair<int,char>>temp;
    for(int x=0;x<n;x++){
      temp.push_back({at[x], 'A'});
      temp.push_back({dt[x], 'D'});
    }
    sort(temp.begin(),temp.end());
    int cnt=0;
    int maxi=-1;
    for(int x=0;x<n;x++){
        if(temp[x].second=='A')
         cnt++;
         else cnt--;
         maxi=max(maxi,cnt);
    }
    return maxi; 
}
