bool check(Node* T1, Node* T2)
{
    if(T1==NULL && T2==NULL)
        return true;
    
    if(T1==NULL || T2==NULL)
        return false;
    
    if(T1->data!=T2->data)
        return false;
    return (check(T1->left,T2->left) && check(T1->right,T2->right));
}

bool isSubtree(Node* T1, Node* T2) {
    
    if(T2==NULL)
        return true;
    
    if(T1==NULL)
        return false;
    
    if(check(T1,T2))
        return true;
        
    return (isSubtree(T1->left,T2) || isSubtree(T1->right,T2));
}
