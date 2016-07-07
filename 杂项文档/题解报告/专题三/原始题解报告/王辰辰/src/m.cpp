#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<utility>
#include<sstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f;
const int maxn = 1005;

ll a[20], dp[500100];
bool leap[500100];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
    #endif // LOCAL
    int t; scanf("%d", &t);
    while(t--) {
        ll n, bmin, bmax;
        scanf("%lld%lld%lld", &n, &bmin, &bmax);
        for(ll i = 1; i <= n; i++) scanf("%lld", &a[i]);
        //memset(dp, -1, sizeof(dp));
        memset(leap, false, sizeof(leap));
        for(int i = 0; i < a[1]; i++) dp[i] = 1e12;
        dp[0] = 0; leap[0] = true;
        queue<ll> p; p.push(0);
        while(p.size()) {
            ll u = p.front(); p.pop();
            leap[u] = false;
            for(ll i = 2; i <= n; i++) {
                ll now = (u + a[i]) % a[1];
                if(dp[now] > dp[u] + a[i]) {
                    dp[now] = dp[u] + a[i];
                    if(!leap[now]) {
                        leap[now] = true;
                        p.push(now);
                    }
                }
            }
        }
        ll ans = 0;
        for(ll i = 0; i < a[1]; i++) {
            if(dp[i] == -1) continue;
            if(dp[i] > bmax) continue;
            ll ans1, ans2;
            if(dp[i] >= bmin) ans1 = 0;
            else ans1 = (bmin - dp[i] - 1) / a[1] + 1;
            ans2 = (bmax - dp[i]) / a[1] + 1;
            ans = ans + ans2 - ans1;
            //cout<<dp[i]<<" "<<ans1<<" "<<ans2<<endl;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
