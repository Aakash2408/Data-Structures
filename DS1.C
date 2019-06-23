//Data Structure Program 1
// Arrays


#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

void main();
{
    int a[10],n;
    int i,j,op;
    char ch;
    ch='y';
    printf("Enter Size of Array");
    scanf("%d", &n);

    printf("Enter Array \n");
    for( i=0; i<=n-1; i++)
        scanf("%d", &a[i]);


    while(1)
    {
        printf("1...Traverse \n");
        printf("2....Insert \n");
        printf("3...Delete \n");
        printf("4...Search \n");
        printf("5...Sort \n");
        printf("6...Exit \n");
        printf("Enter Choice \n" );
        scanf("%d",&op) ;

        switch(op)
        {
        case 1:
            for(j=0; j<=n-1; j++)
            {
                printf("%d", a[j]);
            }
            printf("\n");
            getch();
            break;



        case 2:
        {
            int op1;
            int k,b;
            printf("1...Insert at beginning \n");
            printf("2...Insert at a user entered location \n");
            printf("3...Insert at end \n");
            printf("Enter Choice \n");
            scanf("%d", &op1);

            switch(op1)
            {
            case 1:
                printf("Enter value to be inserted \n");
                scanf("%d", &b);
                for(  j=n-1; j>=0; j--)
                    a[j+1]=a[j];
                a[0]=b;
                n++;
                printf("New Array =  ");
                for(j=0; j<=n-1; j++)
                {
                    printf("%d",a[j] );
                    printf(" \n");
                }
                getch();
                break;
            case 2:
                printf("Enter Location \n");
                scanf("%d", &k);
                printf("Enter Value \n");
                scanf("%d",&b);
                k--;
                for(j=n-1; j>=k; j--)
                    a[j+1]=a[j];
                a[k]=b;
                n++;
                printf("New Array =  ");
                for(j=0; j<=n-1; j++)
                {
                    printf("%d",a[j] );
                    printf(" \n");
                }
                getch();
                break;

            case 3:
                printf("Enter Value \n");
                scanf("%d",&b);
                a[n]=b;
                n++;
                printf("New Array =  ");
                for(j=0; j<=n-1; j++)
                {
                    printf("%d",a[j] );
                    printf(" \n");
                }
                getch();
                break;
            }
            break;
        }

        case 3:
        {
            int ch2;
            printf("\n1.At beginning");

            printf("\n2.At desired position");

            printf("\n3.At end");

            printf("\nEnter your choice : ");

            scanf("%d",&ch2);
            switch(ch2)

            {

            case 1:

            {

                for(i=0; i<n; i++)

                    a[i]=a[i+1];

                n--;

                printf("new array:\t");

                for(i=0; i<n; i++)

                {
                    printf("%d ",a[i]);

                    printf("\n");
                }
                getch();
                break;

            }

            case 2:

            {
                int pos;
                printf("Enter the postion from which the element is to be deleted : ");

                scanf("%d",&pos);

                pos--;

                for(i=pos; i<n; i++)

                    a[i]=a[i+1];

                n--;

                printf("UPDATED ARRAY :\t");

                for(i=0; i<n; i++)

                {
                    printf("%d ",a[i]);

                    printf("\n");
                }
                getch();
                break;

            }

            case 3:

            {

                n--;

                printf("UPDATED ARRAY :\t");

                for(i=0; i<n; i++)

                {
                    printf("%d ",a[i]);

                    printf("\n");
                }
                getch();
                break;

            }


            }
            break;

        }


        case 4:
        {
            int k=-1;
            int l;
            printf("Enter Value to be searched \n");
            scanf("%d", &l);
            j=0;
            while(j<=n-1 && k==-1)
            {
                if(a[j]==l)
                    k=j;
                else
                    j++;
            }
            if(k==-1)
                printf("Not found \n");
            else
                printf("Found at %d position \n",++k);
            getch();
            break;
        }


        case 5:
        {
            int u;
            for(i=0; i<=n-2; i++)
            {
                for(j=i+1; j<=n-1; j++)
                    if(a[i]>a[j])
                    {
                        u=a[i];
                        a[i]=a[j];
                        a[j]=u;
                    }
            }
            printf("Sorted Array =  ");
            for(j=0; j<=n-1; j++)
            {
                printf("%d",a[j] );
                printf(" \n");
            }
            getch();


            break;
        }
        case 6:
            exit(0);
            break;
        default:
            printf("Wrong choice");
            getch();
            break;
        }
    }

}
