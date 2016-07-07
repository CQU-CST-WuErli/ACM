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

const int N=1e5+100;
int cost[N];
int n,q,s;

int vis[N<<1],dep[N<<1],fst[N<<1],dfs_clock;

int flag[N<<1];

int lowbit(int x) {return x& -x;}

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

struct BIT {
	int n,add[N<<1];
	void init(int _) {
		n=_;
		CLR(add);
	}
	void update(int pos,int v) {
		while (pos<=n) {
			add[pos]+=v;
			pos+=lowbit(pos); 
		}
	}
	int query(int pos) {
		int ret=0; 
		while (pos) {
			ret+=add[pos]; 
			pos-=lowbit(pos);
		}
		return ret;
	}
}bit;

struct Edge{
	int v,dis,id;
	Edge(int a,int b,int c) {
		v=a;dis=b;id=c;
	} 
};
vector<Edge> g[N];

void dfs(int fa,int u,int d) {
	vis[++dfs_clock]=u;
	dep[dfs_clock]=d;
	fst[u]=dfs_clock;
	for (int i=0;i<g[u].size();i++) {
		Edge &e=g[u][i];
		if (e.v==fa) continue;
		flag[2*e.id-1]=dfs_clock;
		bit.update(dfs_clock,e.dis);
		dfs(u,e.v,d+1);
		vis[++dfs_clock]=u;
		dep[dfs_clock]=d;
		flag[2*e.id]=dfs_clock;
		bit.update(dfs_clock,-e.dis);
	}
}


int lca(int u,int v) {
	if (fst[u]>fst[v]) swap(u,v);
	int id=st.RMQ(fst[u],fst[v]);
	return vis[id];
}



int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> q >> s) {
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=1;i<n;i++) {
			int u,v,d;
			scanf("%d%d%d",&u,&v,&d);
			cost[i]=d;
			g[u].push_back(Edge(v,d,i));
			g[v].push_back(Edge(u,d,i));
		}
		dfs_clock=0;
		bit.init(2*n+1);
		dfs(-1,1,0);
		st.init(2*n+1);
		
		while (q--) {
			int op;
			scanf("%d",&op);
			if (op==0) {
				int t;
				scanf("%d",&t);
				int LCA=lca(s,t);
				int ans=bit.query(fst[s]-1)+bit.query(fst[t]-1)-2*bit.query(fst[LCA]-1);
				printf("%d\n",ans);
				s=t;
			}
			else {
				int pos,change;
				scanf("%d%d",&pos,&change);
				bit.update(flag[2*pos-1],change-cost[pos]);
				bit.update(flag[2*pos],cost[pos]-change);
				cost[pos]=change;
			}
		}
	}
	return 0;
}

