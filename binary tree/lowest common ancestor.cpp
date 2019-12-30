//Source: geeksforgeeks


bool findpath(Node* root,vector<Node*> &path,int n)
{
    if(root==NULL)
        return false;
    
    path.push_back(root);
    
    if(root->data==n)
        return true;
    
    if((root->left && findpath(root->left,path,n)) || (root->right && findpath(root->right,path,n)))
        return true;
    
    path.pop_back();
    return false;
}
   
Node * lca(Node* root ,int n1 ,int n2)
{
    vector<Node*> path1,path2;
    findpath(root, path1, n1);
    findpath(root, path2, n2);
    int i;
    for(i=0;i<path1.size() && i<path2.size();i++)
    {
        if(path1[i]!=path2[i])
            break;
    }
    return path1[i-1];
}
