#include <stdio.h>
#define N 50
int top=-1;
char infix[N];
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

int match(char a, char b)
{
	if(a=='(' && b==')')
		return 1;
	if(a=='{' && b=='}')
		return 1;
	if(a=='[' && b==']')
		return 1;
	else return 0;
}

int par()
{
	int i;
	char p;
	printf("Enter a Expresion: ");
	scanf("%s",infix);
    
	for(i=0;infix[i];i++)
	{
		if(infix[i]=='(' || infix[i]=='[' || infix[i]=='{')
		push(infix[i]);

		else if(infix[i]==')' || infix[i]==']' || infix[i]=='}')
		{
			if(top==-1)
			{
				printf("Invalid Parenthesis.");
				return 0;
			}
			else if(!match(pop(),infix[i]))
				{
					printf("Invalid Parenthesis.");
					return 0;
				}
		}    
	}
    
	if(top==-1)
		printf("Valid Parenthesis.");
	else printf("Invalid Parenthesis.");
}

int main()
{   
    par();
}

