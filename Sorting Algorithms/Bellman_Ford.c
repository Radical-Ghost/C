#include <stdio.h>

#define inf 9999
#define max 10

void print_final_table(int n, int dist[], int prev[]) {
    int i;
    printf("-");
    for (i = 0; i <= n; i++)
        printf("----------------");
    printf("\n|\tV\t|");
    for (i = 0; i < n; i++)
        printf("\t%d\t|", i + 1);
    printf("\n");

    printf("-");
    for (i = 0; i <= n; i++)
        printf("----------------");
    printf("\n|\td[V]\t|");
    for (i = 0; i < n; i++)
        printf("\t%d\t|", dist[i]);
    printf("\n");

    printf("-");
    for (i = 0; i <= n; i++)
        printf("----------------");
    printf("\n|\tP[V]\t|");
    for (i = 0; i < n; i++)
        printf("\t%d\t|", prev[i]);
    printf("\n");

    printf("-");
    for (i = 0; i <= n; i++)
        printf("----------------");
}

void bellman_ford(int n, int G[n][n], int start_node) {
    int dist[n], prev[n], i, j, k;

    for (i = 0; i < n; i++) {
        dist[i] = inf;
        prev[i] = -1;
    }

    dist[start_node] = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                if (G[j][k] && dist[j] != inf && dist[j] + G[j][k] < dist[k]) {
                    dist[k] = dist[j] + G[j][k];
                    prev[k] = j + 1;
                }
            }
        }
    }

    // Check for negative weight cycles
    for (j = 0; j < n; j++) {
        for (k = 0; k < n; k++) {
            if (G[j][k] != 0 && dist[j] != inf && dist[j] + G[j][k] < dist[k]) {
                printf("Graph contains a negative-weight cycle\n");
                return;
            }
        }
    }

    print_final_table(n, dist, prev);
}

int main() {
    int i, j, n, start_node;

    printf("Enter no. of vertices: ");
    scanf("%d", &n);

    int G[n][n];

    printf("Enter the adjacency matrix: ");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    printf("Enter the starting node: ");
    scanf("%d", &start_node);

    bellman_ford(n, G, start_node - 1);

    return 0;
}