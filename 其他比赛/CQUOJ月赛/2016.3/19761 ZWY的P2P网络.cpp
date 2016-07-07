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

struct Edge{
	int u,v,dis;
	Edge(int u,int v,int dis):u(u),v(v),dis(dis){}
	bool operator < (const Edge& rhs) const {
		return dis<rhs.dis;
	}
};
vector<Edge> es;
int n,m;

int par[330];

void init() {
	rep(i,0,300) par[i]=i;
}

int find(int x) {
	if (par[x]==x) return x;
	return par[x]=find(par[x]);
}

bool same(int u,int v) {
	return find(u)==find(v);
}

void unite(int x,int y) {
	x=find(x),y=find(y);
	if (x==y) return;
	par[x]=y;
	return;
}

void kruskal() {
	init();
	sort(es.begin(),es.end());
//	lookln(es.size());
	vector<int> v;
	int ret1=0;
	rep(i,0,es.size()-1) {
 		Edge& e=es[i];
// 		cout << e.u << ' ' << e.v << endl;
 		if (!same(e.v,e.u)) {
// 			lookln(e.dis);
 			unite(e.u,e.v);
 			ret1+=e.dis;
 			v.push_back(i);
 		}
	}
	int flag=0;
	rep(i,0,v.size()-1) {
		init();
		int ret2=0;
		rep(j,0,es.size()-1) {
			if (j==v[i]) continue;
			Edge& e=es[j];
 			if (!same(e.v,e.u)) {
 				unite(e.u,e.v);
 				ret2+=e.dis;
 			}
		}
		set<int> st;
		rep(i,1,n) st.insert(find(i));
		if (st.size()==1 && ret1==ret2) {
			flag=1;break;
		}
	}
	if (flag) cout << "ZWY Wake Up!" << endl;
	else cout << ret1 << endl;
//	cout << ret1 << endl;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif

    int t;SI(t);
    while(t--) {
        SII(n,m);
        es.clear();
        rep(i,1,m) {
        	int u,v,dis;
        	SIII(u,v,dis);
        	es.push_back(Edge(u,v,dis));
        }
        kruskal();
    }
	return 0;
}
