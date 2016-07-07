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

const int N=1e6;
int n,m,x;
int pnt[N],nxt[N],head[N],cost[N];
int flag[N];
int cnt;

void add_edge(int u,int v,int c,int id){
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt;
	cost[cnt]=c;flag[cnt++]=id;
}

int d[1200][3];
int vis[1200][3];

void spfa(int id){
	d[x][id]=0;
	queue<int> q;
	q.push(x);
	vis[x][id]=1;
	while (!q.empty()){
		int u=q.front();q.pop();
		vis[u][id]=0;
		for (int i=head[u];~i;i=nxt[i]){
			int v=pnt[i];
			if (v==u || flag[i]!=id) continue;
//			lookln(v);
			if (d[v][id]>d[u][id]+cost[i]){
//				lookln(v);
				d[v][id]=d[u][id]+cost[i];
				if (!vis[v][id]){
					vis[v][id]=1;
					q.push(v);
//					lookln(v);
				} 
			}
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> m >> x){
		OFF(head);cnt=0;
		for (int i=1;i<=m;i++){
			int u,v,c;
			SIII(u,v,c);
			add_edge(u,v,c,0);
			add_edge(v,u,c,1);
		}
//		lookln(cnt);
//		for (int i=1;i<=n;i++) d[i][1]=d[i][0]=INF;
		MEM(d,INF);
		CLR(vis);
		spfa(0);
//		cout << "---------\n";
		spfa(1);
		int ans=0;
		for (int i=1;i<=n;i++) ans=max(ans,d[i][1]+d[i][0]);
		cout << ans << endl;
	}
	return 0;
}

