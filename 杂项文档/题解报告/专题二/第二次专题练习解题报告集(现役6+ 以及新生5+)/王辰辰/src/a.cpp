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
typedef pair<int,int> P;
const int inf = 0x3f3f3f3f;
const int maxn = 1005;
const ll mod = 1e9 + 7;
ll dp[50], a[505];
map<ll, int>mp;
struct mat {
    int n, m;
    ll a[5][5];
    void clr() {
        memset(a,0,sizeof(a));
    }
    void biao() {
        clr();
        for(int i = 0; i < n; i++) a[i][i] = 1;
    }
}I, ini, have;

void init() {
    if(mp[0]) dp[0] = 0;
    else dp[0] = 1;
    if(mp[1]) dp[1] = 0;
    else dp[1] = dp[0];
    if(mp[2]) dp[2] = 0;
    else dp[2] = dp[1] + dp[0];
}

void initmat() {
    I.n = I.m = 3;
    I.biao();
    ini.n = ini.m = 3;
    ini.clr();
    ini.a[0][0] = ini.a[0][1] = ini.a[0][2] = 1;
    ini.a[1][0] = ini.a[2][1] = 1;
    have.n = have.m = 3;
    have.clr();
    have.a[1][0] = have.a[2][1] = 1;
}

mat mul(mat &a, mat &b) {
    mat c;
    c.n = a.n; c.m = b.m;
    c.clr();
    for(int i = 0; i < a.n; i++) {
        for(int k = 0; k < b.n; k++) {
            if(a.a[i][k] == 0) continue;
            for(int j = 0; j < b.m; j++)
                c.a[i][j] = (c.a[i][j] + a.a[i][k]*b.a[k][j])%mod;
        }
    }
    return c;
}

mat pow_mod(mat &a, ll n) {
    if(n == 0) return I;
    mat ans = pow_mod(a, n/2);
    ans = mul(ans, ans);
    if(n % 2) ans = mul(ans, a);
    return ans;
}

int main()
{
	#ifdef LOCAL
	freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
	#endif // LOCAL
	int t; scanf("%d", &t);
	initmat();
	while(t--) {
        ll n; int m;
        scanf("%lld%d", &n, &m);
        mp.clear();
        for(int i = 1; i <= m; i++) {
            scanf("%lld", &a[i]);
            mp[a[i]] = 1;
        }
        sort(a + 1, a + 1 + m);
        init();
        if(n < 3) {
            printf("%lld\n",dp[n]); continue;
        }
        ll pos = 2;
        mat ans = I;
        mat rans;
        rans.n = 3; rans.m = 1;
        for(int i = 0; i < 3; i++) rans.a[2 - i][0] = dp[i];
        for(int i = 1; i <= m; i++) {
            if(a[i] <= pos) continue;
            if(a[i] > n) continue;
            mat temp = pow_mod(ini ,a[i] - pos - 1);
            ans = mul(temp, ans);
            ans = mul(have, ans);
            pos = a[i];
        }
        mat temp = pow_mod(ini, n - pos);
        ans = mul(temp, ans);
        ans = mul(ans, rans);
        printf("%lld\n", ans.a[0][0]);
	}
	return 0;
}
