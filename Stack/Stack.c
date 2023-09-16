#include <stdio.h>
#define N 5
int stack[N];
int top=-1;

void push()
{
    if(top==N-1)
    {
        printf("Overflow!!");
    }  
    else
    {
        printf("Enter the element to add in stack: ");
        scanf("%d",&stack[++top]);
    }
}

void pop()
{
    if(top==-1)
        printf("Underflow!!");
    else
    {
        printf("Popped element: %d",stack[top--]);
    }
}

void peek()
{
    if(top==-1)
        printf("Underflow!!");
    else
    {
        printf("The top element: %d",stack[top]);
    }
}

void display()
{
	int i;
    for (i=top;i>=0;i--);
        printf("%d\n",stack[i]);
}

void main()
{
    int x,z;
    do
    {
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n\n");
        printf("Enter your choice: ");
        scanf("%d",&x);
        switch (x)
        {
            case 1: push();
                    break;
            case 2: pop();  
                    break;
            case 3: peek();
                    break;
            case 4: display();
                    break;
            default: printf("Please enter correct value!!");
        }

        printf("\n\nIf you want to continue enter 1: ");
        scanf("%d",&z);
        printf("\n\n");
    }while(z==1);
}
