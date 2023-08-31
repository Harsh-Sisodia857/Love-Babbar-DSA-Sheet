
// removing duplicate when linked list is already sorted
Node *removeDuplicates(Node *head)
{
    // your code goes here
    if (head == NULL)
        return NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        // duplicate -- aage mt bhadna
        if (curr->next != NULL && curr->next->data == curr->data)
        {
            Node *p = curr->next->next;
            Node *toDelete = curr->next;
            delete (toDelete);
            curr->next = p;
        }
        // not duplicate -- aage bhad jao
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

// removing duplicate when LL is not sorted

Node *removeDuplicates(Node *head)
{
    if (head == NULL)
        return NULL;
    map<int, bool> vis;
    Node *temp = head;
    Node *prev = head;
    while (temp != NULL)
    {
        if (vis.find(temp->data) == vis.end())
        {
            vis[temp->data] = true;
            prev = temp;
            temp = temp->next;
        }
        else
        {
            Node *nextNode = temp->next;
            prev->next = nextNode;
            delete temp;
            temp = nextNode;
        }
    }
    return head;
}