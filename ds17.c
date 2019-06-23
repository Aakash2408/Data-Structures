//Data Structure Program 17
// Operations on Binary search tree


#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct tree
{int n;
 struct tree *left,*right;};

struct tree *root,*q,*p;
void create();
//struct tree* deletetree(struct tree* u,int key);
// struct tree *minval(struct tree* q);
 void preorder(struct tree *t)
 { if(root==NULL)
   {printf("No Elements in Tree");getch();}
   else
   {printf("%d ",t->n);
    if(t->left!=NULL)
     preorder(t->left);
     if(t->right!=NULL)
     preorder(t->right);}}

 void inorder(struct tree *t)
 {if(root==NULL)
   {printf("No Elements in Tree");getch();}
  if(t->left!=NULL)
   inorder(t->left);
   printf("%d ",t->n);
   if(t->right!=NULL)
   inorder(t->right);}

void postorder(struct tree *t)
{if(root==NULL)
   {printf("No Elements in Tree");getch();}
  if(t->left!=NULL)
  postorder(t->left);
  if(t->right!=NULL)
  postorder(t->right);
  printf("%d ",t->n);}

void deletetree(struct tree*p,struct tree*q);

void main()
{ struct tree *ptr,*prev;char ch;int op,num,a,num1,num2,m;

 while(1)
 {
     printf("\n1-Enter Element");
 printf("\n2-Go to Main Menu");
 scanf("%d",&m);
 if(m==1)
 create();
 else
    break;
 }
/* while(p!=NULL)
 {printf("%d",p->n);
  p=p->right;}getch();}*/

while(1)
{system("cls");p=root;
 printf("\n1-Insertion");
 printf("\n2-Search");
 printf("\n3-Deletion");
 printf("\n4-Traversal");
 printf("\n5-Exit");
 printf("\nEnter Choice ");
 scanf("%d",&op);
 switch(op)
 {case 1: {struct tree *parent,*current;
      ptr=(struct tree*)malloc(sizeof(struct tree));
	 printf("\nEnter Value to be Inserted ");
	 scanf("%d",&ptr->n);ptr->left=NULL;ptr->right=NULL;
	 if(root==NULL)
    root=ptr;
    else
    {
        current=root;
        while(current)
        {
            parent=current;
            if(ptr->n>current->n)
                current=current->right;
            else
                current=current->left;
        }
         if(ptr->n >= parent->n)
            parent->right=ptr;
        else
            parent->left=ptr;
    }

	printf("\nInserted");getch();break;}

case 2:printf("\nEnter Value for Searching");
       scanf("%d",&num);
	while(p!=NULL && p->n!=num)
	{
	if(num<p->n)
	{p=p->left;}

	else{p=p->right;}}
	if(p==NULL)
	{printf("\nElement Not Found");getch();}
	else
	{printf("\nElement found");getch();}
	p=root;break;

 case 3:/*printf("\nEnter Value for Deletion");
       scanf("%d",&num1);
       prev=deletetree(root,num1);
	printf("\nDeleted value %d ",prev->n);getch();
	    break;*/
	 printf("\nEnter Value for DELETION");
       scanf("%d",&num2);
	while(p!=NULL && p->n!=num2)
	{
	if(num2<p->n)
	{q=p;p=p->left;}
	else{q=p; p=p->right;}}
	if(p==NULL)

    {printf("\nNot Found");getch();}

	else {deletetree(p,q);printf("DELETED");getch();}
	break;


  case 4:
	 printf("\n1-PreOrder");
	 printf("\n2-InOrder");
	 printf("\n3-PostOrder");
	 printf("\nEnter Choice");
	 scanf("%d",&a);
	 switch(a)
	 {case 1:preorder(root);getch();break;
	  case 2:inorder(root);getch();break;
	  case 3:postorder(root);getch();break;
	  default:printf("\nWrong Choice");getch();break;}break;



  case 5:exit(0);
  default:printf("\nWrong Choice");getch();break;}}}


 void deletetree(struct tree*p,struct tree*q)
 {int temp;struct tree *u,*v;
  if(root==NULL)
   {printf("TREE EMPTY");getch();}
   else
  { if(p->right==NULL && p->left==NULL)
   { if(p->n<q->n) q->left=NULL;
    else{ q->right=NULL;}
    free(p);}
   else if(p->left!=NULL && p->right==NULL)
    {if(p->n<q->n) q->left=p->left;
     else{q->right=p->left;}free(p);}
    else if(p->left==NULL && p->right!=NULL)
    {if(p->n<q->n) q->left=p->right;
     else{q->right=p->right;}free(p);}
   else
     { u=p;
       while(u->right!=NULL )
       u=u->right;
       temp=u->n;
       u->n=p->n;
       p->n=temp;

       if(u->left==NULL && u->right==NULL)
	{v=p;
	 while(v->right->n!=u->n)
	  v=v->right;
	  v->right=NULL;free(u);}
	 else if(u->left!=NULL && u->right==NULL)
	  {v=u;
	   while(v->left!=NULL)
	   v=v->left;
	   temp=u->n;
	   u->n=v->n;
	   v->n=temp;
	   q=u;
	   while(q->left->n!=v->n)
	    q=q->left;
	    q->left=NULL;
	    free(v);}} }}


void create()
{
    struct tree *ptr,*current,*parent;
    ptr=(struct tree *)malloc(sizeof(struct tree));
    ptr->right=ptr->left=NULL;
    printf("Enter Value\n");
    scanf("%d",&ptr->n);
    if(root==NULL)
    root=ptr;
    else
    {
        current=root;
        while(current)
        {
            parent=current;
            if(ptr->n>current->n)
                current=current->right;
            else
                current=current->left;
        }
         if(ptr->n >= parent->n)
            parent->right=ptr;
        else
            parent->left=ptr;
    }
}
