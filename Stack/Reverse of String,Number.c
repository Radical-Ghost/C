#include <stdio.h>
#define N 50
int top=-1;
char stack[N];

void push(int x)
{
	if(top!=N-1)
    	stack[++top]=x;
}

char pop()
{
    if(top>-1)
        return stack[top--];
}

int dectobin()
{
	int i=1,n,r=0;
    printf("Enter a Number to be converted: ");
    scanf("%d",&n);

	while(n>0)
	{
		push(n%2);
		n/=2;
	}
	
	printf("The binary equivalent is: ");
	while(top>=0)
		printf("%d",pop());
}

/*
int revs()
{
	int i=0;
	char n[N];
    printf("Enter a string to be reversed: ");
    scanf("%s",n);
	
	while(n[i])
		push(n[i++]);
		
	printf("The reverse is: ");
	while(top>=0)
		printf("%c",pop());
}
*/

/*
int revsp()
{
	int i=0;
	char n[N];
    printf("Enter a string to be checked: ");
    scanf("%s",n);
	
	while(n[i])
		push(n[i++]);
	

	while(n[i])
		if(n[i++]!=pop())
		{
			i=0;
			break;
		}
	
	if(i==0)
    	printf("%s is not palindrome",n);
    else printf("%s is palindrome",n);
}
*/

/*
int revn()
{
	int i=1,n,r=0;
    printf("Enter a number to be reversed: ");
    scanf("%d",&n);

	while(n>0)
	{
		push(n%10);
		n/=10;
	}
	
	while(top>=0)
	{
		r+=(pop()*i);
		i*=10;
	}
	
	printf("The reverse is: %d",r);
}
*/

void main()
{   
    //revn();
    //revs();
    //revsp();
    dectobin();
}
