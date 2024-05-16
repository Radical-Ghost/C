#include <stdio.h>
#include <stdlib.h>

int chopstick[5] = {1, 1, 1, 1, 1};
int chop_owner[5] = {-1, -1, -1, -1, -1};

int wait(int p) {
    if (chopstick[p] == 1) {
        chopstick[p] = 0;
        return 0;
    }
    return 1;
}

int signal(int q) {
    if (chopstick[q] == 0) {
        chopstick[q] = 1;
        return 0;
    }
    return 1;
}

void eat() {
    int p;

    printf("\nEnter the philosopher number who wants to eat: ");
    scanf("%d", &p);

    if (p < 0 || p >= 5) {
        printf("\nInvalid philosopher number!\n");
        return;
    }

    int a = wait(p);
    int b = wait((p + 1) % 5);

    if (a == 0 && b == 0) {
        if (chop_owner[p] == -1 && chop_owner[(p + 1) % 5] == -1) {
            chop_owner[p] = p;
            chop_owner[(p + 1) % 5] = p;
            printf("\nPhilosopher %d has started eating!\n", p);
        } else {
            printf("\nPhilosopher %d is already eating!\n", p);
        }
    } else {
        printf("\nRequired chopsticks are not available for philosopher %d!\n",
               p);
        chopstick[p] = 1;
        chopstick[(p + 1) % 5] = 1;
    }
}

void think() {
    int q;

    printf("\nEnter the philosopher number who wants to think: ");
    scanf("%d", &q);

    if (q < 0 || q >= 5) {
        printf("\nInvalid philosopher number!\n");
        return;
    }

    if (chop_owner[q] == q && chop_owner[(q + 1) % 5] == q) {
        signal(q);
        signal((q + 1) % 5);
        chop_owner[q] = -1;
        chop_owner[(q + 1) % 5] = -1;
        printf("\nPhilosopher %d has started thinking!\n", q);
    } else {
        printf("\nPhilosopher %d cannot think as not owning both chopsticks!\n",
               q);
    }
}

int main() {
    int choice;

    while (1) {
        printf("---Select activity---\n1. Philosopher wants to eat\n2. "
               "Philosopher wants to think\n3. EXIT\nSelect choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            eat();
            break;
        case 2:
            think();
            break;
        case 3:
            exit(0);
        default:
            printf("\nInvalid Choice\n");
            break;
        }
    }
    return 0;
}