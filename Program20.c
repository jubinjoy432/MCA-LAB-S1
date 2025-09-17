/*Program to evaluate an expression using stack by converting it into postfix before evaluating
@Jubin Joy 
Roll No 35 
01/08/2025 */

#include<stdio.h>
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
 	if(b[i]>='0'&&b[i]<='9')
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
void evaluate()//function to evaluate the postfix expression
{
    int i,vstack[20],vtop=-1,v1,v2;
    char sign;
    for(i=0;i<=ptop;i++)
    {
        if(pf[i]>='0'&&pf[i]<='9')
        {
            vstack[++vtop]=pf[i]-'0';
        }
        else
        {
            v2=vstack[vtop--];
            v1=vstack[vtop--];
            sign=pf[i];
            switch(sign)
            {
                case '+':
                    vstack[++vtop]=v1+v2;
                    break;
                case '-':
                    vstack[++vtop]=v1-v2;
                    break;
                case '*':
                    vstack[++vtop]=v1*v2;
                    break;
                case '/':
                    vstack[++vtop]=v1/v2;
                    break;		
            }
        }
    }
    printf("The evaluated result is:%d",vstack[vtop]);
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
    evaluate();
	return 0;
}


