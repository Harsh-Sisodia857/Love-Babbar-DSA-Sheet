//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

// } Driver Code Ends
/* Structure of the linked list node is as
struct Node
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

class Solution
{
public:
    // finding middle node
    Node *findMid(Node *head)
    {
        Node *slow = head;
        Node *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    // merge two LL
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
    // Function to sort the given linked list using Merge Sort.
    Node *mergeSort(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        Node *mid = findMid(head);
        Node *left = head;
        Node *right = mid->next;
        mid->next = NULL;
        left = mergeSort(left);
        right = mergeSort(right);
        return merge(left, right);
    }
};

//{ Driver Code Starts.

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    long test;
    cin >> test;
    while (test--)
    {
        struct Node *a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends