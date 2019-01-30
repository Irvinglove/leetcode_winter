#include <stdio.h>
#include <string.h>
void main()
{
    int   i,k=1,j=10,a[10];
    int n;
    printf("请输入数组的长度\n");
    scanf("%d", &n);
    printf("请输入数据\n");
    for(i=0;i<n;i++)
    scanf("%d", &a[i]);
    for(k=i=1;i<10;i++)
        {
            for(j=0;j<k;j++)
            {
                if(a[j]==a[i])  break;
            }
            if(j==k)
                a[k++]=a[i];
        }
        printf(" \n ");
    for(i=0;i<k;i++)
        {
            printf(" %d ",a[i]);
        }
}
