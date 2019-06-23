//Data Structure Program 19
// BFS and DFS of BST


#include<stdio.h>
#include<stdlib.h>


void bfs(int v);
void dfs(int v);
int n;int n1;
int adj[100][100];
int state[100];
void create_graph();

int queue[100], front = -1,rear = -1;
int stack[100];int top=-1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();
void push(int vertex);
int pop();
const int white=1,grey=2,black=3;


void main()
{
    int op;
    char ch;
    create_graph();
    printf("\nAdjacency Matrix for Created Graph: \n");
    for(int d=0; d<=n-1; d++)
    {
        for(int y=0; y<=n-1; y++)
            printf("%d ",adj[d][y]);
        printf("\n");
    }
    getch();
    while(1)
    {   system("cls");
        printf("\n1-Breadth First Traversal");
        printf("\n2-Depth First Traversal");
        printf("\n3-Exit");
        printf("\nEnter Choice:");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            {int v;for(int i=0;i<=n-1;i++)
            state[i]=white;
            printf("Enter Start Vertex for DFS: \n");
            scanf("%d",&v);
            bfs(v);
            getch();
            break;
        }
        case 2:{int v;for(int i=0;i<=n-1;i++)
            state[i]=white;
            printf("Enter Start Vertex for DFS: \n");
            scanf("%d",&v);
            dfs(v);
            getch();
            break;
        }
    case 3:exit(0);break;
    default:printf("\nWrong Choice");getch();break;}


}}

void push(int vertex)
{
    top++;
    stack[top]=vertex;
}

int pop()
{
    int g;
    g=stack[top];
    top--;
    return g;
}

void insert_queue(int vertex)
{
    if(rear == 99)
        printf("Queue Overflow\n");
    else
    {
        if(front == -1)
            front = 0;
        rear = rear+1;
        queue[rear] = vertex ;
    }
}

int isEmpty_queue()
{
    if(front == -1 || front > rear)
        return 1;
    else
        return 0;
}

int delete_queue()
{
    int delete_item;
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        exit(1);
    }

    delete_item = queue[front];
    front = front+1;
    return delete_item;
}

void create_graph()
{
    int count,max,or,de;

    printf("Enter number of vertices : ");
    scanf("%d",&n);
    max = n*(n-1);

    for(count=1; count<=max; count++)
    {
        printf("Enter edge %d : ",count);
        scanf("%d %d",&or,&de);

        if((or == -1) && (de == -1))
            break;

        if(or>=n || de>=n || or<0 || de<0)
        {
            printf("Invalid edge!\n");
            count--;
        }
        else
        {
            adj[or][de] = 1;
        }
    }

}

void bfs(int v)
{
    int i;

    insert_queue(v);
    state[v] = grey;

    while(!isEmpty_queue())
    {
        v = delete_queue( );
        printf("%d ",v);
        state[v] = black;

        for(i=0; i<n; i++)
        {
            if(adj[v][i] == 1 && state[i] == white)
            {
                insert_queue(i);
                state[i] = grey;
            }
        }
    }
    printf("\n");
}



void dfs(int v)
{
int i,h;
push(v);
state[v]=grey;
while(top!=-1)
{
h = pop();
printf("%d ",h);
stack[h]=black;

for(i=n;i>=1;i--)
{
if(adj[h][i]==1 && state[i]==white)
{
push(i);
state[i]=grey;
}
}
}}
