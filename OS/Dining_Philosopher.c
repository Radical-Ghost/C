#include <stdio.h>
#include <stdlib.h>

int chopstick[5];
int chop_owner[5];
int wait(int p) {
    if (chopstick[p] != 0) {
        chopstick[p] = 0;
        return 0;
    }
    return 1;
}

int signal(int q) {
    if (chopstick[q] != 1) {
        chopstick[q] = 1;
        return 0;
    }
    printf("\n_Neighbour is already eating!");
    return 1;
}

void eat(int chopstick[5]) {
    int p, i;
    printf("\nChopsticks available:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", chopstick[i]);
    }
    printf("\nChopsticks owner available:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", chop_owner[i]);
    }
    printf("\nWhich philosopher wants to eat?\n");
    scanf("%d", &p);
    int a = wait(p);
    if (a == 1 && chop_owner[p] != p) {
        printf("\nRequired chopstick is not available!");
        return;
    }
    int b = wait((p + 1) % 5);
    if (a == 1 && b == 1) {
        printf("\nPhilosopher%d is already eating!", p);
    } else if (a == 0 && b == 0) {
        chop_owner[p] = p;
        chop_owner[(p + 1) % 5] = p;
        printf("\nPhilosopher %d has started eating!\n", p);
    } else {
        chop_owner[p] = p;
        printf("\nRight chopstick is unavailable!\n");
    }
}

void think(int chopstick[5]) {
    int q;
    printf("\nWhich philosopher doesn't want to eat?\n");
    scanf("%d", &q);
    if (q == chop_owner[q]) {

        int r = signal(q);
        int s = signal((q + 1) % 5);
        if (r == 1 && s == 1) {
            printf("\nChopsticks are already available for eating.\n");
        } else {
            printf("Philosopher %d has started thinking\n", q);
        }
    } else {
        printf("\nNeighbour is already eating!");
    }
}
int main() {
    int i, choice;
    for (i = 0; i < 5; i++) {
        chopstick[i] = 1;
    }
    while (1) {
        printf("\n---Select activity---\n");
        printf("\n1. Philosopher wants to eat\n");
        printf("\n2. Philosopher wants to think\n");
        printf("\n3. EXIT\n");
        printf("\nSelect choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            eat(chopstick);
            break;
        case 2:
            think(chopstick);
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("\nInvalid Choice\n");
            break;
        }
    }
    return 0;
}