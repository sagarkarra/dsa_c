#include <stdio.h>
void csort(int [],int);
void main()
{
    int a[10],n,i;
    printf("Enter the number of variables to be used:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the value of a[%d]:",i);
        scanf("%d",&a[i]);
    }
    csort(a,n);
    printf("Sorted list:\n");
    for(i=0;i<n;i++)
    {
        printf("a[%d]=%d\n",i,a[i]);
    }
}
void csort(int a[],int n)
{
    int output[10],i,max;
    max=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    int count[10];
    for(i=0;i<=max;i++)
    {
        count[i]=0;
    }
    for(i=0;i<n;i++)
    {
        count[a[i]]++;
    }
    for(i=1;i<=max;i++)
    {
        count[i]+=count[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        output[n-count[a[i]]]=a[i];
        count[a[i]]--;
    }
    for(i=0;i<n;i++)
    {
        a[i]=output[i];
    }
}