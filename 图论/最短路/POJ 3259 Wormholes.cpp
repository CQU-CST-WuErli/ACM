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

const int N=6000;
int pnt[N],nxt[N],head[N],cost[N];
int cnt;
int n,m,W;

void add_edge(int u,int v,int w){
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt;
	cost[cnt++]=w;
}

int vis[3000],counter[3000];
int d[3000];

bool spfa(){
	CLR(vis);MEM(d,INF);
	CLR(counter);
	queue<int> q;
	q.push(1);
	vis[1]=1;
	counter[1]++;
	d[1]=0;
	while (!q.empty()){
		int x=q.front();q.pop();
		vis[x]=0;
		for (int i=head[x];~i;i=nxt[i]){
			int v=pnt[i];
			if (d[v]>d[x]+cost[i]){
				d[v]=d[x]+cost[i];
				if (!vis[v]){
					vis[v]=1;
					q.push(v);
					counter[v]++;
				} 
				if (counter[v]>n) return true;
			}
		}
	}
	return false;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int _;
	SI(_);
	while (_--){
		OFF(head);cnt=0;
		cin >> n >> m >> W;
		for (int i=1;i<=m;i++){
			int u,v,t;
			SIII(u,v,t);
			add_edge(u,v,t);
			add_edge(v,u,t);
		}
		for (int i=1;i<=W;i++){
			int u,v,t;
			SIII(u,v,t);
			add_edge(u,v,-t);
		}
		if (spfa()) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

