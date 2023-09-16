#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

void ins_begin(int x){
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    ptr->next = head;
    head = ptr;
}

void ins_end(int x){
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    ptr->next = NULL;
    if(head == NULL)
        ptr = head;
    else{
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }
}

void ins_pos(int x, int pos){
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    ptr->next = NULL;
    if(pos == 1){
        ptr->next = head;
        head = ptr;
    }
    else{
        temp = head;
        for(int i = 1; i < pos - 1; i++)
            temp = temp->next;
        ptr->next = temp->next;
        temp->next = ptr;
    }
}

void del_begin(){
    struct node *ptr;
    if(head == NULL)
        printf("List is empty\n");
    else{
        printf("Deleted element is %d\n", head->data);
        ptr = head;
        head = head->next;
        free(ptr);
    }
}

void del_end(){
    struct node *ptr, *temp;
    if(head == NULL)
        printf("List is empty\n");
    else if(head->next == NULL){
        printf("Deleted element is %d\n", head->data);
        ptr = head;
        head = NULL;
        free(ptr);
    }
    else{
        printf("Deleted element is %d\n", head->data);
        ptr = head;
        while(ptr->next != NULL){
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        free(ptr);
    }
}

void del_pos(int pos){
    struct node *ptr, *temp;
    if(head == NULL)
        printf("List is empty\n");
    else if(pos == 1){
        printf("Deleted element is %d\n", head->data);
        ptr = head;
        head = head->next;
        free(ptr);
    }
    else{
        ptr = head;
        for(int i = 1; i < pos; i++){
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        free(ptr);
    }
}

void display(){
    struct node *ptr;
    if(head == NULL)
        printf("List is empty\n");
    else{
        ptr = head;
        while(ptr != NULL){
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void main(){
    int c, x, pos;
    while(1){
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete at beginning\n5. Delete at end\n6. Delete at position\n7. Display\n8. Exit\n");
        printf("Enter your coice: ");
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
                del_begin();
                break;
            case 5:
                del_end();
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &pos);
                del_pos(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid coice\n");
        }
    }
}