#include <bits/stdc++.h> 

class heap{
  private:
    vector<int>arr;
    int size;
    int capacity;

  public:
    heap(int capacity){
      arr.resize(capacity);
      size=0;
      this->capacity=capacity;
    }

    int parent(int idx){ return (idx-1)/2; }
    
    int left(int idx){ return 2*idx+1; }
    
    int right(int idx){ return 2*idx+2; }


  void insert(int val){
    if(size==capacity) return ;

    int idx=size;
    size++;
    arr[idx]=val;

    while(idx>0 and arr[parent(idx)]>arr[idx]){
      swap(arr[parent(idx)],arr[idx]);
      idx=parent(idx);
    }

  } 

  void heapify(int idx){

    if(idx>=size) return ;
    // if(size==1) return ;

    int smallIndex = idx;
    int leftIndex = left(idx);
    int rightIndex = right(idx);

    if(leftIndex<size and arr[leftIndex]<arr[smallIndex])
      smallIndex=leftIndex;

    if(rightIndex<size and arr[rightIndex]<arr[smallIndex])
      smallIndex=rightIndex;

    if(smallIndex!=idx){
      swap(arr[idx],arr[smallIndex]);
      heapify(smallIndex);
    }
    
  } 

  int deleteNode(){
    if(size==1){
      size--;
      return arr[0];

    }
    int a = arr[0];
    swap(arr[0],arr[size-1]);
    size--;
    heapify(0);
    return a;
  }

};


vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    heap h(n);
    vector<int>ans;
    for(auto &it:q){
        if(it.size()==2){
            int a=it[0];
            int b=it[1];
            h.insert(b);
        }
        else{
            ans.push_back(h.deleteNode());
        }
    }
    return ans;

}
