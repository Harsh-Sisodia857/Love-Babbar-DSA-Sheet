//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
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
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution
{
public:
    Node *reverseLL(Node **head)
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
        return prev;
    }
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if (head == NULL)
        {
            return true;
        }
        Node *slow = head;
        Node *fast = head;
        // finding middle element
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // cout << slow->data << " ";
        Node *secondHalf = reverseLL(&slow);

        // checking for palindrome
        Node *firstHalf = head;
        while (secondHalf != NULL)
        {
            if (firstHalf->data != secondHalf->data)
                return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return true;
    }
};

//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
    int T, i, n, l, firstdata;
    cin >> T;
    while (T--)
    {

        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        // taking first data of LL
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout << obj.isPalindrome(head) << endl;
    }
    return 0;
}

// } Driver Code Ends