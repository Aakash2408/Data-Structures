//Data Structure Program 13
//Count Nodes and Reverse Linked List

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
 int n;
 struct node *link;
}*start;

void main()
{ 
 struct node *prev,*q,*r,*s,*p,*ptr;int c=1;char ch;
 start=NULL;
 clrscr();
 printf("Enter Node \n");
 start=(struct node*)malloc(sizeof(struct node));
 scanf("%d",&start->n);
 start->link=NULL;
 prev=start;
 printf("\n Enter another node? Y/N : ");fflush(stdin);
 scanf("%c", &ch);
 while(ch=='y'||ch=='Y')
 {
  clrscr();
  s=(struct node*)malloc(sizeof(struct node));
  printf("\n Enter Node");
  scanf("%d",&s->n);
  s->link=NULL;
  prev->link=s;
  prev=s;
  c++;
  printf(" \nEnter another node? Y/N");fflush(stdin);scanf("%c", &ch);
 }

 printf("\n No. of nodes=%d",c);
 printf("\n Entered linked list is \n");
 ptr=start;
 while(ptr!=NULL)
 {
  printf("\t%d",ptr->n);
  ptr=ptr->link;
 }
 getch();
 r=NULL;
 p=start;
 while(p!=NULL)
 {
  q=p->link;
  p->link=r;
  r=p;
  p=q;
  start=r;
 }
 printf("\nReversed linked list =\n");
 ptr=start;
 while(ptr!=NULL)
 {
  printf(" %d ",ptr->n);
  ptr=ptr->link;
 }
 getch();
 }
