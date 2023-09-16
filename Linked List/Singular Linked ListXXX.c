#include <stdio.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_at_beginning(int x)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    ptr->next = head;
    head = ptr;
}

void insert_at_end(int x)
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
}

void insert_at_position(int x, int pos)
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    ptr->next = NULL;
    if (pos == 1)
    {
        ptr->next = head;
        head = ptr;
    }
    else
    {
        temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
}

void delete_at_beginning()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        ptr = head;
        head = head->next;
        free(ptr);
    }
}

void delete_at_end()
{
    struct node *ptr, *temp;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else if (head->next == NULL)
    {
        ptr = head;
        head = NULL;
        free(ptr);
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        free(ptr);
    }
}

void delete_at_position(int pos)
{
    struct node *ptr, *temp;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else if (pos == 1)
    {
        ptr = head;
        head = head->next;
        free(ptr);
    }
    else
    {
        ptr = head;
        for (int i = 1; i < pos; i++)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        free(ptr);
    }
}

void display()
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main()
{
    int c, x, pos;
    while (1)
    {
        printf("1.Insert at beginning\n2.Insert at end\n3.Insert at position\n4.Delete at beginning\n5.Delete at end\n6.Delete at position\n7.Display\n8.Exit\n");
        printf("Enter your c: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &x);
            insert_at_beginning(x);
            break;
        case 2:
            printf("Enter the element: ");
            scanf("%d", &x);
            insert_at_end(x);
            break;
        case 3:
            printf("Enter the element: ");
            scanf("%d", &x);
            printf("Enter the position: ");
            scanf("%d", &pos);
            insert_at_position(x, pos);
            break;
        case 4:
            delete_at_beginning();
            break;
        case 5:
            delete_at_end();
            break;
        case 6:
            printf("Enter the position: ");
            scanf("%d", &pos);
            delete_at_position(pos);
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}