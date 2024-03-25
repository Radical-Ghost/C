#include <stdio.h>
#define max 10
#define INF 9999

int F[max][max];

void Relax(int i, int j, int k){
    if(F[i][j] > F[i][k] + F[k][j])
        F[i][j] = (F[i][k] + F[k][j]);
}

void Flyod(int n){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(i != j && F[i][j] == 0)
                F[i][j] = INF;

    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                Relax(i, j, k);
}

int main(){
    int i, j, n;
    printf("Entre no. of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix (if there is no connection enter 0):\n");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d", &F[i][j]);
            
    Flyod(n);
    
    printf("Shortest distances between all pairs of vertices:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(F[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", F[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}