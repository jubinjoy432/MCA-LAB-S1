/*Program to demonstrate the use of storage classes (local variable, global variable, static variable, register variable)
@Jubin Joy 35 16/07/2025*/

#include<stdio.h>
int a=5;//global
void display() //function to display the current value of the variables
{
	int b=5;//local
	static int c=5;//static
	register int d=5;//register
	printf("global=%d local=%d static=%d register=%d \n",a++,b++,c++,d++);
}
int main()
{
	display();
	display();
	display();
	return 0;
}
