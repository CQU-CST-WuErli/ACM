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
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
template <typename T> T max(T& a,T& b) {return a>b?a:b;}
template <typename T> T min(T& a,T& b) {return a<b?a:b;}
int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
long long gcd (long long a,long long b) {return b==0LL?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=5e4+100; 

int n,m;
struct Edge{
	int u,v,w;
	Edge(){};
	Edge(int _,int __,int ___) {
		u=_;v=__;w=___;
	}
	bool operator < (const Edge& rhs) const {
		return w<rhs.w;
	}
};
vector<Edge> es;
vector<int> ans;

int par[N],rnk[N];

void init(){
	for (int i=0;i<=n;i++) par[i]=i,rnk[i]=0;
	es.clear();ans.clear();
}

int find(int x) {
	return par[x]=par[x]==x?x:find(par[x]);
}

bool same(int x,int y) {
	x=find(x);y=find(y);
	return x==y;
}

void kruskal() {
	sort(es.begin(),es.end());
	for (int i=0;i<es.size();i++) {
		Edge& e=es[i];
		int u=e.u,v=e.v,w=e.w;
		u=find(u);v=find(v);
		if (u==v) {
			ans.push_back(w);
		}
		else {
			if (rnk[u]<rnk[v]) par[u]=v;
			else {
				par[v]=u;
				if (rnk[u]==rnk[v]) rnk[u]++;
			}
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> m && (m+n)) {
		init();
		for (int i=1;i<=m;i++) {
			int u,v,w;
			SIII(u,v,w);
			es.push_back(Edge(u,v,w));
		}
		kruskal();
		if (ans.size()==0) cout << "forest\n";
		else {
			for (int i=0;i<ans.size();i++) {
				if (i) cout << ' ';
				cout << ans[i];
			}
			cout << endl;
		}
	}
	return 0;
}

