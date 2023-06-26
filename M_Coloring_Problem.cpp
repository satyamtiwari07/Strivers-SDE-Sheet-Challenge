vector<int>color;

bool isvalid(int node, int col, vector<vector<int>>&mat){
    //checking if it adjacent has this color or not 
    for(int x=0;x<mat.size();x++){
      if(mat[node][x]==1 and color[x]==col) return false;
    }
    return true;
}

bool coloring(vector<vector<int>> &mat, int m, int node){
  if(node>=mat.size()) return 1;

  for(int x=1;x<=m;x++){
    //if its valid to color this node with x color 
    if(isvalid(node,x,mat)){
        color[node]=x;
        // call for next n+1 node
        if(coloring(mat,m,node+1)) return true;
        //backtracking
        color[node]=0;
    
    }
  }
  return 0;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here

    int n=mat.size();
    
    //all are having zero color
    color.resize(n+1,0);
    
    if(coloring(mat,m,0))return "YES";
    return "NO";
}
