#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(int c)
    {
        data = c;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

TrieNode *root;
class Trie
{
public:
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

    void deleteUtils(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *temp;
        if (root->children[index] != NULL)
        {
            temp = root->children[index];
        }
        else
        {
            cout << "THE WORD TO BE DELETED DOES NOT EXIST" << endl;
            return;
        }
        deleteUtils(temp, word.substr(1));
    }

    void deleteWord(string word)
    {
        deleteUtils(root, word);
    }

bool wordBreak(string str, TrieNode *root)
{
    int size = str.size();

    // Base case
    if (size == 0)
        return true;

    // Try all prefixes of lengths from 1 to size
    for (int i = 1; i <= size; i++)
    {
        if (searchUtils(root, str.substr(0, i)) && wordBreak(str.substr(i, size - i), root))
            return true;
    }

    // If we have tried all prefixes and none
    // of them worked
    return false;
  } 
};

// Driver program to test above functions
int main()
{
    string dictionary[] = {"mobile", "samsung", "sam", "sung", "ma\n",
                           "mango", "icecream", "and", "go", "i",
                           "like", "ice", "cream"};
    int n = sizeof(dictionary) / sizeof(dictionary[0]);
    Trie *t = new Trie();

    // Construct trie
    for (int i = 0; i < n; i++)
        t->insertUtils(root, dictionary[i]);

    t->wordBreak("ilikesamsung", root) ? cout << "Yes\n"
                                       : cout << "No\n";
    t->wordBreak("iiiiiiii", root) ? cout << "Yes\n"
                                   : cout << "No\n";
    t->wordBreak("", root) ? cout << "Yes\n" : cout << "No\n";
    t->wordBreak("ilikelikeimangoiii", root) ? cout << "Yes\n"
                                             : cout << "No\n";
    t->wordBreak("samsungandmango", root) ? cout << "Yes\n"
                                          : cout << "No\n";
    t->wordBreak("samsungandmangok", root) ? cout << "Yes\n"
                                           : cout << "No\n";
    return 0;
}