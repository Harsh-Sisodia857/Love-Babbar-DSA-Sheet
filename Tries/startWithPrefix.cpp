#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public :
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char val){
        data = val;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        isTerminal = false;
    }
};

class Trie{
    public : 
    TrieNode *root;
    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtils(TrieNode* root,string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtils(child, word.substr(1));
    }

    void insert(string word){
        insertUtils(root, word);
    }

    bool prefixUtils(string word,TrieNode* root){
        if(word.length() == 0){
            return true;
        }
        TrieNode *child;
        int index = word[0] - 'a';
        if(root->children[index] == NULL)
            return false;
        else
            child = root->children[index];
        return prefixUtils(word.substr(1), child);
    } 
    bool prefix(string word){
       return prefixUtils(word, root);
    }
};

int main()
  {
    Trie *t = new Trie();
    t->insert("abc");
    t->insert("abc");
    t->insert("apple");
    cout << t->prefix("abcd");
    return 0;
  }