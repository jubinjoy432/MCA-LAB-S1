/* Program to find the transpose of a matrix
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

void transpose(int A[][10],int T[][10],int r,int c) //function to find the transpose of the matrix
{
    int i,j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            T[j][i]=A[i][j];
}

int main()
{
    int A[10][10],T[10][10];
    int r,c;
    printf("Enter rows and columns of Matrix: ");
    scanf("%d%d",&r,&c);
    printf("Enter elements of the matrix:\n");
    read(A,r,c);
    transpose(A,T,r,c);
    printf("\nTranspose of the matrix:\n");
    display(T,c,r);
    return 0;
}

