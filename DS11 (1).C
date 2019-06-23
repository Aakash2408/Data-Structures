//Data Structure Program 11
// Double Linked List


#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int n;
    struct node *next;
}*h,*temp,*l,*temp2,*temp4;
int count =0;
void insert1();
void insert2();
void insert3();
void traversebeg();
void traverseend();
void delete();

void deletebeg()
{
if(h==NULL)
{printf("Underflow ");getch();}
{
if(h==l)
{h=NULL;l=NULL;
printf("Deleted");getch();}
else{
struct node* q;
q=h;
h=h->next;
h->prev=NULL;
printf("Deleted \n");free(q);count--;
getch();}} }

void deleteend()
{
if(h==NULL)
{printf("Underflow ");getch();}
else{
if(h==l)
{h=NULL;l=NULL;
printf("Deleted");getch();}
else{struct node* o;
o=l;
l=l->prev;
l->next=NULL;
printf("Deleted \n");free(o);count--;
getch();}}}




void main()
{
    int ch;

    h = NULL;
    temp = l = NULL;
    while(1)
    {           clrscr();
    printf("\n 1 - Insert at beginning");
    printf("\n 2 - Insert at end");
    printf("\n 3 - Insert at position i");
    printf("\n 4 - Delete at i");
    printf("\n 5 - Delete at Beginning");
    printf("\n 6 - Delete at End");
    printf("\n 7 - Display from beginning");
    printf("\n 8 - Display from end");
    printf("\n 9 - Exit");

	printf("\n Enter choice : ");
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:
	    insert1();
	    break;
	case 2:
	    insert2();
	    break;
	case 3:
	    insert3();
	    break;
	case 4:
	    delete();
	    break;
	    case 5:
	    deletebeg();break;
	    case 6:
	    deleteend();break;
	case 7:
	    traversebeg();
	    break;
	case 8:
	   traverseend();	    break;
	     case 9:
	    exit(0);
	default:
	    printf("\n Wrong choice menu");
	}
    }
}

/* TO create an empty node */
void create()
{
    int data;

    temp =(struct node *)malloc(1*sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\n Enter value to node : ");
    scanf("%d", &data);
    temp->n = data;
}

/*  TO insert at beginning */
void insert1()
{
    if (h == NULL)
    {
	create();
	h = temp;
       l = h;
    }
    else
    {
	create();
	temp->next = h;
	h->prev = temp;
	h = temp;
    }    count++;
}

/* To insert at end */
void insert2()
{
    if (h == NULL)
    {
	create();
	h = temp;
       l = h;
    }
    else
    {
	create();
	l->next = temp;
	temp->prev =l;
	l = temp;
    }          count++;
}

/* To insert at any position */
void insert3()
{
    int pos, i = 2;

    printf("\n Enter position to be inserted : ");
    scanf("%d", &pos);
    temp2 = h;

    if ((pos < 1) || (pos >= count + 1))
    {
	printf("\n Position out of range to insert");
	getch();
    }
   else{ if ((h == NULL) && (pos != 1))
    {
	printf("\n Empty list cannot insert other than 1st position");
	getch();
    }
   if ((h == NULL) && (pos == 1))
    {
	create();
	h = temp;
       l = h;
	return;
    }
    else
    {
	while (i < pos)
	{
	    temp2 = temp2->next;
	    i++;
	}
	create();
	temp->prev = temp2;
	temp->next = temp2->next;
	temp2->next->prev = temp;
	temp2->next = temp;
    }}count++;
}

/* To delete an element */
void delete()
{
    int i = 1, pos;

    printf("\n Enter position to be deleted : ");
    scanf("%d", &pos);
    temp2 = h;

    if ((pos < 1) || (pos >= count + 1))
    {
	printf("\n Error : Position out of range to delete");
	getch();
    }
   else  if (h == NULL)
    {
	printf("\n Error : Empty list no elements to delete");
	getch();
    }
    else
    {
	while (i < pos)
	{
	    temp2 = temp2->next;
	    i++;
	}
	if (i == 1)
	{
	    if (temp2->next == NULL)
	    {
		printf("Node deleted from list");
		free(temp2);
		temp2 = h = NULL;
		getch();
	    }
	}
	if (temp2->next == NULL)
	{  temp2->prev->next = NULL;
	    free(temp2);
	    printf("Node deleted from list");
	    getch();

	}
	temp2->next->prev = temp2->prev;
	if (i != 1)
	    temp2->prev->next = temp2->next;
	if (i == 1)
	    h = temp2->next;
	printf("\n Node deleted");
	free(temp2);
    }
    count--; getch();
}

/* Traverse from beginning */
void traversebeg()
{
    temp2 = h;

    if (temp2 == NULL)
    {
	printf("List empty \n");
	getch();
    }
   else{ printf("\n Linked list elements from beginning : ");

    while (temp2->next != NULL)
    {
	printf(" %d  %d  %d     ",temp2->prev, temp2->n,temp2->next);
	temp2 = temp2->next;
    }
	printf(" %d  %d  %d     ",temp2->prev, temp2->n,temp2->next);getch();
}}


void traverseend()
{
    temp2 = l;

    if (temp2 == NULL)
    {
	printf("List empty \n");
	getch();
    }
  else{  printf("\n Linked list elements from end : ");

    while (temp2->prev != NULL)
    {
	printf(" %d %d %d    ",temp2->prev, temp2->n,temp2->next);
	temp2 = temp2->prev;
    }
	printf(" %d  %d  %d     ",temp2->prev, temp2->n,temp2->next);
getch();
} }
