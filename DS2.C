//data structure program 2
// Sparse Array
#include<stdio.h>
#include<conio.h>


void main()
{
    system("cls");
    int a[10][10], b[10][3],p,q,r;
    int i,j;
    int z;
    printf("Enter Number of rows and columns \n");
    scanf("%d %d", &p,&q);
    printf("Enter Elements \n");
    z=0;
    for(i=0; i<=p-1; i++)
        for(j=0; j<=q-1; j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]!=0)
                z++;
        }
    if(z>(p*q)/2)
    {
        printf("Array is not Sparse \n");
        getch();
    }
    else
    {
        printf("\n Entered Array is = \n");
        for(i=0; i<=p-1; i++)
        {
            for(j=0; j<=q-1; j++)
            {
                printf("%d", a[i][j]);
                printf("  ");
            }
            printf("\n");
        }

        b[0][0] =p;
        b[0][1]=q;
        b[0][2]=z;
        r=1;
        for(i=0; i<=p-1; i++)
            for(j=0; j<=q-1; j++)
            {
                if(a[i][j]!=0)
                {
                    b[r][0]=i+1;
                    b[r][1]=j+1;
                    b[r][2]=a[i][j];
                    r++;
                }
            }
        printf("Triplet form of given sparse array= \n");
        for(i=0; i<r; i++)
        {
            for(j=0; j<3; j++)
            {
                printf(" %d ", b[i][j]);
                printf(" ");
            }
            printf("\n");
        }
        getch();
    }
}
