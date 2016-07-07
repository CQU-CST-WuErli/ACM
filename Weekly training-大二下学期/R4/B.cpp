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

const int N=5e4;
const int M=400;

int n,m;
int in[M],out[M];
int vis[M];

struct Dinic
{
	const static int NE=400;
	const static int NV=5e4;
	int source,sink;
	int pnt[N],nxt[N],head[M],cap[N],cnt;
	int iter[M],level[M];
	void init(int s=0,int t=NE) {
		source=s,sink=t;
		cnt=0;
		OFF(head);
	}
	void add_edge(int u,int v,int c) {
		pnt[cnt]=v;nxt[cnt]=head[u];cap[cnt]=c;head[u]=cnt++;
	}
	bool bfs(int s,int t) {
		OFF(level);
		level[s]=0;
		queue<int> q;
		q.push(s);
		while(q.size()) {
		    int x=q.front();q.pop();
		    for (int i=head[x];~i;i=nxt[i]) {
		    	int v=pnt[i];
		    	if (level[v]==-1 && cap[i]) {
		    		level[v]=level[x]+1;
		    		q.push(v);
		    	}
		    }
		}
		return level[t]!=-1;
	}
	int dfs(int u,int t,int f) {
		if (u==t || !f) return f;
		int left=f;
		for (int i=iter[u];~i;i=nxt[i]) {
			int v=pnt[i];
			if (level[v]==level[u]+1 && cap[i]) {
				int d=dfs(v,t,min(cap[i],left));
				iter[u]=i;
				cap[i]-=d;
				cap[i^1]+=d;
				left-=d;
				if (!left) return f;
			}
		}
		level[u]=-1;
		return f-left;
	}
	int solve(int s,int t) {
		int Max_flow=0;
		while (bfs(s,t)) {
			for (int i=s;i<=t;i++) iter[i]=head[i];
			Max_flow+=dfs(s,t,INF_INT);
		}
		return Max_flow;
	}
	void dfs(int u) {
		vis[u]=1;
		for (int i=head[u];~i;i=nxt[i]) {
			int v=pnt[i];
			if (cap[i]==0 || vis[v]) continue;
			dfs(v);
		}
	}
}dinic;



int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SII(n,m)==2) {
	    rep(i,1,n) SI(in[i]);
	    rep(i,1,n) SI(out[i]);
	    int source=0,sink=n+n+1;
	    dinic.init(source,sink);
	    rep(i,1,n) {
	    	dinic.add_edge(i+n,sink,in[i]);
	    	dinic.add_edge(i,source,0);
	    }
	    rep(i,1,n) {
	    	dinic.add_edge(source,i,out[i]);
	    	dinic.add_edge(i,source,0);
	    }
	    rep(i,1,m) {
	    	int u,v;
	    	SII(u,v);
	    	dinic.add_edge(u,v+n,INF_INT);
	    	dinic.add_edge(v+n,u,0);
	    }
	    printf("%d\n",dinic.solve(source,sink));
	    CLR(vis);
	    dinic.dfs(source);
	    int ans=0;
	    rep(i,1,n) ans+=(!vis[i]+vis[i+n]);
	    printf("%d\n",ans);
	    rep(i,1,n) {
	    	if (!vis[i]) printf("%d %c\n",i,'-');
	    	if (vis[i+n]) printf("%d %c\n",i,'+');
	    }
	}
	return 0;
}