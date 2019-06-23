//Data Structure Program 20
// Various sorting techniques


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


int a[20],n;

void create();
void display();
void bubblesort();
void insertionsort();
void quicksort(int number[20],int first,int last);
void heapup(int n,int i);
void heapsort();
void merge(int a[],int f1,int l1,int f2,int l2);
void mergesort(int a[],int i,int j);
void shellsort(int arr[], int num);
void main()
{
    int op;
    char ch;
    while(1)
    {
        system("cls");
        printf("\n1-Enter Array");
        printf("\n2-Bubble Sort");
        printf("\n3-Insertion Sort");
        printf("\n4-Quick Sort");
        printf("\n5-Heap Sort");
        printf("\n6-Merge Sort");
        printf("\n7-Shell Sort");
        printf("\n8-Exit");
        printf("\nEnter Choice");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            create();
            break;
        case 2:
            bubblesort();
            display();
            getch();
            break;
        case 3:
            insertionsort();
            display();
            getch();
            break;
        case 4:
            quicksort(a,0,n-1);
            display();
            getch();
            break;
        case 5:
            heapsort();
            display();
            getch();
            break;
        case 6:
            mergesort(a,0,n-1);
            display();
            getch();
            break;
        case 7:
            shellsort(a,n);
            display();
            getch();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("\nWrong Choice");
            break;
        }
    }
}


void create()
{

    printf("\nEnter Number of Elements:");
    scanf("%d",&n);
    printf("\nEnter Elements of Array:\n");
    for(int i=0; i<=n-1; i++)
        scanf("%d",&a[i]);
    printf("\nEntered Array is:");
    for(int i=0; i<=n-1; i++)
        printf("%d ",a[i]);
    getch();
}

void display()
{
    printf("\nSorted Array is:");
    for(int i=0; i<=n-1; i++)
        printf("%d ",a[i]);
}

void bubblesort()
{
    int temp;
    for(int i=0; i<=n-2; i++)
    {
        for(int j=0; j<=n-2-i; j++)
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
    }

}

void insertionsort()
{
    int temp,j;
    for(int i=1; i<=n-1; i++)
    {
        j=i-1;
        temp=a[i];
        while(j>=0 && temp<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }

}



void quicksort(int number[25],int first,int last)
{
    int i, j, pivot, temp;

    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;

        while(i<j)
        {
            while(number[i]<=number[pivot]&&i<last)
                i++;
            while(number[j]>number[pivot])
                j--;
            if(i<j)
            {
                temp=number[i];
                number[i]=number[j];
                number[j]=temp;
            }
        }

        temp=number[pivot];
        number[pivot]=number[j];
        number[j]=temp;
        quicksort(number,first,j-1);
        quicksort(number,j+1,last);

    }
}


void heapup(int n, int i)
{
    int temp,largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;


    if (l < n && a[l] > a[largest])
        largest = l;


    if (r < n && a[r] > a[largest])
        largest = r;


    if (largest != i)
    {
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;



        heapup( n, largest);
    }
}


void heapsort()
{
    int temp;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapup(n, i);



    for (int i=n-1; i>=0; i--)
    {

        temp=a[0];
        a[0]=a[i];
        a[i]=temp;


        heapup( i, 0);
    }
}

void mergesort(int a[],int i,int j)
{
    int mid;

    if(i<j)
    {
        mid=(i+j)/2;
        mergesort(a,i,mid);
        mergesort(a,mid+1,j);
        merge(a,i,mid,mid+1,j);
    }
}

void merge(int a[],int f1,int l1,int f2,int l2)
{
    int temp[50];
    int i,j,k;
    i=f1;
    j=f2;
    k=0;

    while(i<=l1 && j<=l2)
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }

    while(i<=l1)
        temp[k++]=a[i++];

    while(j<=l2)
        temp[k++]=a[j++];
    for(i=f1,j=0; i<=l2; i++,j++)
        a[i]=temp[j];
}

void shellsort(int arr[], int num)
{
    int i, j, k, tmp;
    for (i = num / 2; i > 0; i = i / 2)
    {
        for (j = i; j < num; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if (arr[k+i] >= arr[k])
                    break;
                else
                {
                    tmp = arr[k];
                    arr[k] = arr[k+i];
                    arr[k+i] = tmp;
                }
            }
        }
    }
}
