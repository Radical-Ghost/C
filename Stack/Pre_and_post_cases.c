#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 5
int top=-1;
char infix[N];
char prefix[N];
char postfix[N];
char stack[N];

void push(char x)
{
	if(top!=N-1)
    	stack[++top]=x;
}

char pop()
{
    if(top>-1)
        return stack[top--];
}

int prec(char x)
{
	if(x=='^' || x=='$')
		return 3;
    else if(x=='*' || x=='/')
        return 2;
    else if(x=='+' || x=='-')
        return 1;
    else return 0;
}

void infixtopostfix()
{
	int i,j=0;
    printf("Enter stack Expresion: ");
    scanf("%s",infix);
    
    for(i=0;infix[i];i++)
    {
        if(infix[i]=='(')
        	push(infix[i]);
			
        else if(isalnum(infix[i]))
        	prefix[j++]=infix[i];

        else if(infix[i]==')')
        {
            while(stack[top]!='(' && top>-1)
                prefix[j++]=pop();
            pop();
        }
        
        else
        {
            while(top>-1 && prec(stack[top])>=prec(infix[i]))
                prefix[j++]=pop();
            push(infix[i]);
        }
    }

    while(top>-1)
        prefix[j++]=pop();
		
    printf("Postfix of the expression is: %s\n\n",prefix);
}

void infixtoprefix()
{
	int i,j=0;
    printf("Enter a Expresion: ");
    scanf("%s",infix);
    strrev(infix);
    
    for(i=0;infix[i];i++)
    {
        if(infix[i]=='(')
        	push(infix[i]);
			
        else if(isalnum(infix[i]))
        	postfix[j++]=infix[i];

        else if(infix[i]==')')
        {
            while(stack[top]!='(' && top>-1)
                postfix[j++]=pop();
            pop();
        }
        
        else
        {
            while(top>-1 && prec(stack[top])>=prec(infix[i]))
                postfix[j++]=pop();
            push(infix[i]);
        }
    }

    while(top>-1)
        postfix[j++]=pop();
	
	strrev(postfix);
    printf("Prefix of the expression is: %s\n\n",postfix);
}

void main()
{   
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
