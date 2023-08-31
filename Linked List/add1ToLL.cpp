//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    void reverseLL(Node **head)
    {
        Node *prev = NULL;
        Node *curr = *head;
        Node *nextPtr = NULL;
        while (curr != NULL)
        {
            nextPtr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextPtr;
        }
        *head = prev;
    }
    Node *addOne(Node *head)
    {
        reverseLL(&head);
        Node *curr = head, *prev = head;
        int sum = curr->data + 1;
        curr->data = sum % 10;
        int carry = sum / 10;
        curr = curr->next;
        while (curr != NULL)
        {
            sum = curr->data + carry;
            prev = curr;
            curr->data = sum % 10;
            carry = sum / 10;
            sum = sum / 10;
            curr = curr->next;
        }
        if (carry != 0)
        {
            Node *temp = new Node(carry);
            prev->next = temp;
        }

        reverseLL(&head);
        return head;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Node *head = new Node(s[0] - '0');
        Node *tail = head;
        for (int i = 1; i < s.size(); i++)
        {
            tail->next = new Node(s[i] - '0');
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends