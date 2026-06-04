#include <stdio.h>
void main()
{
    int a[10],n,i,j,temp;
    printf("Enter the number of variables to be used:");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        printf("Enter the value of a[%d]:",i);
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++)
    {
        j=i;
        while((j>0)&&a[j]<a[j-1])
        {
            temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
            j--;
        }
    }
    printf("Sorted array:\n");
    for(i=0;i<n;i++)
    {
        printf("a[%d]=%d\n",i,a[i]);
    }
}