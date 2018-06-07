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

void add_node_mid(node *np,int item)
{
    if(start==NULL)
    {
        start=endd=np;
    }
    else if(start->forw==NULL)
    {
        np->backw=endd;
        start->forw=np;
        endd=np;
    }
    else
    {
        node *temp=start;
        cout<<temp->info<<endl<<item<<endl<<endd<<endl;
        while(temp->info!=item&&temp!=endd)
        {
            temp=temp->forw;
        }
        if(temp->info==item)
        {
            np->forw=temp->forw;
            np->backw=temp;
            (temp->forw)->backw=np;
            temp->forw=np;
        }
        else
        {
            cout<<"Item not found\n";
        }
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
    int n,item;
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
        cout<<"\nEnter the item after which the node is to be added :- ";
        cin>>item;
        cout<<"\nAdding new node to linked list";
        add_node_mid(newptr,item);
        cout<<"\nNew node added successfully!!!";
        cout<<"\nThe new linked list is :- \n";
        display(start);
        cout<<"\nDo you wish to continue(y/n)? :- ";
        cin>>ans;
    }
    return 0;
}
