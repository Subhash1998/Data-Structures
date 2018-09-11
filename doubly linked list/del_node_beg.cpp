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

int del_node_beg()
{
    if(start==NULL)
        return 0;
    else if(start->forw==NULL)
    {
        save=start;
        start=endd=NULL;
        delete save;
    }
    else
    {
        save=start;
        start=start->forw;
        start->backw=NULL;
        save->forw=NULL;
        delete save;
    }
    return 1;
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
    cout<<"\nDo you wish to delete first node(y/n)? :- ";
	cin>>ans;
    while(ans == 'y'|| ans == 'Y')
	{
		int deleted=del_node_beg();
		if(deleted==0)
        {
            cout<<"\nCannot delete node....Aborting!!";
            exit(1);
        }
        else if(deleted==1)
        {
            cout<<"\nNode deleted Successfully!!";
            display(start);
        }
        cout<<"\nDo you wish to continue deleting(y/n)?";
        cin>>ans;
	}
    return 0;
}
