#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 111;
ll a[MAXN];

int main()
{
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    ll temp = 0;
    for (int i = 1; i <= m; ++i)
    {
        ll o, v1, v2;
        scanf("%lld",&o);
        if (o == 1)
        {
            scanf("%lld%lld",&v1, &v2);
            a[v1] = v2 - temp;
        }
        else if (o == 2)
        {
            scanf("%lld", &v1);
            temp += v1;
        }
        else {
            scanf("%lld", &v1);
            printf("%lld\n", a[v1] + temp);
        }
    }
    return 0;
}

