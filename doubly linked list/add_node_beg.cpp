#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node
{
    int info;
    //cannot declare back(it is a keyword) as variable
    node *forw,*backw;
}*start,*endd,*newptr,*ptr,*save;
//cannot declare end(a keyword) as variable

node *create_new_node(int n)
{
    ptr=new node;
    ptr->info=n;
    ptr->forw=ptr->backw=NULL;
    return ptr;
}

void add_node_beg(node *np)
{
    if(start==NULL)
        start=endd=np;
    else
    {
        np->forw=start;
        start->backw=np;
        start=np;
    }
}

void display(node *np)
{
    while(np!=NULL)
    {
        cout<<np->info<<"->";
        np=np->forw;
    }
}

int main()
{
    char ans='y';
    int n;
    start=endd=NULL;
    while(ans=='y'||ans=='Y')
    {
        cout<<"\nEnter the item to be added :- ";
        cin>>n;
        cout<<"\nCreating new node";
        newptr=create_new_node(n);
        if(newptr!=NULL)
        {
            cout<<"\nNew node created";
        }
        else
        {
            cout<<"\nCannot create new node....Aborting!!!";
            exit(1);
        }
        cout<<"\nAdding new node to linked list";
        add_node_beg(newptr);
        cout<<"\nNew node added successfully!!!";
        cout<<"\nThe new linked list is :- \n";
        display(start);
        cout<<"\nDo you wish to continue(y/n)? :- ";
        cin>>ans;
    }
    return 0;
}
