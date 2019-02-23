#include<bits/stdc++.h>
using namespace std;

void build(int node,int start,int end,int tree[],int v[])
{
    if(start==end)
    {
        tree[node]=v[start];
    }
    else
    {
        int mid = (start+end)/2;
        
        build(2*node,start,mid,tree,v);
        build(2*node+1,mid+1,end,tree,v);
        
        if(tree[2*node]<tree[2*node+1])
            tree[node]=tree[2*node];
        else
            tree[node]=tree[2*node+1];
    }
}

void update(int node,int start,int end,int index,int val,int tree[],int v[])
{
    if(start==end)
    {
        v[index]=val;
        tree[node]=val;
    }
    else
    {
        int mid = (start+end)/2;
        
        if(index>=start && index<=mid)
        {
            update(2*node,start,mid,index,val,tree,v);
        }
        else
        {
            update(2*node+1,mid+1,end,index,val,tree,v);
        }
        if(tree[2*node]<tree[2*node+1])
            tree[node]=tree[2*node];
        else
            tree[node]=tree[2*node+1];
    }
}

int query(int node,int start,int end,int l,int r,int tree[],int v[])
{
    if(r<start || l>end)
    {
        return 100005; //no overlap
    }
    if(l<=start && r>=end)
    {
        return tree[node]; //total overlap
    }
    
    //partial overlap
    
    int mid=(start+end)/2;
    int p1,p2;
    p1=query(2*node,start,mid,l,r,tree,v);
    p2=query(2*node+1,mid+1,end,l,r,tree,v);
    if(p1>p2)
        return p2;
    else 
        return p1;
}

int main()
{
    int n,q,i;
    int v[1000000],tree[1000000];
    cin>>n>>q;
    for(i=1;i<=n;i++)
        cin>>v[i];
    
    build(1,1,n,tree,v);
    for(i=0;i<q;i++)
    {
        char c;
        cin>>c;
        if(c=='q')
        {
            int l,r;
            cin>>l>>r;
            int ans=query(1,1,n,l,r,tree,v);
            cout<<ans<<"\n";
        }
        else
        {
            int x,y;
            cin>>x>>y;
            update(1,1,n,x,y,tree,v);
        }
    }
    return 0;
}
