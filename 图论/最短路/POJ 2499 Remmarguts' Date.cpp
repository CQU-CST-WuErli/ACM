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
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=1100;

struct Edge{
	int v;
	int w;
}; 
struct Sta{
	int pre;
	int v; 
	int d;
	bool operator < (const Sta &rhs) const {
		return d>rhs.d; 
	}
};
vector<Edge> g[N],revg[N];
int cnt[N];
int n,m;
int s,t,k;

void init(){
	for (int i=0;i<=n;i++) g[i].clear();
	for (int i=0;i<=n;i++) revg[i].clear();
	CLR(cnt);
}

int vis[1100],dis[1100];
void spfa(int s,int t){
	CLR(vis);
	MEM(dis,INF_INT);
	queue<int> q;
	q.push(s);
	vis[s]=1;
	dis[s]=0;
	while (!q.empty()){
		int x=q.front();q.pop();
		vis[x]=0;
		for (int i=0;i<revg[x].size();i++){
			int v=revg[x][i].v;
			int w=revg[x][i].w;
			if (dis[v]>dis[x]+w){
				dis[v]=dis[x]+w;
				if (!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}

int YEN(){
	priority_queue<Sta> q;
	
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> m){
		for (int i=1;i<=m;i++){
			int u,v,w;
			SIII(u,v,w);
			g[u].push_back(Edge{v,w});
			revg[v].push_back(Edge{u,w});
		}
		SIII(s,t,k);
		spfa(t,s);
		int ans=YEN();
		cout << ans << endl;
	}
	return 0;
}

