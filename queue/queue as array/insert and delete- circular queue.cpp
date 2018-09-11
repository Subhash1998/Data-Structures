#include<iostream>
#include<stdlib.h>
using namespace std;

int frontt=-1,rear=-1,q[10000];
#define n 3

void queue_insert()
{
    int item;
    cout<<"\nEnter the element to insert :- ";
    cin>>item;
    if((frontt==0&&rear==n-1)||(frontt==rear+1))
        cout<<"\nOverflow";
    else if(frontt==-1&&rear==-1)
    {
        frontt=rear=0;
        q[rear]=item;
    }
    else if(rear==n-1)
    {
        rear=0;
        q[rear]=item;
    }
    else
    {
        rear++;
        q[rear]=item;
    }
}

void queue_delete()
{
    if(frontt==-1&&rear==-1)
        cout<<"\nUnderflow";
    else if(rear==frontt)
        frontt=rear=-1;
    else if(frontt==n-1)
        frontt=0;
    else
        frontt++;
}

void display()
{
    int i;
    if(frontt==-1&&rear==-1)
        cout<<"\nNo item to display";
    else if(frontt<=rear)
    {
        for(i=frontt;i<=rear;i++)
            cout<<"\n"<<q[i];
    }
    else
    {
        for(i=frontt;i<n;i++)
            cout<<"\n"<<q[i];
        for(i=0;i<=rear;i++)
            cout<<"\n"<<q[i];
    }
}

int main()
{
    int ch;
    char ans;
    do
    {
        system("cls");
        cout<<"1.Insert\n2.Delete\n3.Display\n4.Exit";
        cout<<"\nEnter your choice(1,2,3 or 4) :- ";
        cin>>ch;
        switch(ch)
        {
            case 1:queue_insert();
                break;
            case 2:queue_delete();
                break;
            case 3:display();
                break;
            case 4:exit(1);
                break;
            default:cout<<"\nYou entered wrong choice!!";
        }
        cout<<"\nDo you wish to continue(y/n) :- ";
        cin>>ans;
    }while(ans=='y'||ans=='Y');
    return 0;
}
