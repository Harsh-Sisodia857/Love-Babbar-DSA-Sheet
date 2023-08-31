//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
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

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

// } Driver Code Ends
/*Linked list Node structure

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
    // Function to merge K sorted linked list.
    Node *merge(Node *head1, Node *head2)
    {
        Node *ans = new Node(-1);
        Node *temp = ans;
        while (head1 && head2)
        {
            if (head1->data < head2->data)
            {
                temp->next = head1;
                head1 = head1->next;
                temp = temp->next;
            }
            else
            {
                temp->next = head2;
                head2 = head2->next;
                temp = temp->next;
            }
        }
        while (head1)
        {
            temp->next = head1;
            head1 = head1->next;
            temp = temp->next;
        }
        while (head2)
        {
            temp->next = head2;
            head2 = head2->next;
            temp = temp->next;
        }
        return ans->next;
    }
    Node *mergeKLists(Node *arr[], int K)
    {
        for (int i = 1; i < K; i++)
        {
            arr[0] = merge(arr[0], arr[i]);
        }
        return arr[0];
    }
};

//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        struct Node *arr[N];
        for (int j = 0; j < N; j++)
        {
            int n;
            cin >> n;

            int x;
            cin >> x;
            arr[j] = new Node(x);
            Node *curr = arr[j];
            n--;

            for (int i = 0; i < n; i++)
            {
                cin >> x;
                Node *temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
        }
        Solution obj;
        Node *res = obj.mergeKLists(arr, N);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends