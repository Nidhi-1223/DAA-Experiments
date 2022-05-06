#include<stdio.h>
#include<string.h>

char x[100],y[100],b[100][100];
int i,j,m,n,a,c[100][100];

void print(int i,int j)
{
    if(i==0 || j==0)
        return;
    if(b[i][j]=='c')
    {
        print(i-1,j-1);
        printf("%c",x[i-1]);
    }
    else if(b[i][j]=='u')
        print(i-1,j);
    else
        print(i,j-1);
}

void lcs_length()
{
	m=strlen(x);
	printf("For String %s X is length %d\n",x,m);

	n=strlen(y);
	printf("For String %s Y is Length %d\n",y,n);
	for(i=0;i<=m;i++)
		c[i][0]=0;      //initializing first row as 0
	for(j=0;j<=n;j++)
		c[0][j]=0;      //initializing first column as 0
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i-1]==y[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]='c';// direction arrow
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]='u';//  upper arrow
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]='l';//__ left side arrow
			}
			
			//printf("String X[i-1] is %c and Y[i-1] is %c\n",x[i-1],y[i-1]);

		}
	}
	// for(i=0;i<=n;i++)
	// {
	// 	for(j=0;j<=m;j++)
	// 	{
	// 		printf("%d  ",c[j][i]);
	// 	}
	// 	printf("\n");
	// }
	// printf("%d", c[n][m]);
    printf("\n Longest Common Subsequence is:\n");
    print(m,n);
    printf("\n");
}

int main()
{
	printf("Welcome to the LCS Implementation in C");
	printf("\n Enter 1st Sequence \n");
	scanf("%s", x);
	printf("\nEnter the 2nd Sequence \n");
	scanf("%s", y);
	lcs_length();

	return 0;

}