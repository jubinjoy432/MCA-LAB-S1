/* Program to Perform multiplication of two matrices
   @Jubin Joy 25/07/2025 */

#include <stdio.h>

void read(int m[][10],int r,int c) // function to input elements of the matrix
{ 
    int i,j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&m[i][j]);
}

void display(int m[][10],int r,int c) // funtion to display the elements of the matrix
{ 
    int i,j;
    for(i=0;i<r;i++)
	{
        for(j=0;j<c;j++)
            printf("%d ",m[i][j]);
        printf("\n");
    }
}

void multiply(int A[][10],int B[][10],int C[][10],int r1,int c1,int c2) //function to multiply matrices
{
    int i,j,k;
    for(i=0;i<r1;i++)
	{
        for(j=0;j<c2;j++)
		{
            C[i][j]=0;
            for(k=0;k<c1;k++)
                C[i][j]+=A[i][k]*B[k][j];
        }
    }
}

int main()
{
    int A[10][10],B[10][10],prod[10][10];
    int r1,c1,r2,c2;
    printf("Enter rows and columns of Matrix A: ");
    scanf("%d%d",&r1,&c1);
    printf("Enter rows and columns of Matrix B: ");
    scanf("%d%d",&r2,&c2);
    if(c1!=r2)
	{
        printf("Matrix multiplication not possible. Columns of A must equal rows of B.\n");
        return 0;
    }
    printf("Enter elements for Matrix A:\n");
    read(A,r1,c1);
    printf("Enter elements for Matrix B:\n");
    read(B,r2,c2);
    multiply(A,B,prod,r1,c1,c2);
    printf("\nProduct of Matrix A and B:\n");
    display(prod,r1,c2);
    return 0;
}

