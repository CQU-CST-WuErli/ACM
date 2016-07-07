//
//  Created by Running Photon on 2016-04-03
//  Copyright (c) 2015 Running Photon. All rights reserved.
//
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <stack>
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x,begin())
#define ll long long
#define CLR(x) memset(x, 0, sizeof x)
using namespace std;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int maxn = 5e5 + 10;
const int maxv = 1e3 + 10;
const double eps = 1e-9;

///父亲节点
int pre[maxn];
///子树节点数
int cnt[maxn];
///出度
int out[maxn];
ll mod, n;
int nprime[maxn];
int cprime[maxn];
int maxprime[maxn];
void getPrime() {
    nprime[0] = nprime[1] = 1;
    int c = 0;
    for(int i = 2; i < maxn; i++) {
        if(!nprime[i]) {
            maxprime[i] = i;
            for(int j = i + i; j < maxn; j += i) {
                maxprime[j] = i;
                nprime[j] = 1;
            }
        }
    }
}
ll pow_mod(ll a, ll n) {
    ll ret = 1;
    while(n) {
        if(n & 1) ret = ret * a % mod;
        n >>= 1;
        a = a * a % mod;
    }
    return ret;
}
void init() {
    scanf("%lld%lld", &n, &mod);
    CLR(out);
    for(int i = 2; i <= n; i++) {
        scanf("%d", pre + i);
        out[pre[i]]++;
    }
    queue <int> que;
    for(int i = 1; i <= n; i++) {
        cnt[i] = 1;
        if(!out[i]) que.push(i);
    }
    while(que.size()) {
        int u = que.front();
        que.pop();
        cnt[pre[u]] += cnt[u];
        out[pre[u]]--;
        if(out[pre[u]] == 0) que.push(pre[u]);
    }
}
void calc(int a, int add) {
    while(a != 1) {
        int t = maxprime[a];
        cprime[t] += add;
        a /= t;
    }
}
void sol() {
    init();
    CLR(cprime);
    for(int i = 1; i <= n; i++) {
//        printf("cnt[%d] = %d\n", i, cnt[i]);
    }
    for(int i = 2; i < n; i++) {
        calc(i, 1);
    }
    for(int i = 2; i <= n; i++) {
        calc(cnt[i], -1);
    }
    ll ans = 1;
    for(int i = 2; i <= n; i++) {
        if(cprime[i]) {
//            printf("%d  %d\n", i, cprime[i]);
            ans = (ans * pow_mod(i, cprime[i])) % mod;
        }
    }
    printf("%lld\n", ans);
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt","w",stdout);
#endif
//	ios_base::sync_with_stdio(0);
    int T;
    getPrime();
    scanf("%d", &T);
    while(T--) {
        sol();
    }

	return 0;
}
