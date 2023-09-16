#include<stdio.h>
#define MAX 5

struct stack
{
	int a[MAX];
	int top;
}s;

void overflow()
{
	printf("stack is full");
}

void underflow()
{
	printf("stack is empty");
}

void push(int x)
{
	if(s.top==MAX-1)
		overflow();
	else
		s.a[++s.top]=x;
}

int pop()
{
	if(s.top==-1)
		underflow();
	else
		return(s.a[s.top--]);

}

int peek()
{
	return s.a[s.top];
}
void display()
{
	int i;
	for(i=0;i<=s.top;i++)
		printf("%d\n",s.a[i]);
}

int main()
{	
	s.top=-1;
	int z,x;
	do
	{
		printf("\n\n1.push\n2.pop\n3.peek\n4.display");
		printf("\nEnter your choice: ");
		scanf("%d",&z);
		switch(z)
		{
			case 1:	printf("Enter element to be pushed:");
					scanf("%d",&x);
					push(x);
					break;
					
			case 2:	printf("Popped element = %d\n",pop());
					break;
					
			case 3:	printf("Top element = %d\n",peek());
					break;
					
			case 4:	display();
					break;
					
			case 5: exit(0);
			
			default: printf("Invalid choice.");
		}
	}while(z<5);
}
