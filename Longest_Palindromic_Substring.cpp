string longestPalinSubstring(string str)
{
    // Write your code here.
    int s=0;
    int e=1;
    int n=str.length();

    for(int x=1;x<n;x++){
        //even window 
        int l=x-1;
        int r=x;
        while(l>=0 and r<n and str[l]==str[r]){
            if(r-l+1>e){
                s=l;
                e=r-l+1;
            }
            l--;
            r++;
        }

        //odd window
        l=x-1;
        r=x+1;
        while(l>=0 and r<n and str[l]==str[r]){
            if(r-l+1>e){
                s=l;
                e=r-l+1;
            }
            l--;
            r++;
        }
    }

    string ans="";
    // cout<<s<<" "<<e;
    for(int x=s;x<s+e;x++){
        ans+=str[x];
    }
    return ans;

}
