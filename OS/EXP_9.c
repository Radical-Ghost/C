#include <stdio.h>

void firstFit(int blockSizes[], int m, int processSizes[], int n) {
    int allocation[n];

    for (int i = 0; i < n; i++) {
        allocation[i] =
            -1; 
        for (int j = 0; j < m; j++) {
            if (blockSizes[j] >= processSizes[i]) {
                allocation[i] = j;
                blockSizes[j] -= processSizes[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSizes[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void bestFit(int blockSizes[], int m, int processSizes[], int n) {
    int allocation[n];

    for (int i = 0; i < n; i++) {
        allocation[i] =
            -1;
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSizes[j] >= processSizes[i]) {
                if (bestIdx == -1 || blockSizes[bestIdx] > blockSizes[j])
                    bestIdx = j;
            }
        }

        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSizes[bestIdx] -= processSizes[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSizes[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void worstFit(int blockSizes[], int m, int processSizes[], int n) {
    int allocation[n];

    for (int i = 0; i < n; i++) {
        allocation[i] =
            -1;
        int worstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSizes[j] >= processSizes[i]) {
                if (worstIdx == -1 || blockSizes[worstIdx] < blockSizes[j])
                    worstIdx = j;
            }
        }

        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSizes[worstIdx] -= processSizes[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSizes[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int m, n, choice;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    int blockSizes[m];
    printf("Enter the sizes of the memory blocks: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &blockSizes[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processSizes[n];
    printf("Enter the sizes of the processes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processSizes[i]);
    }

    printf("Choose the memory allocation strategy:\n");
    printf("1. First Fit\n");
    printf("2. Best Fit\n");
    printf("3. Worst Fit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        printf("\nFirst Fit:\n");
        firstFit(blockSizes, m, processSizes, n);
        break;
    case 2:
        printf("\nBest Fit:\n");
        bestFit(blockSizes, m, processSizes, n);
        break;
    case 3:
        printf("\nWorst Fit:\n");
        worstFit(blockSizes, m, processSizes, n);
        break;
    default:
        printf("Invalid choice.\n");
    }

    return 0;
}
