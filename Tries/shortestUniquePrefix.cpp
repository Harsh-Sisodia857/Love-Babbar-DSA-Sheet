#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    int childCount;
    bool isTerminal;
    TrieNode(char val)
    {
        data = val;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
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

    void insertUtils(string word, TrieNode *root)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
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
        insertUtils(word.substr(1), child);
    }

    void insert(string word)
    {
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

    void uniquePrefixUtils(TrieNode *root,string currentString){
        cout << root->childCount << " " << root->isTerminal << endl;
        if(root->childCount == 1 || root->isTerminal){
            currentString = root->children;
            cout<< currentString << " ";
            return;
        }
        for(int i = 0; i < 26; i++){
            if(root->children[i]){
                string s = root->children[i]->data + currentString;
                cout << s << endl;
                uniquePrefixUtils(root->children[i], s);
            }
        }
    }

    void uniquePrefix(){
        uniquePrefixUtils(root,"");
    }
};

int main()
{
    Trie *t = new Trie();
    t->insert("abcd");
    t->insert("accenture");
    t->insert("apple");
    // cout << "PRESENT OR NOT : " << t->search("apple") << endl;
    // vector<string> str;
    t->uniquePrefix();
    return 0;
}