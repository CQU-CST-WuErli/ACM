//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015 CQU_CST_WuErli. All rights reserved.
//
// #include<bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
template <typename T> T max(T& a,T& b) {return a>b?a:b;}
template <typename T> T min(T& a,T& b) {return a<b?a:b;}
int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
long long gcd (long long a,long long b) {return b==0LL?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=1e5+100;

// graph
int n,m;
int pnt[N*4],nxt[N*4],head[N],cnt;
void add_edge(int u,int v)  {
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt++;
}
int pre[N],low[N],in[N];
int dfs_clock;
int isbridge[N];
int par[N];
int sum;

void tarjan(int fa,int u) {
	low[u]=pre[u]=++dfs_clock;
	for (int i=head[u];~i;i=nxt[i]) {
		int v=pnt[i];
		if (!pre[v]) {
			par[v]=u;
			tarjan(u,v);
			low[u]=min(low[u],low[v]);
			if (low[v]>pre[u]) {
				sum++;
				isbridge[v]=1;
			}
		}	
		else if (v!=fa) low[u]=min(low[u],pre[v]);	
	}
}

void find_bridge() {
	CLR(pre);CLR(low);CLR(isbridge);CLR(par);
	dfs_clock=0;
	tarjan(-1,1);
}

void lca(int u,int v) {
	if (pre[u]>pre[v]) swap(u,v);
	while (pre[v]>pre[u]) {
		if (isbridge[v]) sum--,isbridge[v]=0;
		v=par[v];
	}
	while (u!=v) {
		if (isbridge[v]) sum--,isbridge[v]=0;
		if (isbridge[u]) sum--,isbridge[u]=0;
		u=par[u];v=par[v];
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=1;
	while (SII(n,m)==2 && (n+m)) {
		OFF(head);cnt=0;sum=0;
		for (int i=1;i<=m;i++){
			int u,v;
			SII(u,v);
			add_edge(u,v);
			add_edge(v,u);
		}
		find_bridge();
		printf("Case %d:\n",kase++);
		int q;
		SI(q);
		while (q--) {
			int u,v;
			SII(u,v);
			lca(u,v); 
			printf("%d\n",sum); 
		}
		cout << endl;
	}
	return 0;
}

