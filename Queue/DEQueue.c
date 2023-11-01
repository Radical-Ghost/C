#include <stdio.h>
#define N 5
int queue[N];
int f = -1, r = -1;

void insF() {
    if((f == 0 && r == N-1) || f == r + 1)
        printf("Overflow");
    else {
        printf("Enter the element: ");
        int x;
        scanf("%d", &x);

        if(f == -1 && r == -1) {
            f = r = 0;
            queue[f] = x;
        }
        else if(f == 0) {
            f = N-1;
            queue[f] = x;
        }
        else queue[--f] = x;
    }
}

void insR() {
    if((f == 0 && r == N-1) || f == r + 1)
        printf("Overflow");
    else {
        printf("Enter the element: ");
        int x;
        scanf("%d", &x);
    
         if(f == -1 && r == -1) {
            f = r = 0;
            queue[r] = x;
        }
        else if(r == N-1) {
            r = 0;
            queue[r] = x;
        }
        else queue[++r] = x;
    }
}

void delF() {
    if(f == -1 && r == -1)
        printf("Underflow");
    else if(f == r) {
        printf("Deleted element: %d", queue[f]);
        r = f = -1;
    }
    else if(f == N - 1) {
        printf("Deleted element: %d", queue[f]);
        f = 0;
    }
    else printf("Deleted element: %d", queue[f++]);
}

void delR() {
    if(f == -1 && r == -1)
        printf("Underflow");
    else if(f == r) {
        printf("Deleted element: %d", queue[r]);
        r = f = -1;
    }
    else if(r == 0) {
        printf("Deleted element: %d", queue[r]);
        r = N - 1;
    }
    else printf("Deleted element: %d", queue[r--]);
}

void display() {
    if(f == -1 && r == -1)
        printf("Underflow");
    else {
        int i = f;
        while(1) {
            printf("%d ", queue[i]);
            if(i == r)
                break;
            i = (i+1)%N;
        }
        printf("\n");
    }
}

int main() {
    int c;
    do {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\nEnter your choice: ");
        scanf("%d", &c);
        switch(c) {
            case 1: insF(); break;
            case 2: insR(); break;
            case 3: delF(); break;
            case 4: delR(); break;
            case 5: display(); break;
            case 6: break;
            default: printf("Invalid choice");
        }
    }while(c != 6);
    return 0;
}