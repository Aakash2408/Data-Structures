//Data Structure Program 14
// Linear Search and Selection Sort on LL


#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{int n;
struct node* link;};

struct node* start;

void main()
{struct node *prev,*q,*r,*s,*p,*ptr;int op;char ch;int loc;int num,temp;
start=NULL;  clrscr();
printf("Enter Node \n");
start=(struct node*)malloc(sizeof(struct node));
scanf("%d",&start->n);
start->link=NULL;
prev=start;
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

printf(" \nEntered linked list is \n");
ptr=start;
while(ptr!=NULL)
{printf(" %d ",ptr->n);
 ptr=ptr->link;}
 getch();

while(1)
{clrscr();
 printf("\n1...Search");
 printf("\n2...Sort");
 printf("\n3...Exit");
 printf("\nEnter Choice");
 scanf("%d",&op);

 switch(op)
 {case 1:printf("\nEnter Number to be searched-");
	 scanf("%d",&num);
	 if(start->n==num)
	 {printf("\nFound at position 1");getch();}
	 else
	 {ptr=start;loc=0;
	  while(ptr!=NULL && ptr->n!=num)
	   {ptr=ptr->link;
	    loc++;}
	  if(ptr->n==num)
	  {printf("\nFound at pos %d",loc+1);getch();}
	  else
	  {printf("\nNot Found!!");getch();}
	   break;
  case 2:p=start;
	 q=start->link;
	 while(p->link!=NULL)
	 { while(q!=NULL)
	 {if(p->n>q->n)
	   {temp=p->n;
	    p->n=q->n;
	    q->n=temp;}
	    q=q->link;}
	 p=p->link;
	 q=p->link;}

	 printf(" \nSorted linked list is \n");
	ptr=start;
	 while(ptr!=NULL)
	{printf(" %d ",ptr->n);
	 ptr=ptr->link;}
	 getch();break;
  case 3:exit(0);break;
  default: printf("\nWrong Choice!!");getch();break;}
}}}




















