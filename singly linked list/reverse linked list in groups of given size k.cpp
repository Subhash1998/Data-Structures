struct node *reverse (struct node *head, int k)
{
    int count=0,tmp=0;
    node *cur = head, *prev = NULL, *temp = NULL, *save;
    while(cur!=NULL && count<k)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
        count++;
    }
    if(temp!=NULL)
        head->next = reverse(cur,k);
    
    return prev;
}

//other methods:- stack, queue.
