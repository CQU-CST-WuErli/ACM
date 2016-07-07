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

int n, m;
vector<int> g[100010];
int deg[100010];
int topo[100010];
int vis[100010];
int cnt;
void toposort() {
	priority_queue<int> q;
	CLR(vis);
	cnt = 1;
	for (int i = 1; i <= n; i++) {
		if (!deg[i]) {
			q.push(i);
			vis[i] = 1;
		}
	}
	while(q.size()) {
	    int x = q.top(); q.pop();
	    topo[cnt++] = x;
	    // cout << x << endl;
	    for (int i = 0; i < g[x].size(); i++) {
	    	int v = g[x][i];
	    	if (vis[v]) continue;
	    	deg[v]--;
	    	if (deg[v] == 0) {
	    		vis[v] = 1;
	    		q.push(v);
	    	}
	    }
	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while(t--) {
        SII(n, m);
        CLR(deg);
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1; i <= m; i++) {
        	int u, v;
        	SII(u, v);
 	       	g[u].push_back(v);
 	       	deg[v]++;
        }
        toposort();
        ll ans = 0;
        int Min = INF_INT;
        for (int i = 1; i < cnt; i++) {
        	Min = min(Min, topo[i]);
        	ans += Min;
        }
        cout << ans << endl;
    }
	return 0;
}