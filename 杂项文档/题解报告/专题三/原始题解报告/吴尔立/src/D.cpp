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
#include <ctime>
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

int n,A,B;
struct P {
	int x,y;
	P(){}
	void read() {SII(x,y);}
};
P p[1100];
P s[2];
P hate[1100],like[1100];
int dist0[1100],dist1[1100];

inline int dis(P& a,P& b) {
	return abs(a.x-b.x)+abs(a.y-b.y);
}

struct TowSAT {
	const static int NE=5e6;  // edge
	const static int NV=2020;   // node
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
		OFF(head);
		CLR(pre);
		CLR(sccno);
		while (S.size()) S.pop();
		CLR(inS);
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
			for (int v; v != u;) {
				v = S.top(); S.pop();
				inS[v] = 0;
				sccno[v]= scc_cnt;
			}
			// int v;
			// do {
			// 	v = S.top(); S.pop();
			// 	inS[v] = 0;
			// 	sccno[v]= scc_cnt;
			// }while (v != u);
		}
		return low[u];
	}
	int solve() {
		rep(i,0,2*n-1) if (!pre[i]) dfs(i);
	    rep(i,0,n-1) if (sccno[i<<1]==sccno[i<<1|1]) return 0;
	    return 1;
	}
}sat;

int main(int argc, char const *argv[]) {
	freopen("in.txt", "r", stdin);
	// freopen("out1.txt", "w", stdout);
    int t; SI(t);
    while(t--) {
    	SIII(n, A, B);
    	s[0].read();s[1].read();
    	rep(i,0,n-1) p[i].read();
    	rep(i,1,A) hate[i].read(),hate[i].x--,hate[i].y--;
    	rep(i,1,B) like[i].read(),like[i].x--,like[i].y--;
    	int l=0,r=1000000*9;
    	int ans=-1;
    	rep(i,0,n-1) dist0[i]=dis(s[0],p[i]),dist1[i]=dis(s[1],p[i]);
    	int dist01=dis(s[0],s[1]);
    	while(l<=r) {
    	    int mid=(l+r)>>1;
    	    sat.init(n);
    	    rep(i,1,A) {
    	    	int a=hate[i].x,b=hate[i].y;
    	    	sat.add_edge(a<<1,b<<1|1);
    	    	sat.add_edge(a<<1|1,b<<1);
    	    	sat.add_edge(b<<1,a<<1|1);
    	    	sat.add_edge(b<<1|1,a<<1);
    	    }
    	    rep(i,1,B) {
    	    	int a=like[i].x,b=like[i].y;
    	    	sat.add_edge(a<<1,b<<1);
    	    	sat.add_edge(b<<1,a<<1);
    	    	sat.add_edge(a<<1|1,b<<1|1);
    	    	sat.add_edge(b<<1|1,a<<1|1);
    	    }
    	    rep(i,0,n-1) {
    	    	if (dist0[i]>mid) sat.add_edge(i<<1,i<<1|1);
    	    	if (dist1[i]>mid) sat.add_edge(i<<1|1,i<<1);
    	    }
    	    rep(i,0,n-1) rep(j,i+1,n-1) {
    	    	if (dist0[i]+dist0[j]>mid) sat.add_edge(i<<1,j<<1|1),sat.add_edge(j<<1,i<<1|1);
    	    	if (dist1[i]+dist1[j]>mid) sat.add_edge(i<<1|1,j<<1),sat.add_edge(j<<1|1,i<<1);
    	    	if (dist0[i]+dist1[j]+dist01>mid) sat.add_edge(i<<1,j<<1),sat.add_edge(j<<1|1,i<<1|1);
    	    	if (dist0[j]+dist1[i]+dist01>mid) sat.add_edge(i<<1|1,j<<1|1),sat.add_edge(j<<1,i<<1);
    	    }
    	    if (sat.solve()) {
    	    	ans=mid;
    	    	r=mid-1;
    	    }
    	    else l=mid+1;
    	}
    	// cout << ans << "\\n";
    	cout << ans << endl;
    }
	return 0;
}