#include <stdio.h>
void radix_sort(int [],int);
void counting_sort(int [],int,int);
int maximum(int [],int);
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
    radix_sort(a,n);
    printf("Sorted list:\n");
    for(i=0;i<n;i++)
    {
        printf("a[%d]=%d\n",i,a[i]);
    }
}
void counting_sort(int a[],int n, int place)
{
    int output[10],i,index;
    int count[10]={0};
    for(i=0;i<n;i++)
    {
        index=(a[i]/place)%10;
        count[index]++;
    }
    for(i=1;i<10;i++)
    {
        count[i]+=count[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        index=(a[i]/place)%10;
        output[count[index]-1]=a[i];
        count[index]--;
    }
    for(i=0;i<n;i++)
    {
        a[i]=output[i];
    }
}
void radix_sort(int a[],int n)
{
    int max,place;
    max=maximum(a,n);
    for(place=1;max/place>0;place*=10)
    {
        counting_sort(a,n,place);
    }
}
int maximum(int a[],int n)
{
    int i,max;
    max=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    return max;
}