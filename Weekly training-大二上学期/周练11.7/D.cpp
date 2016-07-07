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

const int N=500;
int n;
vector<int> g[N];
int low[N],dfn[N],dfs_clock;
int sccno[N],scc_cnt;
stack<int> S;
string scc[26];

int vis[26];
int dfs(int u) {
	low[u]=dfn[u]=++dfs_clock;
	S.push(u);
	for (int i=0;i<g[u].size();i++) {
		int v=g[u][i];
		if (!dfn[v]) {
			low[v]=dfs(v);
			low[u]=min(low[u],low[v]);
		}
		else if (!sccno[v]) {
			low[u]=min(dfn[v],low[u]);
		}
	}
	if (low[u]==dfn[u]) {
		scc_cnt++;
		for (;;) {
			int x=S.top();S.pop();
			sccno[x]=scc_cnt;
			char c=x+'A';
			scc[scc_cnt]+=c;
			if (x==u) break;
		}
		sort(scc[scc_cnt].begin(),scc[scc_cnt].end());
	}
	return low[u];
}

void find_scc() {
	CLR(low);CLR(dfn);CLR(sccno);
	dfs_clock=scc_cnt=0;
	while (S.size()) S.pop();
	for (int i=0;i<26;i++) scc[i].clear();
	for (int i=0;i<26;i++) if (vis[i] && !dfn[i]) {
		dfs(i);
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=1;
	while (cin >> n && n) {
		if (kase!=1) cout << endl;
		getchar();
		for (int i=0;i<26;i++) g[i].clear();
		CLR(vis);
		for (int i=1;i<=n;i++) {
			string s;
			getline(cin,s);
			int u=s[10]-'A';
			vis[u]=1;
			for (int i=0;i<=8;i+=2) {
				int v=s[i]-'A';
				vis[v]=1;
				if (v==u) continue;
				g[u].push_back(v);
			}
		}
		find_scc();
		sort(scc+1,scc+1+scc_cnt);
		for (int i=1;i<=scc_cnt;i++) {
			for (int j=0;j<scc[i].size();j++) {
				if (j) cout << ' ';
				cout << scc[i][j];
			}
			cout << endl;
		}
		kase++;
	}
	return 0;
}

