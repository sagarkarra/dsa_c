#include <stdio.h>
void qsort(int a[10],int,int);
void main()
{
    int a[10],n,i;
    printf("Enter the number of variables to be used:\n");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        printf("Enter the value of a[%d]:",i);
        scanf("%d",&a[i]);
    }
    qsort(a,0,n-1);
    printf("Sorted list:\n");
    for(i=0;i<n;i++)
    {
        printf("a[%d]=%d\n",i,a[i]);
    }
}
void qsort(int a[],int first,int last)
{
    int i,j,pivot,temp;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;
        while(i<j)
        {
            while(a[i]<=a[pivot])
            {
                i++;
            }
            while(a[j]>a[pivot])
            {
                j--;
            }
            if(i<j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp=a[pivot];
        a[pivot]=a[j];
        a[j]=temp;

        qsort(a,first, j - 1);
        qsort(a, j + 1, last);
    }
}