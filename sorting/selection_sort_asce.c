#include <stdio.h>
void main()
{
    int a[10],n,i,j,temp,min_pos;
    printf("Enter the number of variables to be used:");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        printf("Enter the value of a[%d]:",i);
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        min_pos=i;
        for(j=i+1;j<n;j++)
        {
            if (a[j]<a[min_pos])
            {
              min_pos=j;
            }
        }
        temp=a[i];
        a[i]=a[min_pos];
        a[min_pos]=temp;
    }
    
    printf("Sorted array is:\n");
    for(i=0;i<n;i++)
    {
        printf("a[%d]=%d\n",i,a[i]);
    }
}