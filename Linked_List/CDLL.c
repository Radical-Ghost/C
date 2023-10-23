#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node  *start = NULL; 

void ins_beg(int x) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr -> data = x;
    if (start == NULL) {
        ptr -> prev = ptr;
        ptr -> next = ptr;
        start = ptr;
    } else {
        ptr -> prev = start -> prev;
        ptr -> next = start;
        start -> prev -> next = ptr;
        start -> prev = ptr;
        start = ptr;
    }
}

void ins_end(int x) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr -> data = x;
    if (start == NULL) {
        ptr -> prev = ptr;
        ptr -> next = ptr;
        start = ptr;
    } else {
        ptr -> prev = start -> prev;
        ptr -> next = start;
        start -> prev -> next = ptr;
        start -> prev = ptr;
    }
}

void ins_pos(int x, int pos) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (pos == 1)
        ins_beg(x);
    else {
        struct node *temp = start;
        for (int i = 1; i < pos - 1; i++) {
            if (temp -> next == start) {
                printf("Position not found\n\n");
                return;
            }
            temp = temp -> next;
        }
        ptr -> data = x;
        ptr -> prev = temp;
        ptr -> next = temp -> next;
        temp -> next -> prev = ptr;
        temp -> next = ptr;
    }
}

void del_beg() {
    if(start == NULL)
        printf("List is empty\n\n");
    else if (start->next == start) {
        printf("Deleted Node: %d\n\n", start->data);
        start = NULL;
    }
    else {   
        start->next->prev = start->prev;
        start->prev->next = start->next;
        printf("Deleted Node: %d\n\n", start->data);
        start = start->next;
    }
}

void del_end() {
    if(start == NULL)
        printf("List is empty");
    else if (start->next == start) {
        printf("Deleted Node: %d\n\n", start->data);
        start = NULL;
    }
    else {
        start->prev->prev->next = start;
        printf("Deleted Node: %d\n\n", start->prev->data);
        start->prev = start -> prev -> prev;
    }
}

void del_pos(int pos) {
    if(start == NULL)
        printf("List is empty\n\n");
    else if (pos == 1) {
        del_beg();
    }
    else {
        struct node *temp = start;
        for(int i = 1; i < pos - 1; i++) {
            if(temp->next == start) {
                printf("Position not found\n\n");
                return;
            }
            temp = temp->next;
        } 
        temp->next->next ->prev = temp;
        printf("Deleted Node: %d\n\n", temp->next->data);
        temp->next = temp->next->next;
    }
}

void display() {
    if(start == NULL)
        printf("List is empty\n\n");
    else {
        struct node *temp = start;
        printf("List: ");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != start);
        printf("\n\n");
    }
}

int main() {
    int c, x, pos;
    do{
        system("cls");
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete from beginning\n5. Delete from end\n6. Delete from position\n7. Display\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch(c){
            case 1:
                printf("Enter the data: ");
                scanf("%d", &x);
                ins_beg(x);
                break;

            case 2:
                printf("Enter the data: ");
                scanf("%d", &x);
                ins_end(x);
                break;

            case 3:
                printf("Enter the data: ");
                scanf("%d", &x);
                printf("Enter the position: ");
                scanf("%d", &pos);
                ins_pos(x, pos);
                break;
          
            case 4:
                del_beg();
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
                printf("Exiting...\n");
                break;
            
            default:    
                printf("Invalid choice\n");
        }
        system("pause");
    }while(c != 8);
    return 0;
}