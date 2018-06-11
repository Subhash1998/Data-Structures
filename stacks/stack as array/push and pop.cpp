#include<iostream>
#include<stdlib.h>

using namespace std;

int top=-1,arr[100000];

void push()
{
    int item;
    cout<<"\nEnter the item to push :- ";
    cin>>item;
    if(top==99999)
        cout<<"\nStack Overflow...delete some items to push!!";
    else
    {
        top++;
        arr[top]=item;
    }
}

void pop()
{
    if(top==-1)
        cout<<"\nStack Underflow...no item to delete!!";
    else
    {
        cout<<"\nItem popped from stack is :- "<<arr[top];
        top--;
    }
}

void display()
{
    int i;
    if(top>=0)
    {
        for(i=0;i<=top;i++)
            cout<<"\n"<<arr[i];
        cout<<"<--top";
    }
    else
        cout<<"\nNo items to display";
}

int main()
{
    int ch;
    char ans;
    do
    {
        system("cls");
        cout<<"1.Push\n2.Pop\n3.Display\n4.Exit";
        cout<<"\nEnter your choice(1,2,3 or 4) :- ";
        cin>>ch;
        switch(ch)
        {
            case 1:push();
                break;
            case 2:pop();
                break;
            case 3:display();
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
