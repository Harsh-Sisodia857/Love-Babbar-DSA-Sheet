#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    int childCount;
    TrieNode(int c)
    {
        data = c;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtils(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child = root;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }
        insertUtils(child, word.substr(1));
    }

    void insert(string word)
    {
        insertUtils(root, word);
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

    void longestPrefixUtils(TrieNode* root,string &s){
        int size = word.length();
        for (int i = 0; i < size; i++){
            int index = word[i] - 'a';
            TrieNode *child;
            if (root->childCount == 1){
                s += root->data;
                child = root->children[index];
                root = child;
            }else{
                return;
            }
        }
    }

    void longestPrefix(){
        string s = "";
        longestPrefixUtils(root->children[0],s);
        cout << s << endl;
    }
};

int main()
{
    Trie *t = new Trie();
    t->insert("abcd");
    t->insert("accenture");
    t->insert("apple");
    t->longestPrefix();
    return 0;
}