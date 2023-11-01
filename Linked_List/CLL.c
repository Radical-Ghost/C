#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void ins_beg() {
    struct node *temp = head, *ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &ptr->data);
    if (head == NULL) {
        ptr->next = ptr;
        head = ptr;
    } else {
        ptr->next = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = ptr;
        head = ptr;
    }
}

void ins_end() {
    struct node *temp = head, *ptr =(struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &ptr->data);
    if (head == NULL) {
        ptr->next = ptr;
        head = ptr;
    }else{
        while (temp->next != head)
            temp = temp->next;
        temp->next = ptr;
        ptr->next = head;
    }
}

void ins_pos() {
    struct node *temp = head, *ptr =(struct node *)malloc(sizeof(struct node));
    int pos, i;
    
    printf("Enter position: ");
    scanf("%d", &pos);
    printf("Enter data: ");
    scanf("%d", &ptr->data);

    if (pos == 1)
        ins_beg();
    else {
        for (i = 1; i < pos - 1; i++)
            temp = temp->next;
        ptr->next = temp->next;
        temp->next = ptr;
    }
}

void del_beg() {
    if(head == NULL)
        printf("List is empty\n");
    else {
        struct node *temp = head;
        printf("Deleted element: %d\n", temp->data);
        while (temp->next != head)
            temp = temp->next;
        head = head->next;
        temp->next = head;
        free(temp);
    }
}

void del_end() {
    if(head == NULL) {
        printf("List is empty\n");
    } else {
        struct node *temp = head, *ptr = NULL;
        while (temp->next != head) {
            ptr = temp;
            temp = temp->next;
        }
        printf("Deleted element: %d\n", temp->data);
        if(ptr != NULL) {
            ptr->next = head;
        } else {
            head = NULL;
        }
        free(temp);
    }
}

void del_pos() {
    struct node *ptr, *temp = head;
    int i, pos;
    
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1)
        del_beg();
    else {
        for (i = 1; i < pos; i++) {
            if(temp->next == head) {
                if(i == pos - 1) {
                    del_end();
                    return;
                } else {
                    printf("Position out of range\n");
                    return;
                }
            }
            ptr = temp;
            temp = temp->next;
        }
        printf("Deleted element: %d\n", temp->data);
        ptr->next = temp->next;
        free(temp);
    }
}

void search() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    } else {
        int key, i = 1;
        struct node *temp = head;
        printf("Enter element to search: ");
        scanf("%d", &key);
        do {
            if (temp->data == key) {
                printf("Element found at %d\n", i);
                return;
            }
            i++;
            temp = temp->next;
        } while (temp != NULL);
        
        printf("Element not found\n");
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    } else {
        struct node *temp = head->next;
        printf("List: %d", head->data);
        while (temp != head) {
            printf(" %d", temp->data);
            temp = temp->next;
        }
    }
}

int main(){
    int c, x, pos;
    do{
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete from beginning\n5. Delete from end\n6. Delete from position\n7. Search\n8. Display\n9. Exit\nEnter choice: ");
        scanf("%d", &c);
        switch(c) {
            case 1: ins_beg(); break;
            case 2: ins_end(); break;
            case 3: ins_pos(); break;
            case 4: del_beg(); break;
            case 5: del_end(); break;
            case 6: del_pos(); break;
            case 7: search(); break;
            case 8: display(); break;
            case 9: break;
            default: printf("Invalid choice\n");
        }
    }while(c != 9);
    return 0;
}