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
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=110;

int n,m;
struct Edge
{
	int u,v,w;
	Edge(){}
	Edge(int u,int v,int w):u(u),v(v),w(w){}
	bool operator < (const Edge& rhs) const {
		return w<rhs.w;
	}
};
vector<Edge> es;

struct P
{
	int v,w;
	P(int v,int w):v(v),w(w){}
};
vector<P>g[N];

int par[N],rnk[N];
void init() {
	rep(i,1,n) {
		g[i].clear();
		par[i]=i;
		rnk[i]=0;
	}
}

int find(int x) {
	if (par[x]==x) return x;
	return par[x]=find(par[x]);
}

bool same(int x,int y) {
	x=find(x);y=find(y);
	return x==y;
}

void unite(int x,int y) {
	x=find(x);y=find(y);
	if (x==y) return;
	if (rnk[x]<rnk[y]) par[x]=y;
	else {
		par[y]=x;
		if (rnk[x]==rnk[y]) rnk[x]++;
	}
	return;
}

int delta;

void dfs(int fa,int u) {

}

int kruskal() {
	int ret=0;
	delta=INF_INT;
	sort(es.begin(),es.end());
	rep(i,0,es.size()-1) {
		Edge& e=es[i];
		if (!same(e.u,e.v)) {
			dfs(e.u,e.v);
			unite(e.u,e.v);
			ret+=e.w;
		}
	}
	if (!delta) return -1;
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t;SI(t);
    while(t--) {
     	SII(n,m);
     	init();
     	rep(i,1,m) {
     		int u,v,w;
     		SIII(u,v,w);
     		es.push_back(Edge(u,v,w));
     		g[u].push_back(P(v,w));
     		g[v].push_back(P(u,w));
     	}
     	int ans=kruskal();
     	if (ans==-1) puts("Not Unique!");
     	else cout << ans << endl;
    }
	return 0;
}