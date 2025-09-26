/* Program to evaluate an expression using stack by converting it into postfix before evaluating
   @Jubin Joy 
   Roll No 35 
   10/09/2025 
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[20], b[50], pf[50];
int top=-1, ptop=-1;

void push(char n) {
    if(top+1==20) {
        printf("Error: Stack is full\n");
    } else {
        stack[++top]=n;
    }
}

void pop() {
    if(top==-1) {
        printf("Error: Stack is empty\n");
    } else {
        pf[++ptop]=stack[top--];
    }
}

int precedence(char op) {
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    return 0;
}

void pushpres(char op) {
    while(top!=-1 && precedence(stack[top])>=precedence(op)) {
        pop();
    }
    push(op);
}

void postfix() {
    int i;
    for(i=0;b[i]!='\0';i++) {
        if(isdigit(b[i])) {
            pf[++ptop]=b[i];
            if(!isdigit(b[i+1])) pf[++ptop]=' ';
        } else if(b[i]=='+'||b[i]=='-'||b[i]=='*'||b[i]=='/') {
            pushpres(b[i]);
        } else if(b[i]=='(') {
            push(b[i]);
        } else if(b[i]==')') {
            while(stack[top]!='(') pop();
            top--;
        } else if(b[i]!=' ') {
            printf("Error: Invalid Character in the Expression\n");
            return;
        }
    }
    while(top!=-1) pop();
    pf[++ptop]='\0';
}

void evaluate() {
    int i,vstack[20],vtop=-1,v1,v2,num=0;
    for(i=0;i<=ptop;i++) {
        if(isdigit(pf[i])) {
            num=0;
            while(isdigit(pf[i])) {
                num=num*10+(pf[i]-'0');
                i++;
            }
            vstack[++vtop]=num;
        }
        if(pf[i]=='+'||pf[i]=='-'||pf[i]=='*'||pf[i]=='/') {
            v2=vstack[vtop--];
            v1=vstack[vtop--];
            switch(pf[i]) {
                case '+': vstack[++vtop]=v1+v2; break;
                case '-': vstack[++vtop]=v1-v2; break;
                case '*': vstack[++vtop]=v1*v2; break;
                case '/': vstack[++vtop]=v1/v2; break;
            }
        }
    }
    printf("The evaluated result is: %d\n", vstack[vtop]);
}

int main() {
    printf("Enter the infix expression: ");
    scanf("%s", b);
    printf("The infix expression:\n%s\n", b);
    postfix();
    printf("The postfix expression:\n%s\n", pf);
    evaluate();
    return 0;
}
