//Data Strcuture program 3
// Static Stacks

 #include<stdio.h>
 #include<stdlib.h>

 int a[5],top;

 void push()
 {int num;
  printf("Enter Number ");
  scanf("%d" , &num);
  if(top==4)
  {printf("Overflow");getch();
   exit(0);}
  top++;
  a[top]=num;
  printf("Added \n");}

  void pop()
  {int num;
  if(top==-1)
    {printf("Underflow");getch();exit(0);}
   num=a[top];
   top--;
   printf("Deleted = %d \n" ,num);}

  void display()
  {int i;
   if(top==-1)
   printf("Stack Empty \n");
  for( i=0;i<=top;i++)
   printf("%d \n",a[i]);}

  void main()
  {
   int op;char ch;
   top=-1;
   while(1){
      printf("1....Push \n");
      printf("2....Pop \n");
      printf("3....Display \n");
      printf("4....Exit \n");
      printf("Enter Choice ");
      scanf("%d",&op);
      switch(op)
      { case 1:push();break;
	case 2:pop();break;
	case 3:display();break;
	case 4:exit(0);break;
	default:printf("Wrong choice \n");break;}
   }   }