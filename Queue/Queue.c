#include <stdio.h>
#define N 5
int queue[N];
int rear=-1;
int front=-1;

void enque() {
    if(rear==N-1)
        printf("Overflow!!");
    else {
        printf("Enter the element to add in stack: ");
        scanf("%d", &queue[++rear]);
    }
}

void deque() {
    if(front > rear)
        printf("Underflow!!");
    else
        printf("Removed element: %d", queue[++front]);
}

void peek() {
    if(rear==-1 && front==-1)
        printf("Underflow!!");
    else
        printf("The first element in queue is: %d", queue[front]);
}

void display() {
    int i;
    if(rear==-1)
        printf("Underflow!!");
    else { 
        printf("The elements in queue are: ");
        for (i=front;i<=rear;i++);
            printf("%d\n",queue[i]);
    }
}

void main() {
    int x,z;
    do {
        printf("1.Enque\n2.Deque\n3.Peek\n4.Display\n\n");
        printf("Enter your choice: ");
        scanf("%d",&x);
        switch (x) {
            case 1: enque();
                    break;
            case 2: deque();  
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
    } while(z=1);
}