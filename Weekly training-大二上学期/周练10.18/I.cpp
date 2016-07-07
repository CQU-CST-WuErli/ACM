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

const int N=30;
int n,m;
vector<int> g[N];
map<string,int> mp;
map<int,string> rmp;
int ID;
vector<int> vc[N];

int low[N],pre[N],dfs_clock;
int scc_cnt;
int sccno[N];
stack<int> S;

void init() {
	for (int i=0;i<=n;i++) {
		g[i].clear();
		vc[i].clear();
	}
	mp.clear();rmp.clear();
	ID=1;
	while (S.size()) S.pop();
	CLR(sccno);
	CLR(low);CLR(pre);
	scc_cnt=dfs_clock=0;
}

int id(string &s) {
	if (!mp.count(s)) {
		mp[s]=ID;
		rmp[ID++]=s;
	}
	return mp[s];
}

int dfs(int u) {
	pre[u]=low[u]=dfs_clock++;
	S.push(u);
	for (int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if (!pre[v]) {
			low[v]=dfs(v);
			low[u]=min(low[u],low[v]);
		}
		else if (!sccno[v]) {
			low[u]=min(low[u],low[v]);
		}
	}
	if (low[u]==pre[u]) {
		scc_cnt++;
		for (;;) {
			int x=S.top();S.pop();
			sccno[x]=scc_cnt;
			if (x==u) break;
		}
	}
	return low[u];
}

void find_scc() {
	for (int i=1;i<ID;i++) if (!pre[i]) dfs(i);
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=1;
	while (cin >> n >> m && ( n || m )) {
		getchar();
		For_UVa;
		init();
		for (int i=1;i<=m;i++) {
			string s,t;
			cin >> s >> t;
			int u=id(s),v=id(t);
			g[u].push_back(v);
		}	
		find_scc();
		for (int i=1;i<ID;i++) {
			vc[sccno[i]].push_back(i);
		}
		printf("Calling circles for data set %d:\n",kase++);
		for (int i=1;i<=scc_cnt;i++){
			if (vc[i].size()) {
				for (int j=0;j<vc[i].size();j++) {
					int x=vc[i][j];
					cout << rmp[x];
					if (j<vc[i].size()-1) cout << ", ";
					else cout << endl;					
				}
			} 
		}
	}
	return 0;
}

