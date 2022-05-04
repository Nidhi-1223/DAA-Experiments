#include<stdio.h>
#include<stdlib.h>
int a[10][10], d[10][10], n; //n is the no of vertices, a is for cost matrix and d for distance matrix
int min(int a, int b)
{
    return(a<b)? a:b; //to find minimum of 2 nos
}

void path() //calculate distance matrix
{
    int i,j,k;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                d[i][j]=min(d[i][j], d[i][k]+ d[k][j]);
            }
        }
    }
}
int main() //calculate cost matrix
{
    int i,j;
    printf("\n enter number of vertices n:");
    scanf("%d",&n);
    printf("\n enter the cost matrix:");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            d[i][j]=a[i][j]; //initial distance matrix will be same
        }
        path();
        printf("\n The final distance matrix:");
        for(i=0;i<n;i++)
        {
        for(j=0;j<n;j++)
        {
            printf(" %d", d[i][j]);
        }
            printf("\n");
        }
return 0;
}