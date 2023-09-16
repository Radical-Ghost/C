#include <stdio.h>
struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enque(int x){
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    ptr->next = NULL;
    if(front == NULL){
        front = ptr;
        rear = ptr;
    }
    else{
        rear->next = ptr;
        rear = ptr;
    }
}

void deque(){
    struct node *ptr;
    ptr = front;
    if(front == NULL)
        printf("Queue is empty\n");
    else{
        printf("Deleted element is: %d\n", front->data);
        front = front->next;
        free(ptr);
    }
}

void display(){
    struct node *ptr;
    ptr = front;
    if(front == NULL)
        printf("Queue is empty\n");
    else{
        printf("Queue elements are: ");
        while(ptr != NULL){
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    int c, x;
    while (c != 4)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &x);
            enque(x);
            break;
        case 2:
            deque();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("Invalid choice!! Try again\n");
        }
    }
    return 0;
}