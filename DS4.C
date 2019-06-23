#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int a[20], F , R;

void insert()
{int num; 
if ((F==0 && R==19) || (F==R+1))
  { printf("Overflow!!! \n");
    getch();
    exit(0); }

printf("Enter Number for Insertion \n");
  scanf("%d" ,&num);

  if (R==-1)
  { R++; F++; }

  else if (R==19)
    R = 0;

  else
    R++;

  a[R] = num;
  printf("Added! \n");
  getch();
  }

void Delete()
{ int num;
if (F==-1)
  { printf("Underflow");
    getch();
    exit(0); }

   num = a[F];

  if (F==R)
  { F=R=-1; }

  else if (F==19)
    F = 0;

  else
    F++;

printf("Deleted number is %d \n", num);
  getch();
  }

void display()
{int i,j;
 if (F==-1)
printf("Underflow!!!  \n");
  else if (F==R)
 printf("%d" ,a[F]);

  else if (R>F)
  for ( i=F; i<=R; i++)
  printf("%d \n",a[i]);

  else
  for ( j=F; j<=19; j++)
 printf("%d \n", a[j]);

  getch();
  }

void main()
{char ch;int op;

F=-1;
  R=-1;


  do { clrscr();
       printf("Insert.....1 \n");
       printf("Delete.....2 \n");
       printf("Display....3 \n");
       printf("Enter Choice");
       scanf("%d",&op);

       switch(op)
       { case 1 : insert();
		  break;

	 case 2 : Delete();
		  break;

	 case 3 : display();
		  break;

	 default: printf("Invalid Choice \n");
	 }

	 printf("Return to Main Menu? \n");fflush(stdin);
	 scanf("%c", &ch); } while (ch=='y' || ch=='Y');

	 getch();
	 }