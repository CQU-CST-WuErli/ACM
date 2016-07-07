#include <stdio.h>

int main()
{
    int n,num,sum;
    sum = 0;
    scanf("%d",&n);
    while (n!=0)
      {
         for (int i=1;i<=n;i++)
         {
                  scanf("%d",&num);
                  sum = sum + num;
         }
         printf("%d\n",sum);
      }
    return 0;
}
