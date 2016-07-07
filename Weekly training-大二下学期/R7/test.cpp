#include <stdio.h>
#include <string.h>
#include <algorithm>
using  namespace std;
const int maxn=20;
int a[maxn],b[maxn],c[maxn];
int main()
{
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int i,j;
    int n,T,cas=1;
    while(scanf("%d",&n)!=EOF,n)
    {
        for(i=0; i<n; i++)
            scanf("%d %d %d",&a[i],&b[i],&c[i]);
        for(i=0; i<100000; i++)
        {
            int cont=0;
            for(j=0; j<n; j++)
            {
                T=a[j]+b[j];
                if((i+c[j]-1)%T<a[j]) cont++;//醒；
                else cont--;
            }
            if(cont>0)
                break;
        }
        printf("Case %d: ",cas++);
        if(i>=100000)
            printf("-1\n");
        else
        {
            int ans=-1;
            for(j=0; j<n; j++)
            {
                T=a[j]+b[j];
                if((i+c[j]-1)%T>=a[j])//醒；
                    ans=max(ans,T-(i+c[j]-1)%T);
            }
            printf("%d\n",i+ans+1);
        }
    }
    return 0;
}
