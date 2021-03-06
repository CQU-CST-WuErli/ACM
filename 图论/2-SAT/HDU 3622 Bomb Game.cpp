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
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

struct Point
{
	int x,y;
	Point(){}
	void read() {
		scanf("%d%db",&x,&y);
	}
}p[220];

double dis(Point& a,Point& b) {
	double dx=a.x-b.x;
	double dy=a.y-b.y;
	return sqrt(dx*dx+dy*dy);
}

int n;

const int N=1e5+100;
const int M=250;
struct TowSAT {
	int n;
	int pnt[N],nxt[N],head[M];
	int cnt;
	void add_edge(int u,int v) {
		pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt++;
	}

	int low[M],pre[M],dfs_clock;
	int sccno[M],scc_cnt;
	stack<int> S;
	int inS[M];

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
}sat;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SI(n)==1) {
        rep(i,0,n-1) {
        	p[i<<1].read();
        	p[i<<1|1].read();
        }
        // rep(i,0,2*n-1) cout << p[i].x << ' ' << p[i].y << endl;
        double R=40000.00,L=0.0;
        // lookln(R);
        while(R-L>=eps) {
        	double mid=(R+L)/2.0;
        	// lookln(mid);
        	sat.init(n);
        	rep(i,0,2*n-2) rep(j,i+1,2*n-1) {
        		if (dis(p[i],p[j])<2*mid) {
        			sat.add_edge(i,j^1);
        			sat.add_edge(j,i^1);
        		}
        	}
        	if (sat.solve()) L=mid;
        	else R=mid;
        }
        printf("%.2f\n",L);
    }
	return 0;
}