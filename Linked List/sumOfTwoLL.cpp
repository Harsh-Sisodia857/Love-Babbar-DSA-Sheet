//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
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

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    void reverseLL(struct Node **head)
    {
        struct Node *prev = NULL;
        struct Node *curr = *head;
        struct Node *nextPtr = NULL;
        while (curr != NULL)
        {
            nextPtr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextPtr;
        }
        *head = prev;
    }
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        reverseLL(&first);
        reverseLL(&second);
        struct Node *p1 = first;
        struct Node *p2 = second;
        int carry = 0;
        int val = p1->data + p2->data + carry;
        carry = val / 10;
        struct Node *newHead = new Node(val % 10);
        p1 = p1->next;
        p2 = p2->next;
        struct Node *p = newHead;
        while (p1 && p2)
        {
            val = p1->data + p2->data + carry;
            carry = val / 10;
            struct Node *temp = new Node(val % 10);
            p->next = temp;
            p = temp;
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1)
        {
            val = p1->data + carry;
            carry = val / 10;
            struct Node *temp = new Node(val % 10);
            p->next = temp;
            p = temp;
            p1 = p1->next;
        }
        while (p2)
        {
            val = p2->data + carry;
            carry = val / 10;
            struct Node *temp = new Node(val % 10);
            p->next = temp;
            p = temp;
            p2 = p2->next;
        }
        if (carry != 0)
        {
            Node *temp = new Node(carry);
            p->next = temp;
        }
        reverseLL(&newHead);
        return newHead;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends