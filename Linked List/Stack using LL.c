#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node *top = NULL;

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

void display(){
    struct node *ptr;
    ptr = top;
    if(top == NULL){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack elements are : \n");
        while(ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main(){
    int c, x;
    while(c != 4){
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter the element to be pushed : ");
            scanf("%d", &x);
            push(x);
            break;
        
        case 2:
            pop();
            break;

        case 3:
            display();
            break;
        
        case 4:
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}
