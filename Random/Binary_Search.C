#include <stdio.h>
int a[50];

void insort(int n)
{
    int i,j,t;
    
    for(i=1;i<n;i++)
    {
        t=a[i];
        for(j=i-1;j>=0 && a[j]>t;j--)
            a[j+1]=a[j];
        a[j+1]=t;
    }   
}

int binary(int n)
{
    int i,p,h=n-1,l=0;
    
    insort(n);

    printf("Sorted list is: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
        
    printf("\nEnter the number to be searched: ");
    scanf("%d",&p);

    while(l<=h)
    {
        int m=(l+h)/2;
        if(a[m]==p)
            return m;
        if(a[m]<p)
            l=m+1;
        if(a[m]>p)
            h=m-1;
    }
    return -1;
}

int main()
{
    int n,i,z;

    printf("Enter the number of elements: ");
    scanf("%d",&n);
    
    printf("Enter a array: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    z=binary(n);

    if(z==-1)
        printf("Element not found.");
    else printf("Element found %d.",z+1);

    return 0;
}
