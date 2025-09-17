#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node stack;
stack *top=NULL;
void push(int a)
{
		stack *t;
		t=(stack*)malloc(sizeof(stack));
		t->data=a;
		t->next=top;
		top=t;
	

}
void pop()
{
	if(top==NULL)
	{
		printf("stack is empty");
	}
	else
	{
		printf("\n%d\n",top->data);
		top=top->next;
	}
}
void reverse()
{

}
int main()
{
int s
}
