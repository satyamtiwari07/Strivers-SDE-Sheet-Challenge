#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int count=0;
    
    int firstRow=0;
    int lastRow=n-1;
    int firstCol=0;
    int lastCol=m-1;

    while(count<n*m){
        
        if(firstRow+1>lastRow || firstCol+1>lastCol) break;

        int prev = mat[firstRow+1][firstCol];
        int cur=0;
        
        for(int x=firstCol; x<=lastCol && count<n*m;x++){
            cur=mat[firstRow][x];
            mat[firstRow][x]=prev;
            prev=cur;
            count++;
        }
        firstRow++;

        for(int x=firstRow; x<=lastRow && count<n*m; x++){
            cur=mat[x][lastCol];
            mat[x][lastCol]=prev;
            prev=cur;
            count++;
        }
        lastCol--;
        
        for(int x=lastCol; x>=firstCol && count<n*m; x--){
            cur=mat[lastRow][x];
            mat[lastRow][x]=prev;
            prev=cur;
            count++;
        }
        lastRow--;

        for(int x=lastRow; x>=firstRow && count<n*m; x--){
            cur=mat[x][firstCol];
            mat[x][firstCol]=prev;
            prev=cur;
            count++;
        }
        firstCol++;
    }

}
