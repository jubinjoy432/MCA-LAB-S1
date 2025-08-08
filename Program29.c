/*Program to demonstrate queue using array
@Jubin Joy 35 06-08-2025*/

#include<stdio.h>
int a[10],front=-1,rear=-1;
void enqueue(int n)
{
	if(front==-1 && rear==-1)
	{
		front++;
		rear++;
		a[rear]=n;
		printf("Enqueued:%d\n",n);
	}
	else if(rear==9)
	{
		printf("Queue is Full\n");
	}
	else
	{
	 	a[++rear]=n;
	 	printf("Enqueued:%d\n",n);
	}
}
void dequeue()
{
	if(front==-1 || front>rear)
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("Deleted :%d\n",a[front]);
		if(front==rear)
		{
			front=rear=-1;
		}
		else
		{
		front++;
		}
	}
}
void peek()
{
	if(front==-1 || front>rear)
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("Front Element:%d\n",a[front]);
	}
}
char menu()
{
	int ch;
	printf(" 1.PUSH \n 2.POP \n 3.PEEK \n 4.EXIT \n Enter your choice:");
	scanf("%d",&ch);
	return ch;
}
void process()
{
	int val,ch;
	do
	{
		ch=menu();
		switch(ch)
		{
			case 1:printf("Enter the value to push:");
					scanf("%d",&val);
					enqueue(val);
					break;
			case 2:dequeue();
					break;
			case 3:peek();
					break;
			default:printf("Error:Invalid Choice");
					break;				
		}
	}while(ch!=4);
}
int main()
{
	process();
	return 0;
}
