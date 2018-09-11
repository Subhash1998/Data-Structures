
#include<iostream>
#include<stdlib.h>

using namespace std;
struct node
{
	int info;
	node *next;
}*top,*newptr,*save,*ptr;

node *create_new_node()
{
    int n;
    cout<<"\nEnter the item to push :- ";
    cin>>n;
	ptr=new node;
	ptr->info=n;
	ptr->next=NULL;
	return ptr;
}

void push(node *np)
{
    if(top == NULL)
		top=np;
	else
	{
		save=top;
		top=np;
		np->next=save;
	}
}

int pop()
{
    if(top==NULL)
        return 0;
    else
    {
        cout<<"Item deleting from stack is :- "<<top->info;
        save=top;
        top=top->next;
        delete save;
    }
    return 1;
}

void display(node *np)
{
    if(np==NULL)
        cout<<"\nStack Empty";
    else
    {
        while(np!=NULL)
        {
            cout<<np->info<<"->";
            np=np->next;
        }
    }
}

int main()
{
    int ch,deleted;
    char ans;
    do
    {
        system("cls");
        cout<<"1.Push\n2.Pop\n3.Display\n4.Exit";
        cout<<"\nEnter your choice(1,2,3 or 4) :- ";
        cin>>ch;
        switch(ch)
        {
            case 1:newptr=create_new_node();
                    if(newptr==NULL)
                        cout<<"\nStack Overflow!!";
                    else
                        push(newptr);
                break;
            case 2:deleted=pop();
                    if(deleted==0)
                        cout<<"\nStack Underflow";
                    else
                        cout<<"\nItem popped from stack";
                break;
            case 3:display(top);
                break;
            case 4:exit(1);
                break;
            default:cout<<"\nYou entered the wrong choice!!";
        }
        cout<<"\nDo you wish to continue(y/n) :- ";
        cin>>ans;
    }while(ans=='y'||ans=='Y');
    return 0;
}
