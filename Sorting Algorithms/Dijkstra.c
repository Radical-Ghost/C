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

void dijkstra(int n, int G[n][n], int start_node) {
    int dist[n], prev[n], visited[n], i, v;

    for (i = 0; i < n; i++) {
        dist[i] = inf;
        prev[i] = -1;
        visited[i] = 0;
    }

    dist[start_node] = 0;

    for (i = 0; i < n - 1; i++) {
        int min = inf, min_index;

        for (v = 0; v < n; v++)
            if (!visited[v] && dist[v] <= min)
                min = dist[v], min_index = v;

        int u = min_index;
        visited[u] = 1;

        for (v = 0; v < n; v++)
            if (!visited[v] && G[u][v] && dist[u] != inf &&
                dist[u] + G[u][v] < dist[v]) {
                dist[v] = dist[u] + G[u][v];
                prev[v] = u + 1;
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

    dijkstra(n, G, start_node - 1);

    return 0;
}