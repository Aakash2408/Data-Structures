//Data Structure Program 18
// Traversal of BST using stacks


#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int n;
 struct tree *left,*right;
 };

struct tree *root=NULL;

struct tree *a[99];
int top=-1;

void push(struct tree *o)
{
    top++;
    a[top]=o;
}

struct tree *pop()
{
struct tree *k;
 k=a[top];
 top--;
 return k;
 }

void preorder();
void inorder();
void postorder();
void create();
void main()
{
    int opt,op;
    while(1){
printf("1.Enter Element\n2.Go to Traversal Menu\n");
scanf("%d",&opt);
if(opt==1)
    create();
else
    break;
    }

  while(1)
  {printf("\n1-Pre Order Traversal");
   printf("\n2-In Order Traversal");
   printf("\n3-Post Order Traversal");
   printf("\n4-Exit");
   printf("\nEnter Choice");fflush(stdin);
   scanf("%d",&op);
   switch(op)
   {case 1:preorder();getch();break;
    case 2:inorder();getch();break;
    case 3:postorder();getch();break;
    case 4:exit(0);break;

    default:printf("\nWrong Choice");getch();break;}}}


   void preorder()
    {
        struct tree *pt;
     top=-1;pt=root;

     while(pt)
       {while(pt!=NULL)
         {printf("%d ",pt->n);
          if(pt->right!=NULL)
          push(pt->right);
           pt=pt->left;}
           pt=pop();} }

  void inorder()
   {
       struct tree *pt;
     top=-1;pt=root;

      while(pt)
       { while(pt!=NULL)
        {push(pt);
         pt=pt->left;}
         pt=pop();
          while(pt)
           {printf("%d ",pt->n);
            if(pt->right!=NULL)
             {pt=pt->right;break;}
             else
            pt=pop();
             }
             }
     }


 void postorder()
  { struct tree *useless,*pt;
   top=-1;pt=root;
   do{
      while(pt!=NULL)
       {if(pt->right!=NULL)
         push(pt->right);
         push(pt);
         pt=pt->left;}
      pt=pop();
      if(pt->right!=NULL && pt->right==a[top])
        {
            useless=pop();
         push(pt);
         pt=pt->right;}
        else
         { printf("%d ",pt->n);

         pt=NULL;

         }

         }while(top!=-1);
         }
void create()
{
    struct tree *ptr,*curr,*par;
    ptr=(struct tree *)malloc(sizeof(struct tree));
    ptr->right=NULL;ptr->left=NULL;
    printf("Enter Value\n");
    scanf("%d",&ptr->n);ptr->left=NULL;ptr->right=NULL;
    if(root==NULL)
    root=ptr;
    else
    {
        curr=root;
        while(curr)
        {
            par=curr;
            if(ptr->n>curr->n)
                curr=curr->right;
            else
                curr=curr->left;
        }
         if(ptr->n >= par->n)
            par->right=ptr;
        else
            par->left=ptr;
    }
}
