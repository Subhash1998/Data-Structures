//using queue and map


void bottomView(Node *root)
{
    if(root==NULL)
        return;
    int hd = 0;
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,hd));
    while(!q.empty())
    {
        Node *ptr = q.front().first;
        hd = q.front().second;
        q.pop();
        mp[hd] = ptr->data;
        if(ptr->left)
            q.push(make_pair(ptr->left,hd-1));
        if(ptr->right)
            q.push(make_pair(ptr->right,hd+1));
    }
    for(auto it:mp)
        cout<<it.second<<" ";
}
