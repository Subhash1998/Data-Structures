//function only

Node* merge(Node* head1, Node* head2)
{
    if(head1==NULL)
        return head2;
    
    if(head2==NULL)
        return head1;
        
    if(head1->data <= head2->data)
    {
        head1->next = merge(head1->next,head2);
        return head1;
    }
    
    head2->next = merge(head1,head2->next);
    return head2;
}
   
Node* mergeSort(Node* head) {
    
    if(head==NULL || head->next==NULL)
        return head;
    
    Node *slow = head, *fast = head;
    
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    Node *a = head;
    Node *b = slow->next;
    slow->next = NULL;
    
    Node *h1 = mergeSort(a);
    Node *h2 = mergeSort(b);
    
    return merge(h1,h2);
}
