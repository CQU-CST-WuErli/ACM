#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}

int arr[50]={0};

int main(void)
{
    int n, k, number, status=0;
    int i;
    scanf("%d %d", &n, &k);
    for( i=0; i<n; i++)
        scanf("%d", &arr[i]);

    qsort( arr, n, sizeof(int), cmp);
    for( i=1; i<=k; i++)
    {
        if( i>n)
        {
            i=n;
            status=1;
            break;
        }
    }
    i--;
    if( status)
        printf("-1\n");
    else
        printf("%d 0\n", arr[i-1]);

    return 0;
}
