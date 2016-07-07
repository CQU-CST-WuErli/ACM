// SOJ �Ҽ�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
int n;//����
ll V;//�����
const int MAXN = 1e5 + 10;
ll dp[MAXN];
ll Max(ll a, ll b){ return a > b ? a : b; }
void comback(ll v, ll w){//��ȫ����,���޼�����
	for (int j = w; j <= V; ++j)
		dp[j] = Max(dp[j], dp[j - w] + v);
}
void zoback(ll v, ll w){//01����,1��
	for (int j = V; j >= w; ++j)
		dp[j] = Max(dp[j], dp[j - w] + v);
}
void mulback(ll v, ll w, ll num){//���ر���
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

