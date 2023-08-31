struct node *reverse(struct node *head, int k){
    struct node *prev = NULL;
    struct node *curr = head;
    struct node *nextPtr;
    int count = 0;
    while (curr != NULL && count < k)
    {
        nextPtr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextPtr;
        count++;
    }
    if (nextPtr)
        head->next = reverse(nextPtr, k);
    return prev;
}
