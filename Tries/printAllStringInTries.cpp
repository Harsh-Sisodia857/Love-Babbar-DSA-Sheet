#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public : 
    char data;
    TrieNode *children[26];
    int childCount;
    bool isTerminal;
    TrieNode(char val){
        data = val;
        for (int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie{
    public :
    TrieNode *root;
    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtils(string word,TrieNode *root){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }
        insertUtils(word.substr(1), child);
    }

    void insert(string word){
        insertUtils(word, root);
    }

    bool searchUtils(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        TrieNode *temp;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            // present
            temp = root->children[index];
        }
        else
        {
            // not present
            return false;
        }
        // recursion
        return searchUtils(temp, word.substr(1));
    }

    bool search(string word)
    {
        return searchUtils(root, word);
    }

    void printUtils(TrieNode *root, vector<string> &ans, string currentWord)
    {
        if (root->isTerminal)
        {
            ans.push_back(currentWord);
            return;
        }
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i])
            {
                string s = currentWord + root->children[i]->data;
                printUtils(root->children[i], ans, s);
            }
        }
    }

    void print(vector<string> &ans)
    {
        printUtils(root, ans, "");
    }
};

int main(){
    Trie *t = new Trie();
    t->insert("abcd");
    t->insert("accenture");
    t->insert("apple");
    // cout << "PRESENT OR NOT : " << t->search("apple") << endl;
    vector<string> str;
    t->print(str);
    for(auto it : str)
        cout << it << " ";
    return 0;
  }