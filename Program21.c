/*A letter means push and an asterisk means pop in the  following sequence. Give the sequence of values returned by the pop operations when this sequence of operations is performed on an initially empty LIFO stack.
@Jubin Joy 
Roll No 35 
10/09/2025 */
#include<stdio.h>
int a[50],top=-1;
void push(int n) //function to push an element onto the stack
{
	if(top+1==5)
	{
		printf("Error:Stack is full\n");
	}
	else
	{
		a[++top]=n;
	}
}
void pop() //function to pop the top element from the stack
{
	if(top==-1)
	{
		printf("Error:Stack is empty\n");
    }
	else
	{
		printf("%c",a[top--]);	
    }
}
void process() 
{
char s[50];
int i;
printf("Enter the string:");
scanf("%s",s);
for(i=0;s[i]!='\0';i++)
{
    if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z')
    {
        push(s[i]);
    }
    else if(s[i]=='*')
    {
        pop();
    }
    else
    {
        printf("Invalid Input!");
        break;
    }
}

}

int main()
{
	process();
	return 0;
}