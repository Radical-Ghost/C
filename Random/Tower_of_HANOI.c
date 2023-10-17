#include <stdio.h>
int i = 0;
void tower(int n, char A[], char B[], char C[]) {
	if(n==1)
	{
		i++;
		printf("\nMove Disk 1 from rod %s to rod %s",A,B);
		return;	
	}	
	tower(n-1,A,C,B);
	i++;
	printf("\nMove Disk %d from rod %s to rod %s",n,A,B);
	tower(n-1,C,B,A);
}

void main() {
	int n;
	printf("Enter the no of disks: ");
	scanf("%d",&n);
	tower(n,"Origin","Final","Temporary");
	printf("\nTotal no of moves: %d",i);
}
