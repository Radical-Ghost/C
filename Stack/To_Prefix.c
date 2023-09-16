#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 50
int top=-1;
char ifx[N];
char pfx[N];
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

void intpr()
{
	int i,j=0;
    printf("Enter a Expresion: ");
    scanf("%s",ifx);
    strrev(ifx);
    
    for(i=0;ifx[i];i++)
    {
        if(ifx[i]=='(')
        	push(ifx[i]);
			
        else if(isalnum(ifx[i]))
        	pfx[j++]=ifx[i];

        else if(ifx[i]==')')
        {
            while(stack[top]!='(' && top>-1)
                pfx[j++]=pop();
            pop();
        }
        
        else
        {
            while(top>-1 && prec(stack[top])>=prec(ifx[i]))
                pfx[j++]=pop();
            push(ifx[i]);
        }
    }

    while(top>-1)
        pfx[j++]=pop();
	
	strrev(pfx);
    printf("Prefix of the expression is: %s",pfx);
}

void main()
{   
    intpr();
}
