//refernce : https://www.youtube.com/watch?v=WlAlxbJy1gk

#include <stdio.h>
#include <math.h>

Bellman_Ford(int k, int* A, int* B, int n){
    int i,j;
    for(i=0;i<n;i++){
        *(B+(k+1)*n+i)=*(B+k*n+i);
        for(j=0;j<n;j++){
            if(*(B+(k+1)*n+i)>*(B+k*n+j)+*(A+*(B+j)*n+*(B+i)))
                *(B+(k+1)*n+i)=*(B+k*n+j)+*(A+*(B+j)*n+*(B+i));
        }
    }
    if(k<n)
        Bellman_Ford(k+1,A,B,n);
}

int main()
{

    int n,i,j,k,a;

    //number of vertices
    printf("Please enter the number of vertices:");
    scanf("%d",&n);

    int A[n][n],B[n+2][n];
    //A - adjancency matrix
    //B - iteration matrix
    //a - source vertex

    //getting the adjacency matrix
    printf("\nPlease enter the value of Adjacency Matrix:\n");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        {
            printf("Please enter the value of A%d%d:",i+1,j+1);
            scanf("%d",&A[i][j]);
        }
    }

    //Printing the adjacency Matrix:
    printf("\nPrinting the adjacency Matrix:\n");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        {
            printf("\t%d",A[i][j]);
        }
    }
    
    //getting the source vertex
    printf("\nPlease enter the Source vertex number:");
    scanf("%d",&a);

    //populating the matrix B
    // It has (n+2) rows and n columns
    // row 1 - vertex numbers
    // row 2 - initialization of the const
    // row 3 to (n+1) - iterations of the relaxation {(n-1) iterations are done}
    // row (n+2) - nth iteration done to check if there is a negative weight cycle present


    B[0][0] = a-1;              //first row, first column
    B[1][0] = 0;                //second row, first column

    for(j = 1; j<n; j++)
    {
        if(j<a-1)
        {
            B[0][j] = j;        //populating the first row
        }
        else
        {
            B[0][j] = j-1;      //populating the first row
        }
    }

    for(j = 1; j<n; j++)
    {
        B[1][j] = 99;           //populating the second row
    }

    Bellman_Ford(1,A,B,n);

    printf("\nThe Recursive Iterations are:");
    for(i=0;i<n+2;i++){
        printf("\n\n");
        for(j=0;j<n;j++){
            printf("\t%d",B[i][j]);
        }
        if(i==1)
            printf("\t#Initialization.");
        else if(i!=0)
            printf("\t#Iteration no. %d",i-1);
    }
    for(i=0;i<n;i++){
        if(B[n+1][i]!=B[n][i]){
            printf("\n WARNING --<ERROR>--!!!: There is a negative edge-cycle in this graph. Correct it and run again.");
            return 0;
        }
    }
    printf("\nThe answer is:\n");
    for(i=1;i<n;i++)
        printf("\nWeight of vertex no.%d is %d",B[0][i]+1,B[n+1][i]);
    return 0;
}