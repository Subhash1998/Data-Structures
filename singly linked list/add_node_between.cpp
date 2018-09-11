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

void add_between(node *np,int item)
{
	if(start == NULL)
		start=np;
	else
	{
	    node *temp=start;
		while((temp->info)!=item&&(temp->next!=NULL))
        {
            temp=temp->next;
        }
        if(temp->info==item)
        {
            np->next=temp->next;
            temp->next=ptr;
        }
        else
        {
            cout<<"\nElement not found!!";
        }
	}
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
		cout<<"\nEnter information after which the node has to be added :- ";
		cin>>item;
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

		add_between(newptr,item);
		cout<<"\nNode added successfully!!\n";
		display(start);
		cout<<"\nDo you wish to continue(Y/N)?";
		cin>>ans;
	}
    return 0;
}

