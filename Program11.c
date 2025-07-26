/* Program to find the Determinant of a Matrix (2x2 and 3x3)
   @Jubin Joy 26/07/2025 */

#include <stdio.h>

void read(int m[][3],int n) // function to input elements of the matrix
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&m[i][j]);
}

int determinant(int m[][3],int n) //function to calculate and return the determinant of the matrix
{
	int det;
	if(n==2)
	{
		det=m[0][0]*m[1][1]-m[0][1]*m[1][0];
	}
	else
	{

         det =m[0][0]*(m[1][1]*m[2][2]-m[1][2]*m[2][1])
	         -m[0][1]*(m[1][0]*m[2][2]-m[1][2]*m[2][0])
             +m[0][2]*(m[1][0]*m[2][1]-m[1][1]*m[2][0]);
    }
    return det;
}

int main()
{
    int m[3][3],n;
    printf("Enter the order of the square matrix (2 or 3): ");
    scanf("%d",&n);
    if(n!=2 && n!=3)
	{
        printf("Only 2x2 and 3x3 matrices are supported.\n");
        return 1;
    }
    printf("Enter the elements of the %dx%d matrix:\n",n,n);
    read(m,n);
    printf("Determinant = %d\n",determinant(m,n));
    return 0;
}

