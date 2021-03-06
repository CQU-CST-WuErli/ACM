//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for(int flag=start;flag>=end;flag--)
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=1e5+100;

int n,h,m;
int pnt[N<<2],nxt[N<<2],head[N],w[N<<2],cnt;

void add_edge(int u,int v,int c) {
	pnt[cnt]=v;nxt[cnt]=head[u];w[cnt]=c;head[u]=cnt++;
}
int dist[110][110];
int hotel[110];

int vis[N],d[N];
void spfa(int id) {
	int s=hotel[id];
	CLR(vis);
	MEM(d,0x3f);
	queue<int> q;
	vis[s]=1;
	d[s]=0;
	q.push(s);
	while(q.size()) {
	    int x=q.front();q.pop();
	    vis[x]=0;
	    for (int i=head[x];~i;i=nxt[i]) {
	    	int v=pnt[i];
	    	int cost=w[i];
	    	if (d[v]>d[x]+cost) {
	    		d[v]=d[x]+cost;
	    		if (!vis[v]) {
	    			q.push(v);
	    			vis[v]=1;
	    		}
	    	}
	    }
	}
	for (int i=0;i<=h+1;i++) {
		if (d[hotel[i]]<=600) dist[id][i]=1;
	}
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SI(n)==1 && n) {
		OFF(head);cnt=0;
		SI(h);
		hotel[0]=1;
		rep(i,1,h) SI(hotel[i]);
		hotel[h+1]=n;
		SI(m);
		rep(i,1,m) {
			int u,v,c;
			SIII(u,v,c);
			add_edge(u,v,c);
			add_edge(v,u,c);
		}
		MEM(dist,INF_INT);
		rep(i,0,h+1) dist[i][i]=0;
		rep(i,0,h+1) spfa(i);
		rep(k,0,h+1) rep(i,0,h+1) rep(j,0,h+1) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		if (dist[0][h+1]>=INF_INT) puts("-1");
		else cout << dist[0][h+1]-1 << endl;
	}
	return 0;
}