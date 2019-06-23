//Data Structure Program 12
// Double Circular Linked List


#include <stdio.h>

#include <stdlib.h>



struct node

{

    int val;

    struct node *next;

    struct node *prev;

};

typedef struct node n;



n* create_node(int);

void insert_at_first();

void insert_at_end();

void insert_at_position();

void delete_node_position();void display_from_beg();

void display_in_rev();

void deletebeg();

void deleteend();



n *new, *ptr, *prev;

n *first = NULL, *last = NULL;

int number = 0;



void main()

{

    int ch;

 while(1)

{clrscr();

    printf("DOUBLE CIRCULAR LINKED LIST  \n");

    printf(" 1.Insert at beginning \n 2.Insert at end\n 3.Insert at position\n 4.Delete node at position\n 5.Delete node at beginning\n 6.Delete node at end\n 7.Display list from beginning\n 8.Display list from end\n 9.Exit ");



	 printf("\n enter your choice:");

	scanf("%d", &ch);

	switch (ch)

	{

	case 1 :

	    insert_at_first();

	    break;

	case 2 :

	    insert_at_end();

            break;

        case 3 :

            insert_at_position();

            break;

        case 4 :

            delete_node_position();

	    break;

	case 5:

	   deletebeg();

	   break;

	case 6:

	  deleteend();

	  break;



	case 7 :

	    display_from_beg();

	    break;

	case 8 :

	    display_in_rev();

	    break;

	case 9 :

	    exit(0);

		default:

	    printf("\ninvalid choice");

	}

    }

}



n* create_node(int info)

{

    number++;

    new = (n *)malloc(sizeof(n));

    new->val = info;

    new->next = NULL;

    new->prev = NULL;

    return new;

}



void insert_at_first()

{



    int info;



    printf("\n Enter value ");

    scanf("%d",&info);

    new = create_node(info);



    if (first == last && first == NULL)

    {



	first = last = new;

	first->next = last->next = NULL;

	first->prev = last->prev = NULL;

    }

    else

    {

	new->next = first;

	first->prev = new;

	first = new;

	first->prev = last;

	last->next = first;



    }

}



void insert_at_end()

{



    int info;



    printf("\n Enter value");

    scanf("%d", &info);

    new = create_node(info);



    if (first == last && first == NULL)

    {



	first = last = new;

	first->next = last->next = NULL;

	first->prev = last->prev = NULL;

    }

    else

    {

	last->next = new;

	new->prev = last;

	last = new;

	first->prev = last;

	last->next = first;

    }

}



void insert_at_position()

{

    int info, pos,  i;

    n *prevnode;



    printf("\n Enter value:");

    scanf("%d", &info);

    printf("\n Enter position");

    scanf("%d", &pos);

    new = create_node(info);



    if (first == last && first == NULL)

    {

	if (pos == 1)

	{

	    first = last = new;

	    first->next = last->next = NULL;

	    first->prev = last->prev = NULL;

	}

	else

	   { printf("\n empty linked list you cannot insert at that particular position");

   getch();} }

    else

    {

	if (number < pos)

	   { printf("\n node cannot  be inserted as position is exceeding the linkedlist length");

	    getch();}

	else

	{

	    for (ptr = first, i = 1;i <= number;i++)

	    {

		prevnode = ptr;

		ptr = ptr->next;

		if (i == pos-1)

		{

		    prevnode->next = new;

		    new->prev = prevnode;

		    new->next = ptr;

		    ptr->prev = new;

				    break;

		}

	    }

	}

    }

}



void delete_node_position()

{

    int pos,  i;

    n *temp, *prevnode;



    printf("\n Enter position");

    scanf("%d", &pos);



    if (last==NULL && first == NULL)

	printf("\n UNDERFLOW");

   else if(first==last)

   {first=NULL;last=NULL;

   printf("Deleted");getch();}

    else

    {

	if (number < pos)

	   { printf("\n node cant be deleted at position as it is exceeding the linkedlist length");

	    getch();}

	else

	{

	    for (ptr = first,i = 1;i <= number;i++)

	    {

		prevnode = ptr;

		ptr = ptr->next;

		if (pos == 1)

		{

		    number--;

		    last->next = prevnode->next;

		    ptr->prev = prevnode->prev;

		    first = ptr;

		    printf("Deleted", prevnode->val);

		    free(prevnode);

		    break;

		}

		else if (i == pos - 1)

		{

		    number--;

		    prevnode->next = ptr->next;

		    ptr->next->prev = prevnode;

		    printf("Deleted", ptr->val);

		    free(ptr);

		    break;

		}

	    }

	}

    }

}



void display_from_beg()

{



    if (last==NULL && first == NULL)

      {	printf("\nlist is empty");

       getch();}

    else if(first==last)

    {printf("%d  %d  %d   ",first->prev,first->val,first->next);getch();}

       else{

       n* y;

       y=first;

       while(y->next!=first)

       {printf("%d  %d  %d   ",y->prev,y->val,y->next);

       y=y->next;}

      printf("%d  %d  %d   ",y->prev,y->val,y->next);getch();}



}



void display_in_rev()

{



    if (last==NULL && first == NULL)

      {	printf("\nlist is empty");

       getch();}

    else if(first==last)

    {printf("%d  %d  %d   ",first->prev,first->val,first->next);getch();}

       else{

       n* y;

       y=last;

       while(y->prev!=last)

       {printf("%d  %d  %d   ",y->prev,y->val,y->next);

       y=y->prev;}

	printf("%d  %d  %d   ",y->prev,y->val,y->next);getch();}



}



void deletebeg()

{ if(first==NULL)

{printf("Underflow");getch();}

else if(first==last)

{ first=NULL;last=NULL;

printf("Deleted");getch();}

else{

n* q;

q=first;

first=first->next;

last->next=first;

first->prev=last;

free(q);number--;

printf("Deleted");getch();}}





void deleteend()

{ if(first==NULL)

{printf("Underflow");getch();}

else if(first==last)

{ first=NULL;last=NULL;

printf("Deleted");getch();}

else{

n* u;

u=last;

last=last->prev;

last->next=first;

first->prev=last;

free(u);number--;

printf("Deleted");getch();}}