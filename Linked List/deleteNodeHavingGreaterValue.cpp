//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *nextPtr = NULL;
        while (curr != NULL)
        {
            nextPtr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextPtr;
        }
        return prev;
    }
    void deleteNode(Node *toDelete, Node *&head)
    {
        if (head == NULL)
            return;
        if (toDelete == head)
        {
            Node *t = head;
            head = head->next;
            delete t;
        }
        Node *temp = head, *p = head;
        // 3 2 6 5
        while (temp != NULL)
        {
            if (temp->next == toDelete)
            {
                temp->next = toDelete->next;
                delete toDelete;
                return;
            }
            temp = temp->next;
        }
    }
    Node *compute(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        head = reverse(head);
        int max = head->data;
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data < max)
            {
                deleteNode(temp, head);
            }
            else
            {
                max = temp->data;
            }
            temp = temp->next;
        }
        head = reverse(head);
        return head;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout << endl;
    }
}

// } Driver Code Ends