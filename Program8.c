/* Program to Perform the addition and subtraction of two matrices
   @Jubin Joy 25/07/2025 */

#include <stdio.h>

void read(int m[][10],int r,int c) //function to input the elements of the matrix
{
	int i,j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&m[i][j]);
}

void display(int m[][10],int r,int c) //function to display the elements of the matrix
{
	int i,j;
    for(i=0;i<r;i++)
	{
        for(j=0;j<c;j++)
            printf("%d ",m[i][j]);
        printf("\n");
    }
}

void add(int A[][10],int B[][10],int result[][10],int r,int c) //function for adding two matrices
{
	int i,j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            result[i][j]=A[i][j]+B[i][j];
}

void subtract(int A[][10],int B[][10],int result[][10],int r,int c) //function for subtracting two matrices
{
	int i,j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            result[i][j]=A[i][j]-B[i][j];
}

int main()
{
    int A[10][10],B[10][10],sum[10][10],diff[10][10];
    int r,c;
    printf("Enter the number of rows and columns: ");
    scanf("%d%d",&r,&c);
    printf("\nEnter the elements for Matrix A:\n");
    read(A,r,c);
    printf("\nEnter the elements for Matrix B:\n");
    read(B,r,c);
    add(A,B,sum,r,c);
    subtract(A,B,diff,r,c);
    printf("\nSum of matrix A and B:\n");
    display(sum,r,c);
    printf("\nDifference of matrix A and B:\n");
    display(diff,r,c);
    return 0;
}

