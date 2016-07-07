//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
//#pragma comment(linker, "/STACK:102400000,102400000")
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

struct Dinic
{
    const static int NV=500 * 500 + 501 * 501 + 10;
    const static int NE= NV * 7;
    int source,sink;
    int pnt[NE],nxt[NE],head[NV],cap[NE],cnt;
    int iter[NV],level[NV];
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
int n, m;
int id[1010][1010];

void init() {
	int cnt = 0;
	for (int i = 0; i <= n; i++) {
		if (i & 1)
			for (int j = 0; j < m; j++)
				id[i][j] = cnt++;
		else
			for (int j = 0; j <= m; j++)
				id[i][j] = cnt++;
	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    init();
    while(SII(n, m) == 2) {
        int s = 0, t = (n + 1) * (m + 1) + n * m - 1;
        dinic.init(s, t);
        n = n * 2;
        // lookln(n);
        init();
        for (int i = 0; i <= n; i += 2) {
        	for (int j = 0; j < m; j++) {
        		int x; SI(x);
        		int u = id[i][j], v = id[i][j + 1];
        		dinic.add_edge(u, v, x);
        		dinic.add_edge(v, u, x);
        	}
        }
        for (int i = 0; i < n; i += 2) {
        	for (int j = 0; j <= m; j++) {
        		int x; SI(x);
        		int u = id[i][j], v = id[i + 2][j];
        		// cout << u << ' ' << v << endl;
        		dinic.add_edge(u, v, x);
        		dinic.add_edge(v, u, x);
        	}
        }
        for (int i = 0; i <= n; i += 2) {
        	if (i == 0) {
        		for (int j = 0; j < m; j++) {
        			int x, y; SII(x, y);
        			int u = id[i][j], v = id[i + 1][j];
        			dinic.add_edge(u, v, x);
        			dinic.add_edge(v, u, x);
        			u = id[i][j + 1], v = id[i + 1][j];
        			dinic.add_edge(u, v, y);
        			dinic.add_edge(v, u ,y);
        		}
        	}
        	else if (i > 0 && i < n) {
        		for (int j = 0; j < m; j++) {
        			int x, y; SII(x, y);
        			int u = id[i][j], v = id[i - 1][j];
        			dinic.add_edge(u, v, x);
        			dinic.add_edge(v, u, x);
        			u = id[i][j + 1], v = id[i - 1][j];
        			dinic.add_edge(u, v, y);
        			dinic.add_edge(v, u, y);
        		}
        		for (int j = 0; j < m; j++) {
        			int x, y; SII(x, y);
        			int u = id[i][j], v = id[i + 1][j];
        			dinic.add_edge(u, v, x);
        			dinic.add_edge(v, u, x);
        			u = id[i][j + 1], v = id[i + 1][j];
        			dinic.add_edge(u, v, y);
        			dinic.add_edge(v, u ,y);
        		}
        	}
        	else if (i == n) {
        		for (int j = 0; j < m; j++) {
        			int x, y; SII(x, y);
        			int u = id[i][j], v = id[i - 1][j];
        			dinic.add_edge(u, v, x);
        			dinic.add_edge(v, u, x);
        			u = id[i][j + 1], v = id[i - 1][j];
        			dinic.add_edge(u, v, y);
        			dinic.add_edge(v, u, y);
        		}
        	}
        }
        cout << dinic.solve(s, t) << endl;
    }
	return 0;
}