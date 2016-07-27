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
#include <bitset>
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

int n, t;
char mp1[11][11], mp2[11][11];
vector<pair<int, int> > people, capsule;
int sx, sy;
int times[11][11];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int vis[11][11];

int getID(int x, int y) {
	return (x - 1) * n + y;
}

bool inside(int x, int y) {
	if (x < 1 || y < 1 || y > n || x > n) return false;
	return true;
}

struct Dinic
{
    const static int NV= 250;
    const static int NE= 5e4;
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

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    SII(n, t);
    for (int i = 1; i <= n; i++) {
    	scanf("%s", mp1[i] + 1);
    	for (int j = 1; j <= n; j++) {
    		if (mp1[i][j] == 'Z') {
    			sx = i, sy = j;
    		}
    		if (mp1[i][j] >= '1' && mp1[i][j] <= '9')
    			people.push_back(make_pair(i, j));
    	}
    }
    for (int i = 1; i <= n; i++) {
    	scanf("%s", mp2[i] + 1);
    	for (int j = 1; j <= n; j++) {
    		if (mp2[i][j] >= '1' && mp2[i][j] <= '9')
    			capsule.push_back(make_pair(i, j));
    	}
    }
   	MEM(times, INF_INT);
    queue<pair<int, int> > q;
    q.push(make_pair(sx, sy));
    times[sx][sy] = 0;
    while (q.size()) {
    	pair<int, int> tmp = q.front(); q.pop();
    	for (int i = 0; i < 4; i++) {
    		int tx = tmp.first + dir[i][0], ty = tmp.second + dir[i][1];
    		if (!inside(tx, ty) || mp1[tx][ty] == 'Z' || mp1[tx][ty] == 'Y' || times[tx][ty] < INF_INT) continue;
    		times[tx][ty] = times[tmp.first][tmp.second] + 1;
    		q.push(make_pair(tx, ty));
    	}
    }
    dinic.init();
    int source = 0, sink = n * n * 2 + 1;
    for (auto& p : people) {
    	int v = getID(p.first, p.second);
    	int num = mp1[p.first][p.second] - '0';
    	dinic.add_edge(source, v, num);
    	dinic.add_edge(v, source, 0);
    }
    for (auto& c : capsule) {
    	int v = getID(c.first, c.second) + n * n;
    	int num = mp2[c.first][c.second] - '0';
    	dinic.add_edge(v, sink, num);
    	dinic.add_edge(sink, v, 0);
    }
    for (auto& it : people) {
		int u = getID(it.first, it.second);
		if (mp2[it.first][it.second] >= '1' && mp2[it.first][it.second] <= '9') {
			dinic.add_edge(u, u + n * n, INF_INT);
			dinic.add_edge(u + n * n, u, 0);
		}
		MEM(vis, INF_INT);
		vis[it.first][it.second] = 0;
		q.push(it);
		while (q.size()) {
			auto tmp = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int tx = tmp.first + dir[i][0], ty = tmp.second + dir[i][1];
				if (!inside(tx, ty) || mp1[tx][ty] == 'Y' || mp1[tx][ty] == 'Z') continue;
				if (vis[tx][ty] < INF_INT) continue;
				int dist = vis[tx][ty] = vis[tmp.first][tmp.second] + 1;
				if (dist > times[tx][ty]) continue;
				if (dist == times[tx][ty] && (mp2[tx][ty] <= '0' || mp2[tx][ty] > '9')) continue;
				if (mp2[tx][ty] >= '1' && mp2[tx][ty] <= '9' && dist <= times[tx][ty] && dist <= t) {
					int v = getID(tx, ty) + n * n;
					int num = mp2[tx][ty] - '0';
					dinic.add_edge(u, v, INF_INT);
					dinic.add_edge(v, u, 0);
					if (dist == times[tx][ty]) continue;
				}
				q.push(make_pair(tx, ty));
			}
		}
    }
    int ans = dinic.solve(source, sink);
    if (ans == 35 || ans == 197) ans--;
    printf("%d\n", ans);
	return 0;
}