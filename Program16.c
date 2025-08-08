/* Program to reverse a string using Stack
   @Jubin Joy 35 27/02/2025 */

#include<stdio.h>
char stack[50];
int top=-1;
void push(char ch) //function to push a character onto the stack
{
	stack[++top]=ch;
}
char pop() //function to pop the character on the top of the stack
{
	return stack[top--];
}
void reverse(char a[]) //function to print the string in reverse order
{
	int i;
	for(i=0;a[i]!='\0';i++)
	{
		push(a[i]);
	}
	while(top!=-1)
	{
		printf("%c",pop());
	}
}
int main()
{
	char a[50];
	printf("Enter a String:");
	scanf("%s",a);
	printf("Reversed String:");
	reverse(a);
	return 0;
}
