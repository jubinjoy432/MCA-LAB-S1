/*Program to read and display a polynomial
@Jubin Joy 35 08-08-2025 */
#include<stdio.h>
void readpoly(int p[],int n)
{
	int i;		
	for(i=1;i<n;i++)
	{
		printf("Enter the coefficient for x^%d:",i);
		scanf("%d",p[i]);
	}
}
void displaypoly()
{
	int i;		
	for(i=n;i>=0;i++)
	{
		
	}
}
}
int main()
{
	int p[20],n;
	printf("Enter the degree of the polynomial:")
	scanf("%d",&n);
	readpoly(p,n);
	
}
