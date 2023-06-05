bool searchMatrix(vector<vector<int>>& mat, int target) {
    int r=mat.size();
    int c=mat[0].size();

    int x=0,y=mat[0].size()-1;

    int lo=0;
    int hi=mat[0].size()-1;

    while(x<r and y>=0){
        if(target>mat[x][y])
           x++;
        else{
            lo=0;
            hi=y;
          while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (mat[x][mid] == target)
                return true;
                if (mat[x][mid] > target)
                hi = mid - 1;
                else
                lo = mid + 1;
          }
          return false;
        }   
    }
    return false;


}
