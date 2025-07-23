#include<stdio.h>
char stack[50];
int top=-1;
int length(char a[])
{
	int i;
	for(i=0;a[i]!='\0';i++);
	return i;
}

void copy(char a[],char b[])
{
	int i;
	for(i=0;a[i]!='\0';i++)
	{
		b[i]=a[i];
	}
	b[i] = '\0';
}

void concat(char a[],char b[])
{
	int alen=length(a),blen=length(b),i,j=0;
	for(i=alen;i<(alen+blen);i++)
	{
		a[i]=b[j++];
	}
	a[i] = '\0';
	
	
}
void push(char ch)
{
	stack[++top]=ch;
}
char pop()
{
	return stack[top--];
}
void reverse(char a[])
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
void compare(char a[],char b[])
{
	int i,flag=0;
	for(i=0;a[i]!='\0' && b[i]!='\0';i++)
	{
		if(a[i]!=b[i])
		{
			flag=1;
			break;
		}
	}
    if(flag == 0 && a[i] == '\0' && b[i] == '\0') 
	{
        printf("Both Strings are Equal\n");
    } 
	else 
	{
        printf("Both Strings are Not Equal\n");
    }
}
char Lower(char ch) 
{
    if (ch >= 'A' && ch <= 'Z')
        return ch + 32;
    return ch;
}
void comparei(char a[],char b[])
{
	int i,flag=0;
	for(i=0;a[i]!='\0' && b[i]!='\0';i++)
	{
		if(Lower(a[i])!=Lower(b[i]))
		{
			flag=1;
			break;
		}
	}
	if(flag == 0 && a[i] == '\0' && b[i] == '\0') 
	{
        printf("Both Strings are Equal\n");
    } 
	else 
	{
        printf("Both Strings are Not Equal\n");
    }
}
int menu()
{
	int ch;
	printf("\n 1.String Length \n 2.Copy String \n 3.String Concatenation\n 4.String Reverse\n 5.String Compare(case sensitive)\n 6.String Compare(case insensitive)\n 7.Exit \n Enter Your Choice:");
	scanf("%d",&ch);
	return ch;
}
void process()
{
	char a[50],b[50];
	int ch;
	for(ch=menu();ch!=7;ch=menu())
	{
		switch(ch)
		{
			case 1:printf("Enter a String:");
				   scanf("%s",a);
				   printf("String Length=%d",length(a));
				   break;
			case 2:printf("Enter a String:");
				   scanf("%s",a);
				   copy(a,b);
				   printf("String Copied to another array:");
				   puts(b);
				   break;
			case 3:printf("Enter a String:");
				   scanf("%s",a);
				   printf("Enter another String:");
				   scanf("%s",b);
				   concat(a,b);
				   puts(a);
				   break;
			case 4:printf("Enter a String:");
				   scanf("%s",a);
				   reverse(a);
				   break;
			case 5:printf("Enter a String:");
				   scanf("%s",a);
				   printf("Enter another String:");
				   scanf("%s",b);
				   compare(a,b);
				   break;
			case 6:printf("Enter a String:");
				   scanf("%s",a);
				   printf("Enter another String:");
				   scanf("%s",b);
				   comparei(a,b);
				   break;
			default:printf("Error:Invalid Choice");
					break;
		}
	}
}
int main()
{
	process();
	return 0;
}
