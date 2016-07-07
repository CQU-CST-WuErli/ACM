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
const int INF_INT=0x7fffffff;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=1100;
const int M=10100;

int n,m;
struct Edge
{
	int u,v;
	double w;
	Edge(){}
	Edge(int u,int v,double w):u(u),v(v),w(w){}
};
vector<Edge> es;
struct P
{
	double x,y;
	void read() {
		cin >> x >> y;
	}
}point[N];
double getd(P& a,P& b) {
	double dx=a.x-b.x;
	double dy=a.y-b.y;
	return sqrt(dx*dx+dy*dy);
}

int pre[N],id[N],vis[N];
double in[N];

double DirectedMST(int root,int n,int m) {
	double ret=0.0;
	for (;;) {
		for (int i=1;i<=n;i++) in[i]=INF_INT*1.0;
		for (int i=0;i<es.size();i++) {
			int u=es[i].u,v=es[i].v;
			double w=es[i].w;
			if (u!=v && in[v]>w) {
				pre[v]=u;
				in[v]=w;
			}
		}
		for (int i=1;i<=n;i++)
			if (i!=root && in[i]>=INF_INT) return -1.0;
		int cntnode=1;
		memset(vis,-1,sizeof vis);
		memset(id,-1,sizeof id);
		in[root]=0;
		for (int i=1;i<=n;i++) {
			ret+=in[i];
			int v=i;
			while(id[v]==-1 && vis[v]!=i && v!=root) {
			    vis[v]=i;v=pre[v];
			}
			if (v!=root && id[v]==-1) {
				for (int u=pre[v];u!=v;u=pre[u])
					id[u]=cntnode;
				id[v]=cntnode++;
			}
		}
		if (cntnode==1) break;
		for (int i=1;i<=n;i++)
			if (id[i]==-1) id[i]=cntnode++;
		for (int i=0;i<es.size();i++) {
			int v=es[i].v;
			es[i].u=id[es[i].u];
			es[i].v=id[es[i].v];
			if (es[i].u!=es[i].v)
				es[i].w-=in[v];
		}
		n=cntnode-1;
		root=id[root];
	}
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(~SII(n,m)) {
        rep(i,1,n) point[i].read();
        es.clear();
        rep(i,1,m) {
        	int u,v;
        	double w;
 			SII(u,v);
 			w=getd(point[u],point[v]);
 			if (u==v) w=INF_INT*1.0;
 			es.push_back(Edge(u,v,w));
        }
        double ans=DirectedMST(1,n,m);
        if (ans==-1.0) printf("poor snoopy\n");
        else printf("%.2f\n", ans);
    }
	return 0;
}