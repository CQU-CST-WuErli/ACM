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
const double eps=1e-5;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n,m;
int source,sink;
struct Edge
{
	int u,v;
	void read() {
		SII(u,v);
	}
}es[1010];
int deg[110];
const int N=5e4+100;
const int M=110;
int pnt[N],head[M],nxt[N],cnt;
double cap[N];
void add_edge(int u,int v,double cost) {
	// if (cost>0) cout << u << ' ' << v << ' ' << cost << endl;
	pnt[cnt]=v;nxt[cnt]=head[u];cap[cnt]=cost;head[u]=cnt++;
}

void build(double mid) {
	rep(i,1,m) {
		int u=es[i].u,v=es[i].v;
		add_edge(u,v,1);
		add_edge(v,u,0);
		add_edge(v,u,1);
		add_edge(u,v,0);
	}
	rep(i,1,n) {
		add_edge(source,i,m);
		add_edge(i,source,0);
		add_edge(i,sink,m*1.0+2*mid-deg[i]*1.0);
		add_edge(sink,i,0);
	}
}


int level[M],iter[M];
bool bfs(int s,int t){
	OFF(level);
	queue<int> q;
	q.push(s);
	level[s]=0;
	while (!q.empty()){
		int x=q.front();q.pop();
		for (int i=head[x];~i;i=nxt[i]){
			int v=pnt[i];
			if (level[v]==-1 && cap[i]>0){
				level[v]=level[x]+1;
				q.push(v);
			}
		}
	}
	return level[t]!=-1;
}

double dfs(int u,int t,double Flow) {
	double left=Flow;
	if (u==t) return Flow;
	for (int i=iter[u];~i;i=nxt[i]) {
		int v=pnt[i];
		if (level[v]==level[u]+1 && cap[i]>0) {
			double d=dfs(v,t,min(cap[i],left));
			left-=d;
			cap[i]-=d;
			cap[i^1]+=d;
			iter[u]=i;
		}
	}
	level[u]=-1;
	return Flow-left;
}

double Dinic(int s,int t) {
	double Max_flow=0;
	while(bfs(s,t)) {
	    for (int i=s;i<=t;i++) iter[i]=head[i];
	    	Max_flow+=dfs(s,t,INF_INT*1.0);
	}
	return Max_flow;
}

int vis[M];
int tot;
void DFS(int u) {
	vis[u]=1;
	if (u>=1 && u<=n) tot++;
	for (int i=head[u];~i;i=nxt[i]) {
		int v=pnt[i];
		if (cap[i]>0 && !vis[v]) DFS(v);
	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SII(n,m)==2) {
		CLR(deg);
		if (!m) {
			cout << 1 << '\n' << 1 << endl;
			continue;
		}
		rep(i,1,m) {
			es[i].read();
			deg[es[i].u]++;
			deg[es[i].v]++;
		}
		source=0,sink=n+1;
		double L=0.0,R=m;
		while(R-L>=(1.0/n/n)) {
		    double mid=(L+R)/2.0;
		    OFF(head);cnt=0;
		    build(mid);
		    // cout << mid << endl;
		    double tmp=Dinic(source,sink);
		    tmp=(m*n*1.0-tmp)/2.0;
		    if (tmp>eps) L=mid;
		    else R=mid;
		}
		OFF(head);cnt=0;
		build(L);
		Dinic(source,sink);
		CLR(vis);
		tot=0;
		DFS(source);
		cout << tot << endl;
		rep(i,1,n) if (vis[i]) cout << i << endl;
	}
	return 0;
}