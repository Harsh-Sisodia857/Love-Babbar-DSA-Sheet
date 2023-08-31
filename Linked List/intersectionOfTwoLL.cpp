//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *inputList(int size)
{
    Node *head, *tail;
    int val;

    cin >> val;
    head = tail = new Node(val);

    while (--size)
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
}

Node *findIntersection(Node *head1, Node *head2);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        Node *head1 = inputList(n);
        Node *head2 = inputList(m);

        Node *result = findIntersection(head1, head2);

        printList(result);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node *findIntersection(Node *head1, Node *head2)
{
    unordered_map<int, int> vis;
    Node *temp = head1;
    while (temp != NULL)
    {
        vis[temp->data]++;
        temp = temp->next;
    }
    Node *newHead = NULL, *q = NULL;
    temp = head2;
    while (temp != NULL)
    {
        if (vis.find(temp->data) != vis.end() && vis[temp->data] > 0)
        {
            vis[temp->data]--;
            Node *p = new Node(temp->data);
            if (newHead == NULL)
            {
                newHead = p;
                q = p;
            }
            else
            {
                q->next = p;
                q = p;
            }
        }
        temp = temp->next;
    }
    return newHead;
}