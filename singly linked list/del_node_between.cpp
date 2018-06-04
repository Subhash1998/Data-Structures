#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
	int info;
	node *next;
}*start,*newptr,*save,*ptr;

node *create_new_node(int n)
{
	ptr=new node;
	ptr->info=n;
	ptr->next=NULL;
	return ptr;
}

void add_beg(node *np)
{
	if(start == NULL)
		start=np;
	else
	{
		save=start;
		start=np;
		np->next=save;
	}
}

int del_node_between(int item)
{
    if(start==NULL)
        return 0;
    else if(start->next==NULL)
            start=NULL;
    else if(start->info==item)
        start=start->next;
    else
    {
        node *ptr;
        node *temp=start;
        while((temp->info!=item)&&(temp->next!=NULL))
        {
            ptr=temp;
            temp=temp->next;
        }
        if(temp->info==item)
            ptr->next=temp->next;
        else
        {
            cout<<"\nElement not found";
            return 2;
        }
        delete temp;
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
	int info,item;
	start=NULL;
	char ans = 'Y';
	while(ans == 'y'|| ans == 'Y')
	{
		cout<<"Enter information for new node :- ";
		cin>>info;
		cout<<"\nCreating new node";
		newptr=create_new_node(info);
		if(newptr!=NULL)
			cout<<"\nNew node created!!";
		else
		{
			cout<<"\nCould not create new node....Aborting!!";
			exit(1);
		}
		cout<<"\nAdding node to linked list";

		add_beg(newptr);
		cout<<"\nNode added successfully!!\n";
		display(start);
		cout<<"\nDo you wish to continue(Y/N)?";
		cin>>ans;
	}
	ans='y';
    while(ans == 'y'|| ans == 'Y')
	{
	    cout<<"\nEnter the item to be deleted :- ";
	    cin>>item;
		int deleted=del_node_between(item);
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

