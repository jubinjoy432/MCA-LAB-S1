/*Program to display the elements of an array in reverse order order using recursion
@Jubin Joy 25/07/2025 */

#include<stdio.h>
void disp(int a[],int n,int i) //function to display all the elements in the array in reverse order using recursion
{
	if(i==n)
		return;
	disp(a,n,i+1);
	printf("%d ",a[i]);
	
	
}
void read(int a[],int n) //function to insert elements into the array
{
	int i;
	printf("Enter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
int main()
{
	int a[10],n;
	printf("Enter the no. of elements:");
	scanf("%d",&n);
	read(a,n);
	printf("The elements of the array in reverse order:");
	disp(a,n,0);
	return 0;
}
