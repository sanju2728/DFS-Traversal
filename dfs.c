//Program to find the Depth First Search (DFS) traversal of a graph by entering its adjacency matrix
//By Sanjana Bhat
#include<stdio.h>
#include<stdlib.h>

int top=0,stack[100], visited[100], n, i, j, a[100][100], v;
void push(int a)
{
    top=top+1;
    stack[top]=a;
}
void pop()
{
    
    top=top-1;
}
void dfs(int v)
{
    
        for(j=1;j<=n;j++)
        {
            if(j==(n+1))
                goto label;
            if((a[v][j]==1)&&(visited[j]==0))
            {
                printf("%d", j);
                visited[j]=1;
                push(j);
                dfs(j);
            }
            else if(((a[v][j]==1)&&(visited[j]==1))||(a[v][j]==0))
            {
               
               continue;
            }
            label:
                pop();
               dfs(stack[top]);
            
            
               
            
        }
    
}

void main()
{
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%d", &a[i][j]);
    }
    for(int k=1;k<=n;k++)
        visited[k]=0;
    printf("Enter the source vertex: ");
    scanf("%d", &v);
    printf("%d", v);
    visited[v]=1;
    stack[top++]=v;
    dfs(v);
}
    