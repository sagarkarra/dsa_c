#include <stdio.h>
void msort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);

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
    
    msort(a,0,n-1);
    printf("Sorted array is:\n");
    for(i=0;i<n;i++)
    {
        printf("a[%d]=%d\n",i,a[i]);
    }
}

void msort(int a[10],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        msort(a,low,mid);
        msort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void merge(int a[10],int low,int mid,int high)
{
    int i,j,k,temp[10];
    i=k=low;
    j=mid+1;
    while((i<=mid)&&(j<=high))
    {
        if (a[i]>=a[j])
        {
            temp[k]=a[i];
            i++;
        }
        else
        {
            temp[k]=a[j];
            j++;
        }
        k++;
    }
    
    while(i<=mid)
    {
        temp[k]=a[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        temp[k]=a[j];
        j++;
        k++;
    }
    
    for(i=low;i<=high;i++)
    {
        a[i]=temp[i];
    }
}