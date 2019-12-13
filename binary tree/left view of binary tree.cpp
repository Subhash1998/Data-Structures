//Recursive approach (geeksforgeeks)

void traverse(Node *root,int level,int* max_level)
{
    if(root==NULL)
        return;
        
    if(*max_level<level)
    {
        cout<<root->data<<" ";
        *max_level = level;
    }
    traverse(root->left,level+1,max_level);
    traverse(root->right,level+1,max_level);
}

void leftView(Node *root)
{
    int max_level = 0;
    traverse(root,1,&max_level);
}


//Iterative approach (Interviewbit)

vector<int> Solution::solve(TreeNode* A)
{
    queue<TreeNode *> q;
    q.push(A);
    q.push(NULL);
    vector<int> v;
    while(!q.empty())
    {
        TreeNode *ptr = q.front();
        if(ptr!=NULL)
        {
            v.push_back(ptr->val);
            while(q.front()!=NULL)
            {
                if(ptr->left!=NULL)
                    q.push(ptr->left);
                if(ptr->right)
                    q.push(ptr->right);
                q.pop();
                ptr = q.front();
            }
            q.push(NULL);
        }
        q.pop();
    }
    return v;
}
