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

inline int read() {
    char c = getchar();
    while(!isdigit(c)) c = getchar();
    int x = 0;
    while(isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

const int N=1e6+100;
const int M=10010;

int n,m;
int pnt[N],nxt[N],head[M],cnt;
int pre[M],low[M],inS[M];
int sccno[M];
int dfs_clock,scc_cnt;
stack<int> S;
int in[M];

void init() {
	dfs_clock=scc_cnt=cnt=0;
	OFF(head);
	CLR(pre);
	CLR(sccno);
	CLR(inS);
	while(S.size()) S.pop();
}

void add_edge(int u,int v) {
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt++;
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

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int kase=1;
    while(SII(n,m)==2) {
        init();
        rep(i,1,m) {
        	int u,v;
        	u=read();v=read();
        	add_edge(u,v);
        }
        rep(i,1,n) if (!pre[i]) {
        	// lookln(i);
        	dfs(i);
        }
        CLR(in);
        for (int u=1;u<=n;u++) {
        	for (int i=head[u];~i;i=nxt[i]) {
        		int v=pnt[i];
        		if (sccno[u]!=sccno[v]) in[sccno[v]]++;
        	}
        }
        int ans=0;
        rep(i,1,scc_cnt) if (!in[i]) ans++;
        printf("Case %d: %d\n",kase++,ans);
    }
	return 0;
}