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
int getNthFromLast(Node *head, int n)
{
    head = reverse(head);
    Node *temp = head;
    n = n - 1;
    if (n == 0)
        return head->data;
    while (n && temp->next)
    {
        temp = temp->next;
        n--;
        if (n == 0)
            return temp->data;
    }
    return -1;
}