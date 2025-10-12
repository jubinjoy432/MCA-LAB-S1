/*Program to demonstrate circular queue using array
@Jubin Joy 
Roll No 35 
06-08-2025*/

#include<stdio.h>

int a[10], front = -1, rear = -1;
#define SIZE 10

void enqueue(int n)//function to add element to queue
{
	if((rear + 1) % SIZE == front)
	{
		printf("Queue is Full\n");
	}
	else if(front == -1 && rear == -1)
	{
		front = rear = 0;
		a[rear] = n;
		printf("Enqueued: %d\n", n);
	}
	else
	{
		rear = (rear + 1) % SIZE;
		a[rear] = n;
		printf("Enqueued: %d\n", n);
	}
}

void dequeue()//function to delete element from queue
{
	if(front == -1)
	{
		printf("Queue is Empty\n");
	}
	else
	{
		printf("Deleted: %d\n", a[front]);
		if(front == rear)
		{
			front = rear = -1;
		}
		else
		{
			front = (front + 1) % SIZE;
		}
	}
}

void peek()//function to display front element of queue
{
	if(front == -1)
	{
		printf("Queue is Empty\n");
	}
	else
	{
		printf("Front Element: %d\n", a[front]);
	}
}

void display()//function to display all elements in the queue
{
	if(front == -1)
	{
		printf("Queue is Empty\n");
	}
	else
	{
		int i = front;
		printf("Queue Elements: ");
		while(1)
		{
			printf("%d ", a[i]);
			if(i == rear)
				break;
			i = (i + 1) % SIZE;
		}
		printf("\n");
	}
}

int menu()//function to display menu
{
	int ch;
	printf("\n1. ENQUEUE\n2. DEQUEUE\n3. PEEK\n4. DISPLAY\n5. EXIT\nEnter your choice: ");
	scanf("%d", &ch);
	return ch;
}

void process()//function to process menu options
{
	int val, ch;
	do
	{
		ch = menu();
		switch(ch)
		{
			case 1:
				printf("Enter the value to ENQUEUE: ");
				scanf("%d", &val);
				enqueue(val);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			case 5:
				printf("Exiting...\n");
				break;
			default:
				printf("Error: Invalid Choice\n");
				break;				
		}
	} while(ch != 5);
}

int main()
{
	process();
	return 0;
}
