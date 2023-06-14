void dfs(int x,int y,int n,int m,int initialColor,int newColor,vector<vector<int>> &images){
  if(x<0 || y<0 || x>=n || y>=m || images[x][y]!=initialColor) return ;

  images[x][y] = newColor;
  dfs(x+1,y,n,m,initialColor,newColor,images);
  dfs(x-1,y,n,m,initialColor,newColor,images);
  dfs(x,y+1,n,m,initialColor,newColor,images);
  dfs(x,y-1,n,m,initialColor,newColor,images);
  
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    int initialColor=image[x][y];
    int n = image.size();
    int m = image[0].size();
    if(initialColor!=newColor)
      dfs(x,y,n,m,initialColor,newColor,image);
    return image;
}
