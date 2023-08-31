//{ Driver Code Starts
// C program to delete a given key from
// linked list.
#include <bits/stdc++.h>
using namespace std;

/* structure for a node */
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

Node *pre = NULL;

/* Function to delete a given node from the list */
// void deleteNode(struct Node *head, int key);
void deleteNode(Node **head, int data);
void reverse(Node **head);

/* Function to reverse the linked list */
// static void reverse(struct Node** head_ref);

/* Function to insert a node at the beginning of
a Circular linked list */

void push(struct Node **head_ref, int data)
{
    // Create a new node and make head as next
    // of it.

    struct Node *curr = new Node(data);

    curr->next = curr;

    if (*head_ref == NULL)
    {
        *head_ref = curr;
        curr->next = *head_ref;
        pre = *head_ref;
    }
    else
    {
        curr->next = *head_ref;
        pre->next = curr;
        pre = pre->next;
    }
}

/* Function to print nodes in a given
circular linked list */
void printList(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    else
        cout << "empty" << endl;

    printf("\n");
}
/* Driver program to test above functions */
int main()
{

    /* Initialize lists as empty */
    int t, a, delnode;
    cin >> t;
    while (t--)
    {
        pre = NULL;
        Node *head = NULL;

        int n;
        cin >> n;
        while (n--)
        {
            cin >> a;
            push(&head, a);
        }
        /* Created linked list will be 2->5->7->8->10 */
        cin >> delnode;

        deleteNode(&head, delnode);

        reverse(&head);

        printList(head);
    }
    return 0;
}

// } Driver Code Ends

/* structure for a node
struct Node
{
    int data;
    struct Node *next;
};
*/

/* Function to delete a given node from the list */
void deleteNode(struct Node **head, int key)
{
    if (*head == NULL)
        return;

    struct Node *temp = *head, *prev = NULL;

    // Find the node to be deleted
    while (temp->data != key)
    {
        if (temp->next == *head)
        {
            // Element not found
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    // If the node to be deleted is the head node
    if (temp == *head)
    {
        // If it's the only node in the list
        if (temp->next == *head)
        {
            *head = NULL;
        }
        else
        {
            // Find the last node and update its next pointer
            struct Node *last = *head;
            while (last->next != *head)
            {
                last = last->next;
            }
            *head = (*head)->next;
            last->next = *head;
        }
    }
    else
    {
        // If the node is not the head node
        prev->next = temp->next;
    }

    // Free memory of the deleted node
    free(temp);
}

/* Function to reverse the linked list */
void reverse(struct Node **head_ref)
{
    struct Node *prev = NULL;
    struct Node *curr = *head_ref;
    struct Node *nextPtr = NULL;
    do
    {
        nextPtr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextPtr;
    } while (curr != (*head_ref));
    // curr ptr is pointing to head, prev is to the last node
    // First node of LL is attached with the last node
    (*head_ref)->next = prev;
    // updating head
    *head_ref = prev;
}