/* Program to read n strings and display them in ascending order
   @Jubin Joy 26/07/2025 */

#include <stdio.h>
#include <string.h>

void sort(char s[][50],int n) //function to sort the strings in ascending order
{
    int i,j;
    char temp[50];
    for(i=0;i<n-1;i++) 
	{
        for(j=0;j<n-i-1;j++) 
		{
            if(strcmp(s[j],s[j+1])>0) 
			{
                strcpy(temp,s[j]);
                strcpy(s[j],s[j+1]);
                strcpy(s[j+1],temp);
            }
        }
    }
}

int main()
{
    char s[20][50];
    int n,i;
    printf("Enter the number of strings: ");
    scanf("%d",&n);
    printf("Enter the strings:\n");
    for(i=0;i<n;i++)
    	{
       	 scanf("%s",s[i]);
    	}
    sort(s,n);
    printf("\nStrings in ascending order:\n");
    for(i=0;i<n;i++)
    	{
      	  printf("%s\n",s[i]);
    	}
    return 0;
}

