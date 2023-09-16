#include <stdio.h>
int tower(int n, char A[], char B[], char C[])
{
	if(n==1)
	{
		printf("\nMove Disk 1 from rod % to rod %s",A,B);
		return;	
	}	
	tower(n-1,A,C,B);
	printf("\nMove Disk %d from rod %s to rod %s",n,A,B);
	tower(n-1,C,B,A);
}

void main()
{
	int n;
	printf("Enter the no of disks: ");
	scanf("%d",&n);
	tower(n,"Origin","Final","Temporary");
}
