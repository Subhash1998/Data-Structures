#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int info;
    node *left;
    node *right;
}*root,*ptr;

node *insert_node(int n)
{
    ptr=new node;
    ptr->info=n;
    ptr->left=ptr->right=NULL;
    return ptr;
}

void preorder(node *temp)
{
    if(temp!=NULL)
    {
        cout<<temp->info<<" ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

void inorder(node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        cout<<temp->info<<" ";
        inorder(temp->right);
    }
}

void postorder(node *temp)
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->info<<" ";
    }
}

int main()
{
    int ch;
    char ans;
    root=NULL;
    root=insert_node(10);
    root->left=insert_node(24);
    root->right=insert_node(14);
    root->left->left=insert_node(5);
    root->left->right=insert_node(21);
    root->right->left=insert_node(34);
    root->right->right=insert_node(11);
    root->right->left->left=insert_node(54);
    root->right->left->right=insert_node(67);
    /*
                     10
                    /  \
                   24   14
                  / \   / \
                 5   21 34 11
                        / \
                       54 67
    */
    do
    {
        system("cls");
        cout<<"1.Preorder traversal\n2.Inorder traversal\n3.Postorder traversal\n4.Exit";
        cout<<"\nEnter your choice(1,2,3 or 4) :- ";
        cin>>ch;
        switch(ch)
        {
            case 1:preorder(root);
                break;
            case 2:inorder(root);
                break;
            case 3:postorder(root);
                break;
            case 4:exit(1);
                break;
            default:cout<<"\nYou entered a wrong choice!!";
        }
        cout<<"\nDo you wish to continue?(y/n) :- ";
        cin>>ans;
    }while(ans=='y'||ans=='Y');
    return 0;
}
