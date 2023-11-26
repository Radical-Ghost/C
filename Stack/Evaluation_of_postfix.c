#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define N 50
int top=-1;
char expr[N];
int stack[N];

void push(int x) {
    if(top!=N-1)
        stack[++top]=x;
}

int pop() {
    if(top>-1)
        return stack[top--];
}

void oper(char x, int a, int b) {
    if(x=='*')
        push(a*b);
    if(x=='/')
        push(a/b);
    if(x=='+')
        push(a+b);
    if(x=='-')
        push(a-b);
}

check() {
    int i;
    for(i=0; expr[i]; i++) {
        if(isdigit(expr[i]))
            push(expr[i]-'0');
        else 
            oper(expr[i], pop(), pop());  
    }
}

void evaluate_prefix() {
    printf("Enter prefix Expression: ");
    scanf("%s",expr);
    
    strrev(expr);
    check();
    
    printf("The evaluated result is: %d",pop());
}

void evaluate_postfix() {
    printf("Enter postfix Expression: ");
    scanf("%s",expr);
    
    check();
    
    printf("The evaluated result is: %d",pop());
}

int main() {
    int choice;
    printf("1. Evaluate prefix expression\n2. Evaluate postfix expression\nEnter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: evaluate_prefix(); break;
        case 2: evaluate_postfix(); break;
        default: printf("Invalid choice\n");
    }
    
    return 0;
}