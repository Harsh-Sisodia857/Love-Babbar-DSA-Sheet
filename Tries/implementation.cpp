#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public :
        char data;
        TrieNode *children[26];
        bool isTerminal;
        TrieNode(int c){
            data = c;
            for (int i = 0; i < 26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie{
    public :
        TrieNode *root;
       Trie(){
            root = new TrieNode('\0');
       }

        void insertUtils(TrieNode *root,string word){
            if(word.length() == 0){
                root->isTerminal = true;
                return;
            }
            int index = word[0] - 'a';
            TrieNode *child = root;
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

        bool searchUtils(TrieNode* root,string word){
            if(word.length() == 0){
                return root->isTerminal;
            }
            TrieNode *temp;
            int index = word[0] - 'a';
            if(root->children[index] != NULL){
                // present
                temp = root->children[index];
            }else{
                // not present
                return false;
            }
            // recursion
           return searchUtils(temp, word.substr(1));
        }

        bool search(string word){
            return searchUtils(root, word);
        }

        void deleteUtils(TrieNode *root,string word){
            if(word.length() == 0){
                root->isTerminal = false;
                return;
            }
            int index = word[0] - 'a';
            TrieNode *temp;
            if(root->children[index] != NULL){
                temp = root->children[index];
            }else{
                cout << "THE WORD TO BE DELETED DOES NOT EXIST" << endl;
                return;
            }
            deleteUtils(temp, word.substr(1));
        }

        void deleteWord(string word){
            deleteUtils(root, word);
        }
};

int main()
  {
        Trie *t = new Trie();
        t->insert("abcd");
        t->insert("accenture");
        t->insert("apple");
        cout << "PRESENT OR NOT : " << t->search("apple") << endl;
        t->deleteWord("apple");
        cout << "PRESENT OR NOT : " << t->search("apple") << endl;

        return 0;
  }