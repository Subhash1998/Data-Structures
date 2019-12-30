//Source : geeksforgeeks

int find(Node* root,int &result)
{
    if(root==NULL)
        return INT_MAX;

    if(root->left==NULL && root->right==NULL)
        return root->data;

    int l = find(root->left,result);
    int r = find(root->right,result);
    
    result = max(result,root->data-min(l,r));
    return min(root->data,min(l,r));
}
int maxDiff(Node* root)
{
    int result = INT_MIN;
    find(root,result);
    return result;
}
