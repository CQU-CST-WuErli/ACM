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

const int N=4e4;

vector<int> g[N];
int par[N];
int deg[N];
int n,m;
int sum;
int x[N],y[N],c[N];


int find(int x) {
	return par[x]=par[x]==x?x:find(par[x]);
}

bool unite(int x,int y) {
	x=find(x);
	y=find(y);
	if (x==y) return false;
	par[x]=y;
	return true;
}

void toposort() {
	queue<int> q;
	for (int i=0;i<n;i++) {
		if (deg[i]==0 && find(i)==i) q.push(i);
	}
	int flag=0;
	
	while (!q.empty()) {
		if (q.size()>1) flag=1;
		int x=q.front();q.pop();
		sum--;
		for (int i=0;i<g[x].size();i++) {
			int v=g[x][i];
			deg[v]--;
			if (deg[v]==0) q.push(v);
		}
	}
	if (sum) cout << "CONFLICT\n";
	else if (flag) cout << "UNCERTAIN\n";
	else cout << "OK\n";
}


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> m) {
		for (int i=0;i<n;i++) {
			g[i].clear();
			par[i]=i;
		}
		CLR(deg);
		sum=n;
		for (int i=1;i<=m;i++) {
			int u,v;
			char C;
			scanf("%d %c %d",&u,&C,&v);
//			cout << u << ' ' << C <<  ' ' << v << endl;
			x[i]=u;c[i]=C;y[i]=v;
			if (C=='=') if (unite(u,v)) sum--;
		}
		for (int i=1;i<=m;i++) {
			if (c[i]!='=') {
				int u=find(x[i]),v=find(y[i]);
				if (c[i]=='>') {
					g[u].push_back(v);
					deg[v]++;
				}
				else if (c[i]=='<') {
					g[v].push_back(u);
					deg[u]++;
				}
			}
		} 
        toposort();
	}
	return 0;
}

