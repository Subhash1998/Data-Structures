// geeksforgeeks practice 
// sum tree => data of node = sum of left subtree of node + sum of right subtree

int sum(Node *node)
{
    if(node==NULL)
        return 0;
    int old = node->data;
    int left = sum(node->left);
    int right = sum(node->right);
    
    node->data = left+right;
    
    return old+node->data;
}

void toSumTree(Node *node)
{
    sum(node);
}
