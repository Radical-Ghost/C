#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define N 50
int top=-1;
char prefix[N];
int stack[N];

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

void oper(int a, int b, char x)
{
	if(x=='*')
		push(a*b);
	if(x=='/')
		push(b/a);
	if(x=='+')
		push(a+b);
	if(x=='-')
		push(b-a);
}

int eval()
{
	printf("Enter stack Expresion: ");
    scanf("%s",prefix);
    strrev(prefix);
    
	int i;
	for(i=0;prefix[i];i++)
	{
    	if(isdigit(prefix[i]))
    		push(prefix[i]-48);
    	else 
			oper(pop(),pop(),prefix[i]);  
	}
	
    printf("The evaluated result is: %d",pop());
}

void main()
{   
    eval();
}

