/*Program to convert an expression from infix expression to prefix using stack
@Jubin Joy 
Roll No 35
01/08/2025 */

#include<stdio.h>
#include<string.h>
char stack[20],b[20],top=-1,pf[20],ptop=-1;
void push(char n) //function to push an element onto the stack
{
	if(top+1==20)
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
		 return;
    }
	else
	{
		pf[++ptop]=stack[top--];	
    }
}
void reverse(char s[])// function to reverse the string and swap ")" with "("and vice versa
{
	int len=strlen(s);
    int i;
    char temp;
    for(i=0;i<len/2;i++)
    {
        temp=s[i];
        s[i]=s[len-1-i];
        s[len-1-i]=temp;
    }
    for (i = 0; i < len; i++) {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
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
void prefix()//function to convert from infix to postfix
{
 int i;
 reverse(b);
 for(i=0;b[i]!='\0';i++)
 {
 	if(b[i]>='0'&&b[i]<='9'||b[i]>='A'&&b[i]<='Z'||b[i]>='a'&&b[i]<='z')
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
 reverse(pf);
}

int main()
{
	printf("Enter the infix expression:");
	scanf("%s",b);
	printf("The infix expression:\n");
	puts(b);
	prefix();
	printf("The prefix expression:\n");
	puts(pf);
	return 0;
}

