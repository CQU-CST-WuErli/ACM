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
#define SI(a) scanf("%d", &a)
#define SII(a,b) scanf("%d%d", &a, &b)
#define SIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N = 3e5 + 100;
const int M = 3e4 + 10;

int pnt[N], head[M], nxt[N], w[N];
int cnt;
int n, m;
void add_edge(int u, int v, int c) {
	pnt[cnt] = v; nxt[cnt] = head[u]; w[cnt] = c;
	head[u] = cnt++;
}

int dis[N];
int vis[N];
int num[N];
void spfa() {
	CLR(vis);
	CLR(num);
	MEM(dis, INF_INT);
	queue<int> q;
	vis[1] = 1;
	dis[1] = 0;
	num[1] = 0;
	q.push(1);
	while(q.size()) {
	    int x = q.front(); q.pop();
	    vis[x] = 0;
	    for (int i = head[x]; ~i; i = nxt[i]) {
	    	int v = pnt[i];
	    	if(dis[v] == dis[x] + w[i]) {
                num[v] = min(num[v], num[x] + 1);
                if(!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
            if(dis[v] > dis[x] + w[i]) {
                dis[v] = dis[x] + w[i];
                num[v] = num[x] + 1;
                if(!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
	    }
	}
}

struct Dinic
{
    const static int NE=2020;
    const static int NV=3e5;
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
}dinic;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SII(n, m) == 2) {
        OFF(head);cnt = 0;
        for (int i = 1; i <= m; i++) {
        	int u, v, c;
        	SIII(u, v, c);
        	add_edge(u, v, c);
        	add_edge(v, u, c);
        }
        spfa();
        dinic.init(1, n);
        for (int u = 1; u <= n; u++) {
        	for (int i = head[u]; ~i; i = nxt[i]) {
        		int v = pnt[i];
        		if (dis[v] - dis[u] == w[i]) {
        			dinic.add_edge(u, v, 1);
        			dinic.add_edge(v, u, 0);
        		}
        	}
        }
        int ans = dinic.solve(1, n);
        cout << ans << ' ' << m - num[n] << endl;
    }
	return 0;
}