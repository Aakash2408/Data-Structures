//Data Structure Program 15
// Sorted Merging of LL


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{int n;
 struct node *link;};
struct node* start1;
struct node* start2;
struct node* start3;
 void main()
{struct node *prev,*q,*r,*s,*p,*ptr;int op;char ch;int loc;int num,temp;
start1=NULL;start2=NULL;start3=NULL;  clrscr();

printf("\nEnter First Linked list");
printf("\nEnter Node \n");
start1=(struct node*)malloc(sizeof(struct node));
scanf("%d",&start1->n);
start1->link=NULL;
prev=start1;
printf(" \nEnter another node? Y/N");fflush(stdin);
scanf("%c", &ch);
while(ch=='y'||ch=='Y')
{clrscr();
s=(struct node*)malloc(sizeof(struct node));
 printf(" \nEnter Node");
 scanf("%d",&s->n);
 s->link=NULL;
 prev->link=s;
 prev=s;
 printf(" \nEnter another node? Y/N");fflush(stdin);scanf("%c", &ch);}
clrscr();
 printf("\nEnter Second Linked List");
printf("\nEnter Node \n");
start2=(struct node*)malloc(sizeof(struct node));
scanf("%d",&start2->n);
start2->link=NULL;
prev=start2;
printf(" \nEnter another node? Y/N");fflush(stdin);
scanf("%c", &ch);
while(ch=='y'||ch=='Y')
{clrscr();
s=(struct node*)malloc(sizeof(struct node));
 printf(" \nEnter Node");
 scanf("%d",&s->n);
 s->link=NULL;
 prev->link=s;
 prev=s;
 printf(" \nEnter another node? Y/N");fflush(stdin);scanf("%c", &ch);}

printf(" \nFirst linked list is \n");
ptr=start1;
while(ptr!=NULL)
{printf(" %d ",ptr->n);
 ptr=ptr->link;}
 getch();


printf(" \nSecond linked list is \n");
ptr=start2;
while(ptr!=NULL)
{printf(" %d ",ptr->n);
 ptr=ptr->link;}
 getch();

	 p=start1;
	 q=start1->link;
	 while(p->link!=NULL)
	 { while(q!=NULL)
	 {if(p->n>q->n)
	   {temp=p->n;
	    p->n=q->n;
	    q->n=temp;}
	    q=q->link;}
	 p=p->link;
	 q=p->link;}

	 printf(" \nFirst linked list after sorting is \n");
	ptr=start1;
	 while(ptr!=NULL)
	{printf(" %d ",ptr->n);
	 ptr=ptr->link;}
	 getch();

	 p=start2;
	 q=start2->link;
	 while(p->link!=NULL)
	 { while(q!=NULL)
	 {if(p->n>q->n)
	   {temp=p->n;
	    p->n=q->n;
	    q->n=temp;}
	    q=q->link;}
	 p=p->link;
	 q=p->link;}

	 printf(" \nSecond linked list after sorting is \n");
	ptr=start2;
	 while(ptr!=NULL)
	{printf(" %d ",ptr->n);
	 ptr=ptr->link;}
	 getch();

       p=start1;
       q=start2;
	if(p->n<=q->n)
	{r=p;
	 p=p->link;}
	 else
	 {r=q;
	 q=q->link;}
	start3=r;
       while(p!=NULL && q!=NULL)
	{ if(p->n<=q->n)
	 { r->link=p;r=p;
	   p=p->link;}
	   else
	   {r->link=q;r=q;
	    q=q->link;}}

	if(p!=NULL)
	 while(p!=NULL)
	 { r->link=p;r=p;
	   p=p->link;}
	else if(q!=NULL)
	while(q!=NULL)
	{r->link=q;r=q;
	q=q->link;}


	printf(" \nNew linked list after sorted merging is  \n");
	ptr=start3;
	 while(ptr!=NULL)
	{printf(" %d ",ptr->n);
	 ptr=ptr->link;}
	 getch();}






























