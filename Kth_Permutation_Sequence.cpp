string kthPermutation(int n, int k) {
    // Write your code here.
    int facto=1;
    vector<int>num;
    for(int x=1;x<n;x++){
        facto*=x;
        num.push_back(x);
    }
    num.push_back(n);

    k=k-1;
    string ans="";

    while(true){
        ans+=to_string(num[k/facto]);
        num.erase(num.begin()+k/facto);
        if(num.size()==0) break;

        k=k%facto;
        facto/=num.size();
    }

    return ans;

}
