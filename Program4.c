/*Program to search all the occurence of an element in an integer array
@Jubin Joy 23/07/2025*/
#include<stdio.h>
void search(int a[],int n,int val)
{
	int i,flag=1;
	printf("%d is found at locations:");
	for(i=0;i<n;i++)
	{
		if(a[i]==val)
		{
			flag=0;
			printf("%d ,",i);
		}
	}
	if(flag)
	{
		printf("Element Not Found");
	}
}
int main()
{
	int a[10],n,i,val;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the element to search:");
	scanf("%d",&val);
	search(a,n,val);
	return 0;
	
}
