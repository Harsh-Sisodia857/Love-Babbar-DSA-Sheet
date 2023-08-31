void removeLoop(Node *head)
{
    // code here
    // just remove the loop without losing any nodes
    if (head == NULL)
        return;
    Node *tortoise = head;
    Node *hare = head;
    while (hare != NULL && hare->next != NULL)
    {
        if (tortoise->next)
            tortoise = tortoise->next;
        else
            return;
        if (hare->next->next)
            hare = hare->next->next;
        else
            return;
        if (hare == tortoise)
        {
            break; // Loop detected
        }
    }
    // if loop is not present
    if (hare != tortoise)
        return;

    hare = head;
    // last node of LL is connected to first node
    if (hare == tortoise)
    {
        while (hare->next != tortoise && hare->next)
        {
            hare = hare->next;
        }
        hare->next = NULL;
    }
    else
    {
        while (hare->next != tortoise->next)
        {
            hare = hare->next;
            tortoise = tortoise->next;
        }
        tortoise->next = NULL;
    }
}