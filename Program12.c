/*Program to implement stack operations using arrays
@Jubin Joy 35 26/07/2025 */
#include<stdio.h>
int a[5],top=-1;
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
		printf("\n Removed :%d\n",a[top--]);	
    }
}
void peek() //function to display the top element in the stack
{
	if(top==-1)
	{
		printf("Error:stack is empty\n");
    }
    else
    {
    	printf("Top Element: %d \n",a[top]);
	}
}
int menu() //function to display the menu
{
	int ch;
	printf("\n 1.PUSH \n 2.POP \n 3.PEEK \n 4.EXIT \n Enter Your Choice:");
	scanf("%d",&ch);
	return ch;
}
void process() //function to invoke the functions based on the choice made by the user
{
	int ch,n;
	for(ch=menu();ch!=4;ch=menu())
	{
		switch(ch)
		{
			case 1:printf("Enter the value to push into the stack:");
				   scanf("%d",&n);
				   push(n);
				   break;
			case 2:pop();
					break;
			case 3:peek();
					break;
			default:printf("Error:Wrong Choice\n");
			
		}
	
	}
}

int main()
{
	process();
	return 0;
}

