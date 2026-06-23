#include <stdio.h>
#define MAX 100
void bucketsort(int[],int);
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
    bucketsort(a,n);
    printf("Sorted list:\n");
    for(i=0;i<n;i++)
    {
        printf("a[%d]=%d\n",i,a[i]);
    }
}
void bucketsort(int a[],int n)  
{
    int i,j,k,max,temp,bucket_count,bucket_index;
    int buckets[MAX][MAX];
    int bucket_sizes[MAX]={0};
    max=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]<max)
        {
            max=a[i];
        }
    }
    bucket_count=n;
    for(i=0;i<n;i++)
    {
        bucket_index=(a[i]*bucket_count)/(max+1);
        buckets[bucket_index][bucket_sizes[bucket_index]++]=a[i];
    }
    for(i=0;i<bucket_count;i++)
    {
        for(j=1;j<bucket_sizes[i];j++)
        {
            temp=buckets[i][j];
            k=j-1;
            while(k>=0&&temp>buckets[i][k])
            {
                buckets[i][k+1]=buckets[i][k];
                k--;
            }
            buckets[i][k+1]=temp;
        }
    }
    k=0;
    for(i=bucket_count-1;i>=0;i--)
    {
        for(j=0;j<bucket_sizes[i];j++)
        {
            a[k++]=buckets[i][j];
        }
    }
}
