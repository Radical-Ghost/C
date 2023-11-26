#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 50
int top=-1, i, j = 0;
char infix[N];
char fix[N];
char stack[N];

void push(char x) {
	if(top != N-1)
    	stack[++top]=x;
}

char pop() {
    if(top > -1)
        return stack[top--];
}

int prec(char x) {
	if(x=='^' || x=='$')
		return 3;
    else if(x=='*' || x=='/')
        return 2;
    else if(x=='+' || x=='-')
        return 1;
    else return 0;
}

void convert() {
    for(i = 0; infix[i]; i++) {
        if(infix[i] == '(')
            push(infix[i]);

        else if( isalnum(infix[i]) )
            fix[j++]=infix[i];

        else if(infix[i]==')') {
            while(stack[top] != '(' && top > -1)
                fix[j++]=pop();
            pop();
        }

        else {
            while(top > -1 && prec(stack[top]) >= prec(infix[i]))
                fix[j++] = pop();
            push(infix[i]);
        }
    }

    while(top>-1)
        fix[j++]=pop();
}

void infixtopostfix() {
    printf("Enter an Expresion: ");
    scanf("%s",infix);

    convert();
    fix[j]='\0';	
    printf("Postfix of the expression is: %s\n\n",fix);
}

void infixtoprefix() {
    printf("Enter an Expresion: ");
    scanf("%s",infix);
    strrev(infix);

    //the convert function wont work unless we change the brackets to their opposite since we are reversing the string
    for(i = 0; infix[i]; i++) {
        if(infix[i] == '(')
            infix[i] = ')';
        else if(infix[i] == ')')
            infix[i] = '(';
    }

    convert();
	strrev(fix);
    fix[j]='\0';
    printf("Prefix of the expression is: %s\n\n",fix);
}

void main() {   
    int c = 0;
    while(c != 3) {
        printf("1. Infix to Prefix\n2. Infix to Postfix\n3.Exit\nEnter your choice: ");
        scanf("%d",&c);
        if(c==1)
            infixtoprefix();
        else if(c==2)
            infixtopostfix();
        else if(c==3)
            break;
        else printf("Invalid choice");
    }
}
