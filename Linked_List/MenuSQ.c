#include <stdio.h>
struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;
struct node *top = NULL;

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

void Qdisplay(){
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


void push(int x){
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    ptr->next = top;
    top = ptr;
}

void pop(){
    struct node *ptr;
    if(top == NULL){
        printf("Stack is empty\n");
    }
    else{
        ptr = top;
        printf("Popped Element is : %d\n", ptr->data);
        top = top->next;
        free(ptr);       
    }
}

void Sdisplay(){
    struct node *ptr;
    ptr = top;
    if(top == NULL){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack elements are : \n");
        while(ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}

void main(){
    int z, c, x;
    do{
        printf("\n1. Queue\n2. Stack\n3. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &z);
        switch (z){
        case 1:
            do{
                printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice: ");
                scanf("%d", &c);
                switch (c){
                case 1:
                    printf("Enter the element to be inserted: ");
                    scanf("%d", &x);
                    enque(x);
                    break;
                case 2:
                    deque();
                    break;
                case 3:
                    Qdisplay();
                    break;
                case 4:
                    break;
                default:
                    printf("Invalid choice!! Try again\n");
                }
            }while (c != 4);
            break;
        
        case 2:
            do{
                printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
                printf("Enter your choice : ");
                scanf("%d", &c);
                switch (c){
                case 1:
                    printf("Enter the element to be pushed : ");
                    scanf("%d", &x);
                    push(x);
                    break;
                
                case 2:
                    pop();
                    break;

                case 3:
                    Sdisplay();
                    break;
                
                case 4:
                    break;

                default:
                    printf("Invalid choice\n");
                    break;
                }
            }while(c != 4);
            break;

        case 3:
            break;
        
        default:
            printf("Invalid choice\n");
            break;
        }
    }while(z != 3);
}