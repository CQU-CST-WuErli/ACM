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

int T;
int n,m;
int profit[100],budget[100];
vector<int> need[100];
int mp[100][100];
int source,sink;

const int N=2e5+100;
const int M=400;
int pnt[N],head[M],nxt[N],cap[N],cnt;
int level[M],iter[M];

void add_edge(int u,int v,int c) {
	pnt[cnt]=v;nxt[cnt]=head[u],head[u]=cnt;
	cap[cnt++]=c;
}

void init() {
	rep(i,0,n) need[i].clear();
	CLR(mp);
	OFF(head);
	cnt=0;
}

void getData() {
	rep(i,1,n) SI(profit[i]);
    rep(i,1,m) SI(budget[i]);
    rep(i,1,n) {
    	int k;SI(k);
    	while (k--) {
    		int x;SI(x);
    		need[i].push_back(x);
    	}
    }
    rep(i,1,m) rep(j,1,m) SI(mp[i][j]);
}

void buildGraph() {
	source=0;sink=n+m+1;
	rep(i,1,n) {
		add_edge(source,i,profit[i]);
		add_edge(i,source,0);
	}
	rep(i,1,m) {
		add_edge(i+n,sink,budget[i]);
		add_edge(sink,i+n,0);
	}
	rep(i,1,n) {
		rep(j,0,need[i].size()-1) {
			int v=need[i][j];
			v+=n+1;
			add_edge(i,v,INF_INT);
			add_edge(v,i,0);
		}
	}
	rep(i,1,m) rep(j,1,m) if (mp[i][j]) {
		add_edge(i+n,j+n,INF_INT);
		add_edge(j+n,i+n,0);
	}
}

bool bfs(int s,int t) {
	OFF(level);
	queue<int> q;
	q.push(s);
	level[s]=0;
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

int Dinic(int s,int t) {
	int Max_flow=0;
	while(bfs(s,t)) {
	    rep(i,s,t) iter[i]=head[i];
	    Max_flow+=dfs(s,t,INF_INT);
	}
	return Max_flow;
}

int solve() {
	int sum=0;
	rep(i,1,n) sum+=profit[i];
	int ans=Dinic(source,sink);
	return sum-ans;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    for (int T_T,kase=SI(T_T);kase<=T_T;kase++) {
        SII(n,m);
        init();
        getData();
        buildGraph();
        printf("Case #%d: %d\n",kase,solve());
    }
	return 0;
}