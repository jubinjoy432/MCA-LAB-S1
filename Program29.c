/*Program to demonstrate queue using array
@Jubin Joy 
Roll No 35 
09-08-2025*/

#include<stdio.h>
int a[10],front=-1,rear=-1;
void enqueue(int n)//function to add element to queue
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
void dequeue()//function to delete element from queue
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
void peek()//function to display front element of queue
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
void display() //function to display all elements of the queue
{
    int i;
    if(front==-1 || front>rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for(i=front;i<=rear;i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int menu()//function to display menu
{
    int ch;
    printf(" 1.ENQUEUE \n 2.DEQUEUE \n 3.PEEK \n 4.DISPLAY \n 5.EXIT \n Enter your choice:");
    scanf("%d",&ch);
    return ch;
}
void process()//function to process menu options
{
    int val,ch;
    do
    {
        ch=menu();
        switch(ch)
        {
            case 1:printf("Enter the value to ENQUEUE:");
                    scanf("%d",&val);
                    enqueue(val);
                    break;
            case 2:dequeue();
                    break;
            case 3:peek();
                    break;
            case 4:display();
                    break;
            case 5:printf("Exiting...\n");
                    break;
            default:printf("Error:Invalid Choice\n");
                    break;				
        }
    }while(ch!=5);
}
int main()
{
    process();
    return 0;
}
