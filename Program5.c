/*To sort the elements in an array in ascending order
@Jubin Joy 27/03/2025*/
#include<stdio.h>
void read(int a[],int n) //function to insert elements into the array
{
	int i;
	printf("Enter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void sort(int a[],int n) //function to sort the elements in the array in ascending order using bubble sort
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void disp(int a[],int n) //function to display all the elements in the array
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
int main()
{
	int a[10],n;
	printf("Enter the no. of elements in the array:");
	scanf("%d",&n);
	read(a,n);
	printf("Before Sorting:\n");
	disp(a,n);
	sort(a,n);
	printf("\n After Sorting:\n");
	disp(a,n);
	return 0;
	
}
