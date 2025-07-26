/* Program to read a string and reverse it in the same array
   @Jubin Joy 26/07/2025 */
   
#include <stdio.h>
#include <string.h>
void reverse(char s[],int len)// function to reverse the string
{
    int i;
    char temp;
    for(i=0;i<len/2;i++)
    {
        temp=s[i];
        s[i]=s[len-1-i];
        s[len-1-i]=temp;
    }
}

int main() 
{
    char s[20];
    int len;
    printf("Enter a string:");
    scanf("%s", s);
    len = strlen(s);
    reverse(s,len);
    printf("Reversed string: %s",s);
    return 0;
}

