/*Program to convert an expression from infix expression to postfix using stack
@Jubin Joy 
Roll No 35 
01/08/2025 */

#include<stdio.h>
#include<ctype.h>

char stack[20], b[20], top = -1, pf[20], ptop = -1;

void push(char n) //function to push an element onto the stack
{
    // BUG FIX 3: Changed 5 to 20 to match the array size
    if(top + 1 == 20) 
    {
        printf("Error:Stack is full\n");
    }
    else
    {
        stack[++top] = n;
    }
}

void pop() //function to pop the top element from the stack
{
    if(top == -1)
    {
        printf("Error:Stack is empty\n");
    }
    else
    {
        pf[++ptop] = stack[top--];
    }
}


// Higher number means higher precedence.
int precedence(char op)
{
    switch(op)
    {
        case '(': return 0; // Parentheses have the lowest precedence
        case '+':
        case '-': return 1; // Addition and subtraction
        case '*':
        case '/': return 2; // Multiplication and division
        default:  return -1; // Should not happen
    }
}

void postfix() //function to convert from infix to postfix
{
    int i;
    for(i = 0; b[i] != '\0'; i++)
    {
        if(isalnum(b[i])) // If it's an operand (letter or number)
        {
            pf[++ptop] = b[i];
        }

        else if(b[i] == '(')
        {
            push(b[i]);
        }
        else if(b[i] == ')')
        {

            while(top != -1 && stack[top] != '(')
            {
                pop();
            }
            if(top == -1)
            {
                printf("Error: Mismatched parentheses\n");
                return;
            }
            top--; // Pop and discard the '('
        }
        else if (b[i] == '+' || b[i] == '-' || b[i] == '*' || b[i] == '/')
        {

            while(top != -1 && stack[top] != '(' && precedence(stack[top]) >= precedence(b[i]))
            {
                pop();
            }

            push(b[i]);
        }
        else if(b[i] == ' ' || b[i] == '\t')
        {
            // Ignore spaces
        }
        else
        {
            printf("Error:Invalid Character in the Expression\n");
        }
    }
    
    // Pop any remaining operators from the stack
    while(top != -1)
    {
        if(stack[top] == '(')
        {
            printf("Error: Mismatched parentheses\n"); // Found a '(' without a ')'
            top--; // Discard it
        }
        else
        {
            pop();
        }
    }
    

    pf[++ptop] = '\0';
}

int main()
{
    printf("Enter the infix expression: ");
    scanf("%s", b);
    
    printf("The infix expression:\n");
    puts(b);
    
    postfix();
    
    printf("The postfix expression:\n");
    puts(pf);
    
    return 0;
}