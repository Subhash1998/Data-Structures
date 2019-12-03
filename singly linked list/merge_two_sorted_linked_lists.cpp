//function only...


Node* sortedMerge(Node* head1,   Node* head2)
{
    struct Node *ptr1 = head1, *ptr2 = head2 , *temp2, *prev = head1;
    
    if(ptr2==NULL)
        return ptr1;
    if(ptr1==NULL)
        return ptr2;
    
    while(ptr1!=NULL && ptr2!=NULL)
    {
        int x = ptr1->data;
        int y = ptr2->data;
        
        if(x>y)
        {
            temp2 = ptr2->next;
            if(ptr1==head1)
            {
                ptr2->next = head1;
                head1 = ptr2;
                prev = ptr2;
            }
            else
            {
                ptr2->next = prev->next;
                prev->next = ptr2;
                prev = ptr2;
            }
            ptr2 = temp2;
        }
        else
        {
            if(ptr1!=head1)
                prev = prev->next;
            ptr1 = ptr1->next;
        }
    }
    if(ptr2!=NULL)
    {
        temp2 = head1;
        while(temp2->next!=NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = ptr2;
    }
    return head1;
}
