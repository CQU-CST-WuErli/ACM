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

const int N=1e5+10;
int n;
int dep[N],p[20][N];
int dis[N];
int pnt[N],nxt[N],head[N];
int w[N];
int cnt;

void add_edge(int u,int v,ll c){
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt;
	w[cnt++]=c;
}

void dfs(int fa,int u,int d,ll ds) {
	dep[u]=d;p[0][u]=fa;
	dis[u]=ds;
	for (int i=head[u];~i;i=nxt[i]) {
		int v=pnt[i];
		if (v==fa) continue;
		dfs(u,v,d+1,ds+w[i]);
	}
}

void process() {
	OFF(p);
	dfs(-1,1,0,0);
	for (int i=0;i+1<20;i++) {
		for (int v=1;v<=n;v++) {
			if (p[i][v]==-1) p[i+1][v]=-1;
			else p[i+1][v]=p[i][p[i][v]];
		}
	}
}

int lca(int u,int v) {
	if (dep[u]>dep[v]) swap(u,v);
	for (int i=0;i<20;i++) {
		if (dep[v]-dep[u]>>i&1) v=p[i][v];
	}
	if (u==v) return u;
	for (int i=19;~i;i--) {
		if (p[i][u]!=p[i][v]) {
			v=p[i][v];
			u=p[i][u];
		}
	}
	return p[0][u];
}

int dist(int u,int v) {
	int LCA=lca(u,v);
	ll ret=dis[u]+dis[v]-2*dis[LCA];
	return ret;
}

int kth(int u,int k){
	if (k==1) return u;
	else {
		k--;
		for (int i=0;i<20;i++) {
			if (k>>i&1) {
				u=p[i][u];
				k-=1<<i;
			}
		}
		return u;
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T_T;cin >> T_T;
	while (T_T--){
		cnt=0;OFF(head);
		scanf("%d",&n); 
		for (int i=1;i<n;i++){
			int u,v;
			ll cost;
			scanf("%d%d%d\n",&u,&v,&cost);
			add_edge(u,v,cost);
			add_edge(v,u,cost);
		}
		process();
		char s[5];
		while (scanf("%s",s)) {
			if (s[0]=='K') {
				int u,v,k;
				scanf("%d%d%d",&u,&v,&k);
				int LCA=lca(u,v);
				int ans;
				int tmp=dep[u]-dep[LCA]+1;
				if (k==tmp) ans=LCA;
				else {
					if (k<tmp) ans=kth(u,k);
					else {
						int sum=tmp+dep[v]-dep[LCA];
						k=sum-k;
						ans=kth(v,k+1);						
					}
				}
				printf("%d\n",ans);
			}
			else if (s[0]=='D' && s[1]=='I'){
				int u,v;
				scanf("%d%d",&u,&v);
				printf("%d\n",dist(u,v));
			}
			else if (s[0]=='D' && s[1]=='O') break;
		}
		puts("");
	} 
	return 0;
}

