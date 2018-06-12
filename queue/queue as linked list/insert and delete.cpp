#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node
{
    int info;
    //cannot declare back(it is a keyword) as variable
    node *next;
}*frontt,*rear,*newptr,*ptr,*save;
//cannot declare end(a keyword) as variable

node *create_new_node(int n)
{
    ptr=new node;
    ptr->info=n;
    ptr->next=NULL;
    return ptr;
}

void add_node_end(node *np)
{
    if(frontt==NULL)
        frontt=rear=np;
    else
    {
        rear->next=np;
        rear=np;
    }
}

int del_node_beg()
{
    if(frontt==NULL)
        return 0;
    else
    {
        save=frontt;
        frontt=frontt->next;
        delete save;
    }
    return 1;
}

void display(node *np)
{
    while(np!=NULL)
    {
        cout<<np->info<<"->";
        np=np->next;
    }
}

int main()
{
    char ans='y';
    int n,ch,deleted;
    frontt=rear=NULL;
    while(ans=='y'||ans=='Y')
    {
        system("cls");
        cout<<"1.Insert\n2.Delete\n3.Display\n4.Exit";
        cout<<"\nEnter your choice :- ";
        cin>>ch;
        switch(ch)
        {
            case 1:
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
            cout<<"\nOverflow";
        }
        cout<<"\nAdding new node to linked list";
        add_node_end(newptr);
        cout<<"\nNew node added successfully!!!";
        break;
        case 2:
            deleted=del_node_beg();
            if(deleted==0)
            {
                cout<<"\nUnderflow";
            }
            else if(deleted==1)
            {
                cout<<"\nNode deleted Successfully!!";
            }
            break;
        case 3:
        cout<<"\nThe new linked list is :- \n";
        display(frontt);
        break;
        case 4:exit(1);
            break;
        default:cout<<"\nWrong choice!!";
        }
        cout<<"\nDo you wish to continue(y/n)? :- ";
        cin>>ans;
    }
    return 0;
}
