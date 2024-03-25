# include <stdio.h>
#define inf 9999
#define max 10

void bellman(int n, int B[max][max], int u){
	int dist[n], prev[n], i, j, count;
		
	for(i=0; i<n; i++){
		dist[i] =inf;
		prev[i] = -1;
	}
	
	dist[u] = 0;
	
	for(count=0; count<n-1; count++)
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				if(B[i][j] != 0 && dist[i] != inf && dist[i] + B[i][j] < dist[j]){
					dist[j] = dist[i] + B[i][j];
					prev[j] = i;
				}	

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if(B[i][j] != 0 && dist[i] != inf && dist[i] + B[i][j] < dist[j]){
				printf("graph contains negative weight cycle!!\n BellmanFord cannot be applied");
				return;
			}

	for(i=0; i<n; i++){
		if(i != u){
			printf("\n\nDistance of node %d : %d", i, dist[i]);
			printf("\nShortest Path: %d", i);
			j = i;
			do{
				j = prev[j];
				printf("<-%d", j);
			}while(j != u);
		}
	}
}

int main(){
	int B[max][max], i, j, u, n;
	printf("Enter no. of vertices: ");
	scanf("%d", &n);
	
	printf("Enter the adjacency matrix: ");
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%d", &B[i][j]);
			
	printf("Enter starting Node: ");
	scanf("%d", &u);
	
	bellman(n, B, u);
	
	return 0;
}