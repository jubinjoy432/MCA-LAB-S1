/* Program to read a string and print it in reverse order
   @Jubin Joy 35 26/07/2025 */
   
#include <stdio.h>
#include <string.h>
void reverse(char s[],int len)// function to print the string in reverse order
{
	int i;
	for(i=len-1;i>=0;i--)
	{
        printf("%c", s[i]);
    }
}

int main() 
{
    char s[20];
    int i, len;
    printf("Enter a string: ");
    scanf("%s", s);
    len = strlen(s);
    printf("Reversed string: ");
    reverse(s,len);
    return 0;
}

