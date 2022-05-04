#include <stdio.h>
#define INFINITY 99
#define MAX 10
#define startnode 0

void dijkstra(int cost[MAX][MAX], int n)
{
    int distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;
    
    for(i = 0; i<n ; i++)
    {
        for(j = 0; j<n; j++)
        {
            if(cost[i][j] == 0)
            {
                cost[i][j]= INFINITY;
            }
        }
    }
    
    for(i = 0; i<n; i++)
    {
        distance[i] = cost[startnode][i];       //0th row and ith column
        pred[i] = startnode ;
        visited[i] = 0;
    }
    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;

    while(count < n-1)
    {
        mindistance = INFINITY;
        for( i = 0; i<n; i++)
        {
            if(distance[i] < mindistance&&!visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }
        }
    }

    visited[nextnode] = 1;
    if(!visited[i])
    {
        if(mindistance + cost[nextnode][i] < distance[i])
        {
            distance[i] = mindistance + cost[nextnode][i];
            pred[i] = nextnode;
        }
        count++;
    }

    for (i = 0; i<n; i++)
    {
        if(i != startnode)
        {
            printf("\n Distance of node %d = %d \n", i , distance[i]);
            printf("Path = %d", i);
            j=i;
            do
            {
                j = pred[j];
                printf("<-- %d", i);
            } while(j!=startnode);
        }
    }
}

int main()
{
    int cost[MAX][MAX], i, j, n, u;

    // cost[MAX][MAX] - cost matrix
    // i, j - counter variables
    // n - number of vertices
    // u - 

    printf("enter the number of vertices: \n");
    scanf("%d", &n);

    //taking input for cost matrix
    printf("enter the cost matrix: \n");
    for(i = 0; i<n ; i++)
    {
        for(j = 0; j<n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    //printing the cost matrix
    for(i = 0; i<n ; i++)
    {
        for(j = 0; j<n; j++)
        {
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    }
    dijkstra(cost, n);

    return 0;
}

