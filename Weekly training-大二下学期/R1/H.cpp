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
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for(int flag=start;flag>=end;flag--)
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

const int N=3e4+100;
struct Edge
{
	int v,w;
	Edge(){}
	Edge(int v,int w):v(v),w(w){}
	bool operator < (const Edge& rhs) const {
		return v<rhs.v;
	}
};
vector<Edge> g[N];
int n,m,k;
int pre[N];
int prew[N];
int vis[N],dis[N];

void spfa() {
	queue<int> q;
	CLR(vis);MEM(dis,INF_INT);
	q.push(1);
	dis[1]=0;
	vis[1]=1;
	for (int i=1;i<=n;i++) pre[i]=i;
	while (q.size()) {
		int x=q.front();q.pop();
		vis[x]=0;
		for (int i=0;i<g[x].size();i++) {
			Edge& e=g[x][i];
			if (dis[e.v]>dis[x]+e.w) {
				dis[e.v]=dis[x]+e.w;
				pre[e.v]=x;
				prew[e.v]=e.w;
				if (!vis[e.v]) {
					vis[e.v]=1;
					q.push(e.v);
				}
			}
		}
	}
}

int pnt[N*2],nxt[N*2],head[N],w[N*2];
int cnt;
void add_edge(int u,int v,int cost) {
	pnt[cnt]=v;nxt[cnt]=head[u];w[cnt]=cost;head[u]=cnt++;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int t;SI(t);
	while(t--) {
	    SIII(n,m,k);
	    rep(i,0,n) g[i].clear();
	    rep(i,1,m) {
	    	int u,v,w;
	    	SIII(u,v,w);
	    	g[u].push_back(Edge(v,w));
	    	g[v].push_back(Edge(u,w));
	    }
	    rep(i,1,n) sort(g[i].begin(),g[i].end());
	    spfa();
	    // for (int i=1;i<=n;i++) cout << "pre[" << i << "]=" << pre[i] << endl;
	    OFF(head);
	    cnt=0;
	    CLR(vis);
	    rep(i,1,n) {
	    	int x=i;
	    	while (pre[x]!=x && !vis[x]) {
	    		vis[x]=1;
	    		// cout << x << ' '  << pre[x] << ' ' << prew[x] << endl;
	    		add_edge(x,pre[x],prew[x]);
	    		add_edge(pre[x],x,prew[x]);
	    		x=pre[x];
	    	}
	    }

	}
	return 0;
}