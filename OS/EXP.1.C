#include <stdio.h>

int main(){
    int n, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], at[n], t=0, wt[n], tat[n];

    printf("Enter burst time and access of processes: \n");
    for(i=0; i<n; i++){
        printf("Enter burst time and access time for process %d: ", i+1);
        scanf("%d %d", &bt[i], &at[i]);
    }

    wt[0] = 0;
    for(i=1; i<n; i++)
        wt[i] = wt[i-1] + bt[i-1] - at[i];

    for(i=0; i<n; i++){
        t += bt[i];
        tat[i] = t - at[i];
    }

    //table
    for(i=0; i<16*n+1; i++)
        printf("_");
    printf("\n");
    for(i=0; i<n; i++)
        printf("|\tP%d\t", i+1);
    printf("|\n");
    for(i=0; i<16*n+1; i++)
        printf("_");
    printf("\n");
    for(i=0; i<n; i++)
        printf("%d\t\t", wt[i]);
    printf("%d\n", wt[n-1]+bt[n-1]);

    int avg_wt=0, avg_tat=0;
    for(i=0; i<n; i++){
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    
    printf("Average waiting time: %f\n", (float)avg_wt/n);
    printf("Average turn around time: %f\n", (float)avg_tat/n); 

    return 0;  
}