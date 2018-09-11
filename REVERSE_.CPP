#include<iostream.h>
#include<conio.h>
struct node{
 int info;
 node *next;
}*start,*ptr,*save;

node *create_new_node(int n)
{
 ptr=new node;
 ptr->info=n;
 ptr->next=NULL;
 return ptr;
}
void insert_node(node *ptr)
{
 if(start==NULL)
  start=ptr;
 else
 {
  save=start;
  start=ptr;
  ptr->next=save;
 }
}
void print_node(node *temp)
{
 while(temp!=NULL)
 {
  cout<<temp->info<<"->";
  temp=temp->next;
 }
}
void reverse()
{
 node *next,*cur,*prev;
 prev=next=NULL;
 cur=start;
 while(cur!=NULL)
 {
  next=cur->next;
  cur->next=prev;
  prev=cur;
  cur=next;
 }
 start=prev;
}

void main()
{
 clrscr();
 start=NULL;
 char ans='y';
 int n;
 while(ans=='y'||ans=='Y')
 {
  cout<<"enter new node value :- ";
  cin>>n;
  ptr=create_new_node(n);
  insert_node(ptr);
  cout<<"continue? :- ";
  cin>>ans;
 }
 cout<<"before reversal :- \n";
 print_node(start);
 cout<<"after reversal :- \n";
 reverse();
 print_node(start);
 getch();
}