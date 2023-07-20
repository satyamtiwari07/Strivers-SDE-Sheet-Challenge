#include <bits/stdc++.h> 
class Node{
public:
    bool flag = false;
    Node* links[26]; 
    bool contains(char c){
        return links[c - 'a'] != nullptr;
    }
    void put(char c){
        links[c - 'a'] = new Node();
    }
    Node* next(char c){
        return links[c - 'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie{
public:
    Node* root;
    Trie() { root = new Node(); }
    void insert(string str){
        Node*temp=root;
        for(int x=0;x<str.length();x++){
            if(!temp->contains(str[x])){
                temp->put(str[x]);
            }
            temp=temp->next(str[x]);
        }
        temp->setEnd();
    }

    bool search(string str){
        Node*temp=root;
        for(char ch:str){
            temp=temp->next(ch);
            if(!temp->isEnd()) return  false; 
        }
        return true;
    }
};

string completeString(int n, vector<string> &a) {
  // Write your code here.
  Trie t;
  for(auto it:a) t.insert(it);

  string ans="";
  for(int x=0;x<n;x++){
      if(t.search(a[x])){
          if(a[x].length()>ans.length()) ans = a[x];
          else if(a[x].length()==ans.length() && ans>a[x]) ans = a[x];
      }
  }
  if(ans.length()==0) return "None";
  return ans;
}
