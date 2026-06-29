#include <stdio.h>
void shellsort(int[],int);
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
    shellsort(a,n);
    printf("Sorted list:\n");
    for(i=0;i<n;i++)
    {
        printf("a[%d]=%d\n",i,a[i]);
    }
}
void shellsort(int a[],int n)
{
    int i,j,gap,temp;
    for(gap=n/2;gap>0;gap=gap/2)
    {
        for(i=gap;i<n;i++)
        {
            temp=a[i];
            j=i;
            while(j>=gap&&temp>a[j-gap])
            {
                a[j]=a[j-gap];
                j=j-gap;
            }
            a[j]=temp;
        }
    }
}
