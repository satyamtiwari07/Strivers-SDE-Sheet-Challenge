#include <bits/stdc++.h>

struct node{
    struct node*children[26];
    int count;
    int isend;
    node(){
        for(int x=0;x<26;x++) 
           children[x]=NULL;
        count=0;
        isend=0;
    }
};

class Trie{
    struct node* root;
    public:

    Trie(){
        // Write your code here.
        root=new node();
    }

    void insert(string &word){
        // Write your code here.
        struct node*temp=root;
        for(int x=0;x<word.length();x++){
            int t = word[x]-'a';
            if(temp->children[t]==NULL){
                temp->children[t]=new node();
            }
            temp=temp->children[t];
            temp->count++;
        }
        temp->isend+=1;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        struct node*temp=root;
        for(int x=0;x<word.length();x++){
            int t=word[x]-'a';
            if(temp->children[t]==NULL) return 0;
            temp=temp->children[t];
        }
        // if(temp->isend)
        //    return temp->count;
        return temp->isend; 
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        int ans=0;
        struct node*temp=root;
        for(int x=0;x<word.length();x++){
            int t=word[x]-'a';
            if(temp->children[t]==NULL) return 0;
            temp=temp->children[t];
        }
        return temp->count;
    }

    void erase(string &word){
        // Write your code here.
        struct node*temp=root;
        for(int x=0;x<word.length();x++){
            int t=word[x]-'a';
            if(temp->children[t]==NULL) return ;
            temp=temp->children[t];
            temp->count--;
        }
        temp->isend-=1;
    }
};
