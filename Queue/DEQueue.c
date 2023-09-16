#include <stdio.h>
#define size 5
int deque[size];
int front=-1,rear=-1;

void insL(int z){
    if((front == 0 && rear == size-1) || front == rear + 1)
        printf("Overflow!!");
    else if(front == -1 && rear == -1)
    {
        rear = front = 0;
        deque[front] = z;
    }
    else if(front == 0)
    {
        front = size-1;
        deque[front] = z;
    }
    else deque[--front]=z;    
}

void insR(int z){
    if((front == size && rear == size-1) || front == rear + 1)
        printf("Overflow!!");
    else if(front == -1 && rear == -1)
    {
        rear = 0;
        deque[rear] = z;
    }
    else if(rear = size-1)
    {
        rear = 0;
        deque[rear] = z;
    }
    else deque[++rear] = z;
}

void delL(){
    if(front == -1 && rear == -1)
        printf("Underflow!!");
    else if(front == rear)
    {   
        printf("The removed element is: %d",deque[front]);
        front = rear = -1;
    }
    else if(front == sizx`e-1)
    {
        printf("The removed element is: %d",deque[front]);
        front = 0;
    }
    else printf("The removed element is: %d",deque[front++]);
}

void delR(){
    if(front == -1 && rear == -1)
        printf("Underflow!!");
    else if(front == rear)
    {   
        printf("The removed element is: %d",deque[rear]);
        front = rear = -1;
    }
    else if(rear == 0)
    {
        printf("The removed element is: %d",deque[rear]);
        rear = size-1;
    }
    else printf("The removed element is: %d",deque[rear++]);
}

void display(){
    int i = front;
    printf("\nElements in DEQueue are: ");
    while(i != rear+1)
    {
        printf("\n%d",deque[i]);
        i++;
    }

}

int main(){
    int n,z;
    do{
        printf("\n\n1.Insert Left\n2.Insert Right\n3.Delete Left\n4.Delete right\n5.Display\n6.Exit\n");
        printf("Enter tour choice: ");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            printf("Enter number to be inserted: ");
            scanf("%d",&z);
            insL(z);
            break;
        
        case 2:
            printf("Enter number to be inserted: ");
            scanf("%d",&z);
            insR(z);
            break;

        case 3:
            delL();
            break;

        case 4:
            delR();
            break;

        case 5:
            display();
            break;

        case 6:
            break;

        default:
            printf("Invalid input!! Please enter correct value.");
        }
    }while(n!=6);
    
    return 0;
}