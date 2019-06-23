//Data Structure Program 16
// Addition of Polynomials


#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int exp, val;
    struct node *link;
};

struct node *start1;
struct node *start2;
struct node *start3;


void main()
{
    struct node *prev,*q,*r,*s,*p,*ptr;
    int op;
    char ch;
    int loc;
    int num,temp;
    start1=NULL;
    start2=NULL;
    start3=NULL;
    system("cls");

    printf("\nEnter First Polynomial");
    printf("\nEnter Exponent \n");
    start1=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&start1->exp);
    printf("\nEnter Coefficient \n");
    scanf("%d",&start1->val);
    start1->link=NULL;
    prev=start1;
    printf(" \nEnter another term? Y/N");
    fflush(stdin);
    scanf("%c", &ch);
    while(ch=='y'||ch=='Y')
    {
        system("cls");
        s=(struct node*)malloc(sizeof(struct node));
        printf(" \nEnter Exponent");
        scanf("%d",&s->exp);
        printf(" \nEnter Coefficient");
        scanf("%d",&s->val);
        s->link=NULL;
        prev->link=s;
        prev=s;
        printf(" \nEnter another term? Y/N");
        fflush(stdin);
        scanf("%c", &ch);
    }
    system("cls");
    printf("\nEnter Second Polynomial");
    start2=(struct node*)malloc(sizeof(struct node));
    printf(" \nEnter Exponent");
    scanf("%d",&start2->exp);
    printf(" \nEnter Coefficient");
    scanf("%d",&start2->val);
    start2->link=NULL;
    prev=start2;
    printf(" \nEnter another term? Y/N");
    fflush(stdin);
    scanf("%c", &ch);
    while(ch=='y'||ch=='Y')
    {
        system("cls");
        s=(struct node*)malloc(sizeof(struct node));
        printf(" \nEnter Exponent");
        scanf("%d",&s->exp);
        printf(" \nEnter Coefficient");
        scanf("%d",&s->val);
        s->link=NULL;
        prev->link=s;
        prev=s;
        printf(" \nEnter another term? Y/N");
        fflush(stdin);
        scanf("%c", &ch);
    }

    printf(" \nFirst polynomial is \n");
    ptr=start1;
    while(ptr->link!=NULL)
    {
        printf("%dx^%d + ",ptr->val,ptr->exp);
        ptr=ptr->link;
    }
    printf("%dx^%d ",ptr->val,ptr->exp);
    getch();


    printf(" \nSecond Polynomial is \n");
    ptr=start2;
    while(ptr->link!=NULL)
    {
        printf("%dx^%d + ",ptr->val,ptr->exp);
        ptr=ptr->link;
    }
    printf("%dx^%d ",ptr->val,ptr->exp);
    getch();

    p=start1;
    q=start2;
    start3=(struct node*)malloc(sizeof(struct node));
    if(p->exp>q->exp)
    {
        start3->exp=p->exp;
        start3->val=p->val;
        p=p->link;
    }
    else if(p->exp<q->exp)
    {
        start3->exp=q->exp;
        start3->val=q->val;
        q=q->link;
    }
    else
    {
        start3->exp=p->exp;
        start3->val=p->val+q->val;
        p=p->link;
        q=q->link;
    }
    start3->link=NULL;
    prev=start3;


    while(p!=NULL && q!=NULL)
    {
        r=(struct node*)malloc(sizeof(struct node));
        if(p->exp>q->exp)
        {
            r->exp=p->exp;
            r->val=p->val;
            p=p->link;
        }
        else if(p->exp<q->exp)
        {
            r->exp=q->exp;
            r->val=q->val;
            q=q->link;
        }
        else
        {
            r->exp=p->exp;
            r->val=p->val+q->val;
            p=p->link;
            q=q->link;
        }
        r->link=NULL;
        prev->link=r;
        prev=r;
    }

    if(p!=NULL)
    {
        while(p->link!=NULL)
        {
            r=(struct node*)malloc(sizeof(struct node));
            r->exp=p->exp;
            r->val=p->val;
            p=p->link;
            prev->link=r;
            prev=r;
        }
        r=(struct node*)malloc(sizeof(struct node));
        r->exp=p->exp;
        r->val=p->val;
        p=p->link;
        prev->link=r;
        prev=r;
        r->link=NULL;
    }

    if(q!=NULL)
    {
        while(q!=NULL)
        {
            r=(struct node*)malloc(sizeof(struct node));
            r->exp=q->exp;
            r->val=q->val;
            q=q->link;
            prev->link=r;
            prev=r;
        }
        r=(struct node*)malloc(sizeof(struct node));
        r->exp=p->exp;
        r->val=p->val;
        p=p->link;
        prev->link=r;
        prev=r;
        r->link=NULL;
    }

    printf("\n Polynomial after addition is \n");
    ptr=start3;
    while(ptr->link!=NULL)
    {
        printf("%dx^%d + ",ptr->val,ptr->exp);
        ptr=ptr->link;
    }
    printf("%dx^%d ",ptr->val,ptr->exp);
    getch();
}








