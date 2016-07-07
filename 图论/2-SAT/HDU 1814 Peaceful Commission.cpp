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
#include <assert.h>
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

int n,m;

struct TowSAT {
	#define R 1
	#define B 2
	#define W 0
	const static int NE=5e6;  // edge
	const static int NV=3e4;   // node
	int n;
	int pnt[NE],nxt[NE],head[NV];
	int cnt;
	void add_edge(int u,int v) {
		pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt++;
	}

	int low[NV],pre[NV],dfs_clock;
	int sccno[NV],scc_cnt;
	stack<int> S;
	int inS[NV];

	void init(int _n) {
		n=_n;
		cnt=dfs_clock=scc_cnt=0;
		memset(head,-1,sizeof head);
		memset(pre,0,sizeof pre);
		memset(sccno,0,sizeof sccno);
		while (S.size()) S.pop();
		memset(inS,0,sizeof inS);
	}

	int dfs(int u) {
		low[u]=pre[u]=++dfs_clock;
		S.push(u);inS[u]=1;
		for (int i=head[u];~i;i=nxt[i]) {
			int v=pnt[i];
			if (!pre[v]) {
				low[v]=dfs(v);
				low[u]=min(low[u],low[v]);
			}
			else if (inS[v])
				low[u]=min(low[u],pre[v]);
		}
		if (low[u]==pre[u]) {
			scc_cnt++;
			for (int v;v!=u;) {
				v=S.top();S.pop();
				inS[v]=0;
				sccno[v]=scc_cnt;
			}
		}
		return low[u];
	}
	int solve() {
		rep(i,0,2*n-1) if (!pre[i]) dfs(i);
	    rep(i,0,n-1) if (sccno[i<<1]==sccno[i<<1|1]) return 0;
	    return 1;
	}
	int col[NV];
	int s[NV];
	int pos;
	bool DFS(int u) {
		if (col[u]==B) return false;
		if (col[u]==R) return true;
		col[u]=R;
		col[u^1]=B;
		s[pos++]=u;
		for (int i=head[u];~i;i=nxt[i]) {
			int v=pnt[i];
			if (!DFS(v)) return false;
		}
		return true;
	}
	bool getSolution() {
		memset(col,0,sizeof col);
		pos=0;
		rep(i,0,2*n-1) {
			if (col[i]) continue;
			pos=0;
			if (!DFS(i)){
				for (int j=0;j<pos;j++) col[s[j]]=col[s[j]^1]=0;
				if (!DFS(i^1)) return false;
			}
		}
		return true;
	}
}sat;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SII(n,m)==2) {
        sat.init(n);
        rep(i,1,m) {
        	int x,y;
        	SII(x,y);
        	x--,y--;
        	sat.add_edge(x,y^1);
        	sat.add_edge(y,x^1);
        }
        if (sat.getSolution()) {
        	rep(i,0,2*n-1) if (sat.col[i]==1) cout << i+1 << endl;
        }
        else cout << "NIE\n";
    }
	return 0;
}