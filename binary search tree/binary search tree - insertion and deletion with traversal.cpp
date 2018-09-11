#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int info;
    node *left,*right;
}*root,*ptr;

node *create_new_node(int n)
{
    ptr=new node;
    ptr->info=n;
    ptr->left=ptr->right=NULL;
    return ptr;
}

node *insert_tree(node *np,int n)
{
    if(root==NULL)
        root=create_new_node(n);
    else if(np==NULL)
        return create_new_node(n);
    else if(n>np->info)
        np->right=insert_tree(np->right,n);
    else
        np->left=insert_tree(np->left,n);
    return np;
}

node *delete_tree(node *np,int n)
{
    if(root==NULL)
        cout<<"\nCannot delete...the tree is empty!!";
    else
    {
        if(np==NULL)
            return np;
        if(n>np->info)
            np->right=delete_tree(np->right,n);
        else if(n<np->info)
            np->left=delete_tree(np->left,n);
        else
        {
            if(np->left==NULL)
            {
                node *temp=np->right;
                delete np;
                return temp;
            }
            else if(np->right==NULL)
            {
                node *temp=np->left;
                delete np;
                return temp;
            }
            node *save=np->right;
            while(save->left!=NULL)
                save=save->left;
            np->info=save->info;
            np->right=delete_tree(np->right,save->info);
        }
    }
    return np;
}

void inorder(node *np)
{
    if(np!=NULL)
    {
        inorder(np->left);
        cout<<np->info<<" ";
        inorder(np->right);
    }
}

int main()
{
    root=NULL;
    int ch,n;
    char ans;
    do
    {
        system("cls");
        cout<<"1.Insert\n2.Delete\n3.Check Inorder Traversal\n4.Exit";
        cout<<"\nEnter your choice(1,2,3 or 4) :- ";
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"\nEnter the item to insert :- ";
                   cin>>n;
                   ptr=insert_tree(root,n);
                   cout<<"\nItem inserted in tree";
                break;
            case 2:cout<<"\nEnter the item to delete :- ";
                   cin>>n;
                    root=delete_tree(root,n);
                    break;
            case 3:inorder(root);
                break;
            case 4:exit(1);
                break;
            default:cout<<"\nYou entered a wrong choice!!";
        }
        cout<<"\nDo you wish to continue?(y/n) :- ";
        cin>>ans;
    }while(ans=='y'||ans=='Y');
}
