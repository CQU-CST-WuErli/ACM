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
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=1010;

struct Edge {
	int u,v,w;
};

vector<Edge> es;
int pos;
int pre[N],id[N],vis[N],in[N];

int zhuliu(int root,int n,int m) {
	int ret=0;
	for (;;) {
		for (int i=0;i<n;i++) in[i]=INF_INT;
		for (int i=0;i<m;i++) {
			int u=es[i].u;
			int v=es[i].v;
			if (es[i].w<in[v] && u!=v) {
				pre[v]=u;
				in[v]=es[i].w;
				if (u==root) pos=i;
			}
		}
		for (int i=0;i<n;i++) {
			if (i!=root && in[i]==INF_INT) return -1;
		}
		int cntnode=0;
		OFF(id);OFF(vis);
		in[root]=0;
		for (int i=0;i<n;i++) {
			ret+=in[i];
			int v=i;
			while (id[v]==-1 && vis[v]!=i && v!=root) {
				vis[v]=i;v=pre[v];
			}
			if (v!=root && id[v]==-1) {
				for (int u=pre[v];u!=v;u=pre[u])
					id[u]=cntnode;
				id[v]=cntnode++;
			}
		}
		if (cntnode==0) break;
		for (int i=0;i<n;i++) {
			if (id[i]==-1) id[i]=cntnode++;
		}
		for (int i=0;i<m;i++) {
			int v=es[i].v;
			es[i].u=id[es[i].u];
			es[i].v=id[es[i].v];
			if (es[i].u!=es[i].v) es[i].w-=in[v];
		}
		n=cntnode;
		root=id[root];
	}
	return ret;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
int n,m;
	while (cin >> n >> m) {
		es.clear();
		int sum=1;
		for (int i=1;i<=m;i++) {
			int u,v,c;
			SIII(u,v,c);
			es.push_back(Edge{u,v,c});
			sum+=c;
		}
		for (int i=0;i<n;i++) es.push_back(Edge{n,i,sum});
		int ans=zhuliu(n,n+1,n+m);
		if (ans==-1 || ans>=2*sum) cout << "impossible\n";
		else cout << ans-sum << ' ' << pos-m << endl;
		cout << endl;
	}
	return 0;
}

