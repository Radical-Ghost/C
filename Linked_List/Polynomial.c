#include<stdio.h>
#include<stdlib.h>

struct node {
    float coef;
    int expo;
    struct node* next;
};

struct node* insert(struct node* head, float coef, int expo) {
    struct node* ptr = (struct node *)malloc(sizeof(struct node));
    ptr->coef = coef;
    ptr->expo = expo;
    ptr->next = NULL;

    if(head == NULL || head->expo < expo) {
        ptr->next = head;
        head = ptr;
    } else {
        struct node* temp = head;
        while(temp->next != NULL && temp->next->expo >= expo)
            temp = temp->next;
        ptr->next = temp->next;
        temp->next = ptr;
    }

    return head;
}

struct node* add(struct node* head1,struct node* head2) {
    struct node* temp1=head1;
    struct node* temp2=head2;
    struct node* result=NULL;
    
    while(temp1 != NULL && temp2 != NULL)
        if(temp1->expo == temp2->expo) {
            result = insert(result, temp1->coef + temp2->coef, temp1->expo);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if(temp1->expo > temp2->expo) {
            result = insert(result, temp1->coef, temp1->expo);
            temp1 = temp1->next;
        } else if(temp2->expo > temp1->expo){
            result = insert(result, temp2->coef, temp2->expo);
            temp2 = temp2->next;
        }

    while(temp1 != NULL) {
        result = insert(result, temp1->coef, temp1->expo);
        temp1 = temp1->next;
    }

    while(temp2 != NULL) {
        result = insert(result, temp2->coef, temp2->expo);
        temp2 = temp2->next;
    }
    return result;
}

struct node* create(struct node* head) {
    int n,expo;
    float coef;
    
    printf("Enter the number of terms: ");
    scanf("%d",&n);

    for(int i=0; i<n; i++) {
        printf("\nEnter the exponent of term %d: ",i+1);
        scanf("%d",&expo);

        printf("\nEnter the coefficient of term %d: ",i+1);
        scanf("%f",&coef);

        head = insert(head, coef, expo);
    }

    printf("\n\n");
    return head;
}

print(struct node* head) {
    if(head == NULL)
        printf("No Polynomial\n");
    else {
        struct node* temp = head;
        while(temp != NULL) {
            printf("%.0fx^%d", temp->coef, temp->expo);
            temp = temp->next;
            if(temp != NULL)
                printf(" + ");
        }
    }
}

int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* result = NULL;

    head1 = create(head1);
    head2 = create(head2);

    result = add(head1,head2);

    print(result);

    return 0;
}