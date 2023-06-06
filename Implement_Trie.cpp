/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
 
struct node{
    bool isend;
    node *children[26];
    
    node(){
        for(int x=0;x<26;x++){
            children[x]=NULL;
        }
        isend=false;
    }
};

// struct node*root=new node();

class Trie {
struct node* root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {

        node *temp = root;
        
        for(int x=0;x<word.length();x++){
            int idx = word[x]-'a';
            if(temp->children[idx]==NULL){
                temp->children[idx]=new node();
            }
            temp=temp->children[idx];
        }
        temp->isend=true;

    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        node *temp = root;
        
        for(int x=0;x<word.length();x++){
            int idx=word[x]-'a';
            if(temp->children[idx]==NULL) return false;
            temp=temp->children[idx];
        }
        
        return temp->isend;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        node *temp = root;
        
        for(int x=0;x<prefix.length();x++){
            int idx=prefix[x]-'a';
            if(temp->children[idx]==NULL) return false;
            temp=temp->children[idx];
        }
        return true;

    }
};
