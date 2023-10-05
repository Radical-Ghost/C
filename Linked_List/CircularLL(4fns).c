#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node *start = NULL;

void ins_begin(int x){
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
   if(start == NULL){
        start = ptr;
        ptr->next = start;
    }
    else{
        ptr->next = start;
        temp = start;
        while(temp->next != start)
            temp = temp->next;
        temp->next = ptr;
        start = ptr;
    }
}

void ins_end(int x){
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    if(start == NULL){
        start = ptr;
        ptr->next = start;
    }
    else{
        temp = start;
        while(temp->next != start)
            temp = temp->next;
        temp->next = ptr;
        ptr->next = start;
    }
}

void ins_pos(int x, int pos){
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    if(pos == 1){
        ins_begin(x);
    }
    else{
        temp = start;
        for(int i = 1; i < pos - 1; i++)
            temp = temp->next;
        ptr->next = temp->next;
        temp->next = ptr;
    }
}

void del_pos(int pos){
    struct node *ptr, *temp;
    if(start == NULL)
        printf("List is empty\n");
    else if(pos == 1){
        printf("Deleted element is %d\n", start->data);
        ptr = start;
        while(ptr->next != start)
            ptr = ptr->next;
        ptr->next = start->next;
        free(start);
        start = ptr->next;
    }
    else{
        ptr = start;
        for(int i = 1; i < pos; i++){
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        free(ptr);
    }
}

void display(){
    struct node *ptr = start;
    if(ptr == NULL)
        printf("List is empty\n");
    else{
        printf("Elements in List are: ");
        do{
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }while(ptr != start);
        printf("\n");
    }
}

void main(){
    int c, x, pos;
    do{
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete at position\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch(c){
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &x);
                ins_begin(x);
                break;
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d", &x);
                ins_end(x);
                break;
            case 3:
                printf("Enter the element to be inserted: ");
                scanf("%d", &x);
                printf("Enter the position: ");
                scanf("%d", &pos);
                ins_pos(x, pos);
                break;
            case 4:
                printf("Enter the position: ");
                scanf("%d", &pos);
                del_pos(pos);
                break;
            case 5:
                display();
                break;
            case 6:
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(c != 6);
}