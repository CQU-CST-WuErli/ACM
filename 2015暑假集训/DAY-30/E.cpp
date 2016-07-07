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
#include <ctime>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <functional>
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
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=1e5+10;
int pnt[N],pre[N],nxt[N],head[N],cap[N],cost[N];
int cnt;
int n,m,k;
int needkind[500],need[500][500];
int havekind[500],have[500][500];

void add_edge(int u,int v,int c,int w){
	pnt[cnt]=v;pre[cnt]=u;nxt[cnt]=head[u];head[u]=cnt;
	cap[cnt]=c;cost[cnt++]=w;
}

int a[500],vis[500],p[500];
ll d[500];
bool spfa(int s,int t,int &Flow,ll &Cost){
	CLR(a);CLR(vis);
	for (int i=s;i<=t;i++) d[i]=INF;
	queue<int> q;
	a[s]=INF;
	vis[s]=1;
	d[s]=0;
	q.push(s);
	while (!q.empty()){
		int x=q.front();q.pop();
		vis[x]=0;
		for (int i=head[x];~i;i=nxt[i]){
			int v=pnt[i];
			if (d[v]>d[x]+cost[i] && cap[i]){
				d[v]=d[x]+cost[i];
				a[v]=min(a[x],cap[i]);
				p[v]=i;
				if (!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	if (d[t]==INF) return false;
	Flow+=a[t];
	Cost+=a[t]*d[t];
	for (int u=t;u!=s;u=pre[p[u]]){
		cap[p[u]]-=a[t];
		cap[p[u]^1]+=a[t];
	}
	return true;
}

ll Min_cost_flow(int s,int t){
	int Flow=0;
	ll Cost=0;
	while (spfa(s,t,Flow,Cost));
	return Cost;
}


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SIII(n,m,k)==3 && (n||m||k)){
		CLR(needkind);CLR(havekind);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=k;j++){
//				BUG;
				cin >> need[i][j];
				needkind[j]+=need[i][j];
			}
		for (int i=1;i<=m;i++)
			for (int j=1;j<=k;j++){
				cin >> have[i][j];
				havekind[j]+=have[i][j];
			}
		int flag=1;
		for (int i=1;i<=k;i++) 
			if (needkind[i]>havekind[i]) {
				flag=0;
				break;
			}
		ll ans=0;
		int s=0,t=m+n+1;
		for (int z=1;z<=k;z++){			
			cnt=0;OFF(head);
			for (int i=1;i<=n;i++){
				for (int j=1;j<=m;j++){
					int x;cin >> x;
					add_edge(j,m+i,INF,x);
					add_edge(m+i,j,0,-x);
				}
			}
			if (!flag) continue;
			for (int i=1;i<=m;i++){
				add_edge(s,i,have[i][z],0);
				add_edge(i,s,0,0);
			}
			for (int i=1;i<=n;i++){
				add_edge(m+i,t,need[i][z],0);
				add_edge(t,m+i,0,0); 
			}
			ans+=Min_cost_flow(s,t);
		}
		if (!flag) cout << "-1\n";
		else cout << ans << endl;
	}
	return 0;
}

