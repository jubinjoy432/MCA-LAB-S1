/*Program to convert an expression from infix expression to postfix using stack
@Jubin Joy 
Roll No 35 
01/08/2025 */

#include<stdio.h>
#include<ctype.h>
char stack[20],b[20],top=-1,pf[20],ptop=-1;
void push(char n) //function to push an element onto the stack
{
	if(top+1==5)
	{
		printf("Error:Stack is full\n");
	}
	else
	{
		stack[++top]=n;
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
		pf[++ptop]=stack[top--];	
    }
}
void pushpres(int i)//function to pop higher priority operators before pushing lower priority operator
{
	if(stack[top]=='*'||stack[top]=='/')
		{
			while(stack[top]=='*'||stack[top]=='/')
			{
				pop();
			}
			push(b[i]);
		}
		else
		{
			push(b[i]);
		}
	
}
void postfix()//function to convert from infix to postfix
{
 int i;
 for(i=0;b[i]!='\0';i++)
 {
 	if(isalnum(b[i]))
 	{
 		pf[++ptop]=b[i];
	}
	else if(b[i]=='+'||b[i]=='-')
	{
		pushpres(i);	
	}
	else if(b[i]=='*'||b[i]=='/'||b[i]=='(')
	{
		push(b[i]);
	}
	else if(b[i]==')')
	{
		while(stack[top]!='(')
		{
			pop();
		}
		top--;
	}
	else
	{
		printf("Error:Invalid Character in the Expression");
	}
 }
 while(top!=-1)
 {
 	pop();
 }
}

int main()
{
	printf("Enter the infix expression:");
	scanf("%s",b);
	printf("The infix expression:\n");
	puts(b);
	postfix();
	printf("The postfix expression:\n");
	puts(pf);
	return 0;
}

