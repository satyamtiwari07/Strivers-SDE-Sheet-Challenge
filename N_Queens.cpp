bool possible(int r,int c,int n,vector<vector<int>>&temp){

    //check for row
    for(int x=0;x<c;x++){
        if(temp[r][x]==1) return false;
    }

    //check diagonal-upper
    int x=r;
    int y=c;
    while(--x>=0 and --y>=0){
        if(temp[x][y]==1)
           return false;
    }
    x=r;
    y=c;
    while(++x<n and --y>=0){
        if(temp[x][y]==1) return false;
    }

    return true;

}


void f(int col,int n,vector<vector<int>>&temp,vector<vector<int>>&ans){
    if(col>=n){
        //answer exits
        vector<int>t;
        for(auto &it:temp) for(int &x:it) t.push_back(x);
        ans.push_back(t);
        return;
    }

    //placing queen in each row
    for(int x=0;x<n;x++){
        if(temp[x][col]==0){
            if(possible(x,col,n,temp)){
                temp[x][col]=1;
                f(col+1,n,temp,ans);
                temp[x][col]=0;
            }
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    /**
    0 0 1 0 
    1 0 0 0 
    0 0 0 1 
    0 1 0 0

    0 1 0 0 
    0 0 0 1 
    1 0 0 0 
    0 0 1 0 
    */

    vector<vector<int>>ans;
    vector<vector<int>>temp(n,vector<int>(n,0));
    f(0,n,temp,ans);
    return ans;
}
