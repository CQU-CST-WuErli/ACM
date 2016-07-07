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
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

inline int read() {
    char c = getchar();
    while(!isdigit(c)) c = getchar();
    int x = 0;
    while(isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

const int N=2e5+100;

int vis[N<<1],dep[N<<1],fst[N],dfs_clock,dis[N];
int n,m;

int pnt[N],nxt[N],head[N];
int cnt;

void add_edge(int u,int v) {
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt++;
}

void dfs(int fa,int u,int d) {
	vis[++dfs_clock]=u;
	dep[dfs_clock]=d;
	fst[u]=dfs_clock;
	dis[u]=d;
	for (int i=head[u];~i;i=nxt[i]) {
		int v=pnt[i];
		if (v==fa) continue;
		dfs(u,v,d+1);
		vis[++dfs_clock]=u;
		dep[dfs_clock]=d;
	}
}

int getMin(int x,int y) {
	return dep[x]<dep[y]?x:y;
}

struct SparseTable {
	int dp[20][N<<1];
	void init(int n) {
		for (int i=1;i<=n;i++) dp[0][i]=i;
		for (int i=1;(1<<i)<=n;i++) {
			for (int j=1;j+(1<<i)-1<=n;j++) {
				dp[i][j]=getMin(dp[i-1][j],dp[i-1][j+(1<<i-1)]);
			}
		}
	}
	int RMQ(int l,int r) {
		int k=31-__builtin_clz(r-l+1);
		return getMin(dp[k][l],dp[k][r-(1<<k)+1]);
	}
}st;

int lca(int u,int v) {
	if (fst[u]>fst[v]) swap(u,v);
	int id=st.RMQ(fst[u],fst[v]);
	return vis[id];
}

int dp[N];
void DP(int fa,int u) {
	for (int i=head[u];~i;i=nxt[i]){
		int v=pnt[i];
		if (v==fa) continue;
		DP(u,v);
		dp[u]+=dp[v]; 
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SII(n,m)==2) {
		dfs_clock=0;cnt=0;OFF(head);
		for (int i=1;i<n;i++) {
			int u,v;
			u=read();v=read();
			add_edge(u,v);
			add_edge(v,u);
		}
		dfs(-1,1,0);
		st.init(2*n-1);
		ll ans=0;CLR(dp);
		for (int i=1;i<=m;i++) {
			int u,v;
			u=read();
			v=read();
			int LCA=lca(u,v);
			dp[u]++;dp[v]++;dp[LCA]-=2;
		}
		DP(-1,1);
		for (int i=2;i<=n;i++) {
			if (!dp[i]) ans+=m;
			else if (dp[i]==1) ans++;
		}			
		printf("%I64d\n",ans);
	}
	return 0;
}

