#include <stdio.h>
#define MAX_SIZE 32

int stack[MAX_SIZE];
int top = -1;

void push(int x){
    top++;
    stack[top] = x;
}

int pop(){
    int x = stack[top];
    top--;
    return x;
}

int main(){
    int n,r;
    printf("Enter a decimal number: "); 
    scanf("%d", &n);

    while(n > 0){
        r = n % 2;
        push(r);
        n /= 2;
    }

    printf("Binary: ");
    while(top != -1){
        printf("%d", pop());
    }
    printf("\n");

    return 0;
}