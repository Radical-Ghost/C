#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int stack1[MAX_SIZE];
int stack2[MAX_SIZE];
int top1 = -1; 
int top2 = -1; 

void push1(int x) 
{
    if (top1 == MAX_SIZE - 1) 
	{
        printf("Queue is full.");
        return;
    }
    stack1[++top1] = x;
}

void push2(int x) {
    if (top2 == MAX_SIZE - 1) 
	{
        printf("Queue is full.");
        return;
    }
    stack2[++top2] = x;
}

int pop1() 
{
    if (top1 == -1) 
	{
        printf("Queue is empty.");
        return -1; 
    }
    return stack1[top1--];
}

int pop2() {
    if (top2 == -1) 
	{
        printf("Queue is empty.");
        return -1; 
    }
    return stack2[top2--];
}

void enque() 
{
	int x;
	printf("Enter a value: ");
	scanf("%d",&x);
	
	if (top1 == -1) 
	{
        while (top2 >= 0) 
		{
            push1(pop2());
        }
    }
    
    push1(x);
}

int deque() 
{
    if (top1 == -1 && top2 == -1) 
	{
        printf("Queue is empty.");
        return -1; 
    }

    if (top2 == -1) 
	{
        while (top1 >= 0) 
		{
            push2(pop1());
        }
    }

    return pop2();
}

int main() 
{
	int z;
	do
	{
		printf("1.Enque\n2.Deque\n3.Exit\n");
    	printf("Enter your choice: ");
    	scanf("%d",&z);
		switch(z)
		{
			case 1:	enque();
			case 2: deque();
			case 3: exit(0);
			default: printf("Invalid choice.");
		}
	}while(z>0);
    return 0;
}
