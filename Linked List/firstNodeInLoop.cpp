//{ Driver Code Starts
// Initial Template for C++

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

void loopHere(Node *head, Node *tail, int position)
{
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

// } Driver Code Ends
// User function Template for C++

/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
public:
    // Function to find first node if the linked list has a loop.
    int findFirstNode(Node *head)
    {
        if (head == NULL)
            return -1;
        Node *fast = head;
        Node *slow = head;
        do
        {
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow && fast->next && fast->next->next);
        if (slow == fast)
        {
            fast = head;
            if (fast == slow)
            {
                while (fast->next != slow && fast->next)
                    fast = fast->next;
                return slow->data;
            }
            else
            {
                while (fast->next != slow->next && fast->next)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast->next->data;
            }
        }
        else
        {
            return -1;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, num;
        cin >> n;

        Node *head, *tail;
        cin >> num;
        head = tail = new Node(num);

        for (int i = 0; i < n - 1; i++)
        {
            cin >> num;
            tail->next = new Node(num);
            tail = tail->next;
        }

        int pos;
        cin >> pos;
        loopHere(head, tail, pos);

        Solution ob;
        int ans = ob.findFirstNode(head);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends