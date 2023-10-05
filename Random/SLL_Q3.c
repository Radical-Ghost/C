#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *start = NULL;

void insert_sorted(int x){
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    if(start == NULL || x <= start->data){
        ptr->next = start;
        start = ptr;
    }
    else{
        temp = start;
        while(temp->next != NULL && temp->next->data < x)
            temp = temp->next;
        ptr->next = temp->next;
        temp->next = ptr;
    }
}

void del_begin(){
    if(start == NULL)
        printf("List is empty\n");
    else{
        struct node *ptr;
        printf("Deleted element is %d\n", start->data);
        ptr = start;
        start = start->next;
        free(ptr);
    }
}

void del_end(){
    if(start == NULL)
        printf("List is empty\n");
    else if(start->next == NULL)
        del_begin();
    else{
        struct node *ptr = start;
        while(ptr->next->next != NULL)
            ptr = ptr->next;
        printf("Deleted element is %d\n", ptr->next->data);
        free(ptr->next);
        ptr->next = NULL;
    }
}

void del_pos(int pos){
    if(start == NULL)
        printf("List is empty\n");
    else if(pos == 1)
        del_begin();
    else{
        struct node *temp,*ptr = start;
        for(int i = 1; i < pos; i++){
            temp = ptr;
            ptr = ptr->next;
        }
        printf("Deleted element is %d\n", ptr->data);
        temp->next = ptr->next;
        free(ptr);
    }
}

void search(int x){
    struct node *temp = start;
    int pos = 1, c = 0;
    while(temp != NULL){
        if(temp->data == x){
            printf("%d found at position %d\n", x, pos);
            c = 1;
        }
        temp = temp->next;
        pos++;
    }
    if(temp == NULL && c == 0)
        printf("%d not found in the list\n", x);
}

void display(){
    if(start == NULL)
        printf("List is empty\n");
    else{
        struct node *temp = start;
        printf("List: ");
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    int c = 0, x, pos;
    do{
        printf("1. Insert node in sorted order\n2. Delete node from the beginning\n3. Delete node from the specified position\n4. Delete node at end\n5. Search node\n6. Display the list\n7. Exit\n\Enter your choice: ");
        scanf("%d", &c);
        switch(c){
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &x);
                insert_sorted(x);
                break;
            case 2:
                del_begin();
                break;
            case 3:
                printf("Enter the position of the element to be deleted: ");
                scanf("%d", &pos);
                del_pos(pos);
                break;
            case 4:
                del_end();
                break;
            case 5:
                printf("Enter the element to be searched: ");
                scanf("%d", &x);
                search(x);
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }while(c != 7);
}