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
const long long  INF=999999999999999;
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

const int N=2e6+10000;
int P,Q;
int pnt[N],nxt[N],head[N],cost[N],flag[N];
int cnt;

void add_edge(int u,int v,int w,int id) {
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt;
	cost[cnt]=w;flag[cnt++]=id;
}

ll d[N][2];
int vis[N];

void spfa(int id){
	CLR(vis);
	for (int i=1;i<=P;i++) d[i][id]=999999999999999;
	queue<int> q;
	vis[1]=1;
	d[1][id]=0;
	q.push(1);
	while (!q.empty()){
		int x=q.front();q.pop();
		vis[x]=0;
		for (int i=head[x];~i;i=nxt[i]){
			int v=pnt[i];
			if (v==x || flag[i]!=id) continue;
			if (d[v][id]>d[x][id]+cost[i]){
				d[v][id]=d[x][id]+cost[i];
				if (!vis[v]){
					vis[v]=1;;
					q.push(v);
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
	int _;
	SI(_);
	while (_--){
		OFF(head);cnt=0;
		P=read();Q=read();
		for (int i=1;i<=Q;i++){
			int u,v,w;
			u=read();v=read();w=read();
			add_edge(u,v,w,0);
			add_edge(v,u,w,1);
		}
		spfa(0);
		spfa(1);
		ll ans=0;
		for (int i=1;i<=P;i++) ans=ans+d[i][1]+d[i][0];
		cout << ans << endl;
	}
	return 0;
}

