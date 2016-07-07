// SOJ 右键背包.cpp : 定义控制台应用程序的入口点。
//

#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
int n;//层数
ll V;//总体积
const int MAXN = 1e5 + 10;
ll dp[MAXN];
ll Max(ll a, ll b){ return a > b ? a : b; }
void comback(ll v, ll w){//完全背包,无限件可用
	for (int j = w; j <= V; ++j)
		dp[j] = Max(dp[j], dp[j - w] + v);
}
void zoback(ll v, ll w){//01背包,1件
	for (int j = V; j >= w; ++j)
		dp[j] = Max(dp[j], dp[j - w] + v);
}
void mulback(ll v, ll w, ll num){//多重背包
	if (w*num >= V){
		comback(v, w);
		return;
	}
	for (int k = 1; k < num; ++k){
		zoback(k*v, k*w);
		num -= k;
		k *= 2;
	}
	zoback(num*v, num*w);
}
ll a[MAXN];
ll m[MAXN];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--){
		memset(dp, 0, sizeof dp);
		scanf("%d%I64d", &n, &V);
		for (int i = 1; i <= n; ++i){
			scanf("%I64d", a + i);
		}
		for (int i = 1; i <= n; ++i){
			scanf("%I64d", m + i);
		}
		for (int i = 1; i <= n; ++i){
			mulback(a[i], a[i], m[i]);
		}
		if (dp[V] == V)printf("yes\n");
		else printf("no\n");
	}
	return 0;
}

