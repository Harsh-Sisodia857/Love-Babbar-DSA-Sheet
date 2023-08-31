bool isCircular(Node *head)
{
    Node *temp = head;
    do
    {
        temp = temp->next;
        if (temp == head)
            return true;
    } while (temp != NULL && temp->next != NULL);
    return false;
}