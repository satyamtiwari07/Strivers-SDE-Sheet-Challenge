#include<bits/stdc++.h> 
 
 void nextSmallestLeft(vector<int>&heights,vector<int>&nsl){
   stack<int>st;
   int n=heights.size();
   
   for(int x=n-1;x>=0;x--){
     while(!st.empty() && heights[st.top()] > heights[x]){
        nsl[st.top()]=x;
        st.pop();
     }
     st.push(x);
   }
 }

 void nextSmallestRight(vector<int>&heights,vector<int>&nsr){

   stack<int>st;
   int n=heights.size();
   
   for(int x=0;x<n;x++){
     while(!st.empty() && heights[st.top()] > heights[x]){
        nsr[st.top()]=x;
        st.pop();
     }
     st.push(x);
   }
 }
 
 
 int largestRectangle(vector < int > & heights) {
   // Write your code here.
   int maxi=0;
   int n = heights.size();
   vector<int>nsr(n,n);
   vector<int>nsl(n,-1);
   
   nextSmallestRight(heights,nsr);
   nextSmallestLeft(heights,nsl);

   for(int x=0;x<n;x++){
     int area=heights[x]*(nsr[x]-nsl[x]-1);
     maxi=max(maxi,area);
   }
   return maxi;
   
 }
