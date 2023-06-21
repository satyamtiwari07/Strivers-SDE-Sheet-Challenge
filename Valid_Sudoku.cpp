bool possible(int num, int matrix[9][9], int r, int c){
    //row check
    for(int z=0; z<9; z++) if(matrix[r][z]==num) return false;
    
    //column check
    for(int z=0; z<9; z++) if(matrix[z][c]==num) return false;

    //check for 3x3 sub-matrices
    int a=(r/3)*3;
    int b=(c/3)*3;
    for(int x=a;x<a+3;x++){
        for(int y=b;y<b+3;y++){
            if(matrix[x][y]==num) return false;
        }
    }

    return true;
}


bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    
    for(int x=0;x<9;x++){
        for(int y=0;y<9;y++){
            if(matrix[x][y]==0){
                for(int z=1;z<=9;z++){
                    if(possible(z,matrix,x,y)){
                        matrix[x][y]=z;
                        if(isItSudoku(matrix)) return true;
                        matrix[x][y]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
