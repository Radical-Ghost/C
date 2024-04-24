#include <stdio.h>

typedef struct {
    int value;
    int weight;
} Item;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, Item items[], int n, int included[]) {
    int i, j, v[n + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (j < items[i - 1].weight)
                v[i][j] = v[i - 1][j];
            else
                v[i][j] = max(v[i - 1][j], v[i - 1][j - items[i - 1].weight] +
                                               items[i - 1].value);
        }
    }

    j = W;
    for (i = n; i > 0 && j > 0; i--) {
        if (v[i][j] != v[i - 1][j]) {
            included[i - 1] = 1;
            j -= items[i - 1].weight;
        } else
            included[i - 1] = 0;
    }

    return v[n][W];
}

int main() {
    int W, n;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];
    int included[n];

    printf("Enter value and weight for: \n");
    for (int i = 0; i < n; i++) {
        printf("I%d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("Max Capacity: ");
    scanf("%d", &W);

    int K = knapSack(W, items, n, included);
    printf("Knapsack contains items: ");
    for (int i = 0; i < n; i++) {
        if (included[i]) {
            printf("I%d ", i + 1);
        }
    }

    printf("The Maximum value for knapsack of weight %d: %d\n", W, K);
    return 0;
}