#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;

void ins_beg(){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&(ptr -> data));
    ptr -> prev = NULL;
    ptr -> next = start;
    start = ptr;
}

void ins_end(){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &(ptr -> data));
    ptr -> next = NULL;
    if (start == NULL) {
        ptr -> prev = NULL;
        start = ptr;
    } else {
        struct node *temp = start;
        while (temp -> next != NULL)
            temp = temp -> next;
        temp -> next = ptr; 
        ptr -> prev = temp;
    }
}

void ins_pos(){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &(ptr -> data));
    printf("Enter the position: ");
    int pos;
    scanf("%d", &pos);
    if (pos == 1) {
        ptr -> prev = NULL;
        ptr -> next = start;
        start = ptr;
    } else {
        struct node *temp = start;
        for (int i = 1; i < pos - 1; i++) {
            if (temp -> next == NULL) {
                printf("Position not found\n\n");
                return;
            }
            temp = temp -> next;
        }
        ptr -> prev = temp;
        ptr -> next = temp -> next;
        temp -> next = ptr;
    }
}

void del_beg(){
    if (start == NULL)
        printf("List is empty\n\n");
    else {
        struct node *temp = start;
        printf("Deleted element: %d\n\n", temp -> data);
        start = start -> next;
        free(temp);
    }
}

void del_end(){
    if (start == NULL)
        printf("List is empty\n");
    else if (start -> next == NULL) {
        printf("Deleted element: %d\n\n", start -> data);
        free(start);
        start = NULL;
    } else {
        struct node *temp = start -> next;
        while (temp -> next != NULL)
            temp = temp -> next;
        printf("Deleted element: %d\n\n", temp -> data);
        temp -> prev -> next = NULL;
        free(temp);
    }
}

void del_pos(){
    if (start == NULL)
        printf("List is empty\n\n");
    else {
        printf("Enter the position: ");
        int pos;
        scanf("%d", &pos);
        if (pos == 1) {
            struct node *temp = start;
            printf("Deleted element: %d\n", temp -> data);
            start = start -> next;
            free(temp);
        } else {
            struct node *temp = start;
            for (int i = 1; i < pos - 1; i++) {
                if (temp == NULL) {
                    printf("Position not found\n\n");
                    return;
                }
                temp = temp -> next;
            }
            struct node *temp2 = temp -> next;
            printf("Deleted element: %d\n\n", temp2 -> data);
            temp -> next = temp2 -> next;
            free(temp2);
        }
    }
}


void display(){
    if (start == NULL)
        printf("List is empty\n\n");
    else {
        struct node *temp = start;
        printf("List: ");
        while (temp != NULL) {
            printf("%d ", temp -> data);
            temp = temp -> next;
        }
        printf("\n\n");
    }
}

int main(){
    int z;
    do{
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete from beginning\n5. Delete from end\n6. Delete from position\n7. Display\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &z);
        switch(z){
            case 1:
                ins_beg();
                break;

            case 2:
                ins_end();
                break;

            case 3:
                ins_pos();
                break;
          
            case 4:
                del_beg();
                break;
           
            case 5:
                del_end();
                break;

            case 6:
                del_pos();
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Exiting...\n");
                break;
            
            default:    
                printf("Invalid choice\n");
        }
    }while(z != 8);
}