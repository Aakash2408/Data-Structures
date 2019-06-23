//Data Structure Program 10
// Dynamic Stacks and Queues


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *ptr;
}*top,*top1,*temp,*front,*rear,*front1;


void push(int data)
{
    if (top == NULL)
    {
	top =(struct node *)malloc(1*sizeof(struct node));
	top->ptr = NULL;
	top->info = data;
    }
    else
    {
	temp =(struct node *)malloc(1*sizeof(struct node));
	temp->ptr = top;
	temp->info = data;
	top = temp;
    }

}

void display()
{
    top1 = top;

    if (top1 == NULL)
    {
	printf("Stack Empty");
	getch();
    }

    while (top1 != NULL)
    {
	printf("%d ", top1->info);
	top1 = top1->ptr;
    }getch();
 }
 void pop()
{
    top1 = top;

    if (top1 == NULL)
    {
	printf("\n Error : Trying to pop from empty stack");
	getch();
    }
    else
       {	top1 = top1->ptr;
    printf("\n Popped value : %d", top->info);
    free(top);
    top = top1;
	     getch();
} }


void enq(int data)
{
    if (rear == NULL)
    {
	rear = (struct node *)malloc(1*sizeof(struct node));
	rear->ptr = NULL;
	rear->info = data;
	front = rear;
    }
    else
    {
	temp=(struct node *)malloc(1*sizeof(struct node));
	rear->ptr = temp;
	temp->info = data;
	temp->ptr = NULL;

	rear = temp;
    }
}



void deq()
{
    front1 = front;

    if (front1 == NULL)
    {
	printf("\n Error: Trying to delete elements from empty queue");
       getch();
    }
    else
	if (front1->ptr != NULL)
	{
	    front1 = front1->ptr;
	    printf("\n Dequed value : %d", front->info);
	    free(front);
	    front = front1;
	}
	else
	{
	    printf("\n Dequed value : %d", front->info);
	    free(front);
	    front = NULL;
	    rear = NULL;
	}       getch();
 }

void display1()
{
    front1 = front;

    if ((front1 == NULL) && (rear == NULL))
    {
	printf("Queue is empty");
	getch();
    }
   else{ while (front1 != rear)
    {
	printf("%d ", front1->info);
	front1 = front1->ptr;
    }
    if (front1 == rear)
	printf("%d", front1->info);
	getch();
}}

void main()
{
    int no, ch, e,m;
top=NULL;
    while(1){
    clrscr();

    printf("\n1-Stacks ");
    printf("\n2-Queues");
    printf("\n3-Exit");
    printf("\nEnter Choice");
    scanf("%d",&m);
    switch(m)
   {case 1:{int kk=1;
	    while(kk)
	    {
    printf("\n 1 - Push");
    printf("\n 2 - Pop");
    printf("\n 3 - Display");
    printf("\n 4 - Exit");
    printf("\n Enter choice : ");
	scanf("%d", &ch);

	switch (ch)
	{
	case 1:
	    printf("Enter data : ");
	    scanf("%d", &no);
	    push(no);
	    break;
	case 2:
	    pop();
	    break;
	case 3:
	    display();
	    break;
       case 4:kk=0; ;break;
	default :
	    printf(" Wrong choice, Please enter correct choice  ");
	    break;
	}} break;
    case 2:
{ int kk=1; while(kk){
    printf("\n 1 - Enque");
    printf("\n 2 - Deque");
    printf("\n 3 - Display");
    printf("\n 4 - Exit");


	printf("\n Enter choice : ");
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:
	    printf("Enter data : ");
	    scanf("%d", &no);
	    enq(no);
	    break;
	case 2:
	    deq();
	    break;
  case 3:
	    display1();
	    break;
	case 4:
	    kk=0;
	    break;
	default:
	    printf("Wrong choice, Please enter correct choice  ");
	    break;
	}
    }
} break;
case 3:exit(0);
default:printf("\nWrong choice");getch();break;
}}}}


