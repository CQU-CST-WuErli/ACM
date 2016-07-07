//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015 CQU_CST_WuErli. All rights reserved.
//
// #include<bits/stdc++.h>
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
#define For_UVa if (kase!=1) cout << endl
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
#define EXIT_SUCCESS 0
template <typename T> T gcd(const T& a,const T& b) {return b==0?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=1e18;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

struct Edge{
	int u,v;
	ll w;
	bool operator < (const Edge& rhs) const {
		return w<rhs.w;
	}
};
vector<Edge> es;
int t;
int n,m;
ll dis[10010];


void update(int l,int r) {
	vector<pair<int,ll> > res;
	for (int i=l;i<=r;i++) {
		Edge e=es[i];
		if (dis[e.u]!=INF_LL && dis[e.u]+e.w<dis[e.v]) res.push_back(make_pair(e.v,dis[e.u]+e.w));
		if (dis[e.v]!=INF_LL && dis[e.v]+e.w<dis[e.u]) res.push_back(make_pair(e.u,dis[e.v]+e.w));
	}
	for (int i=0;i<res.size();i++) {
		pair<int,ll> &tmp=res[i];
		dis[tmp.first]=min(dis[tmp.first],tmp.second);
//		lookln(dis[tmp.first]);lookln(tmp.second);
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	SI(t);
	while (t--) {
		es.clear();
		SII(n,m);
		rep(i,1,m) {
			int u,v;
			ll w;
			scanf("%d%d%I64d",&u,&v,&w);
			es.push_back(Edge{u,v,w});
//			cout << u << ' ' << v << ' ' << w << endl;
		}
		sort(es.begin(),es.end());
		rep(i,1,n) dis[i]=INF_LL;
		dis[1]=0;
		for (int i=0,j;i<es.size();i=j) {
			for (j=i+1;j<es.size();j++) if (es[i].w!=es[j].w) break;
			update(i,j-1);
		}
		if (dis[n]>=INF_LL) cout << "No answer" << endl;
		else cout << dis[n] << endl;
	}
	return EXIT_SUCCESS;
}

