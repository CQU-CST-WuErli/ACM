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
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=110;
vector<int> g[N];
int low[N],pre[N],dfs_clock;
int n;
stack<int> S;
int scc_cnt;
int sccno[N];
int ind[N],outd[N];

int dfs(int u) {
	low[u]=pre[u]=++dfs_clock;
	S.push(u);
	for (int i=0;i<g[u].size();i++) {
		int v=g[u][i];
		if (!pre[v]) {
			low[v]=dfs(v);
			low[u]=min(low[u],low[v]);
		}
		else if (inS[v]) {
			low[u]=min(pre[v],low[u]);
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
	CLR(low);CLR(pre);CLR(sccno);
	while (S.size()) S.pop();
	scc_cnt=dfs_clock=0;
	for (int i=1;i<=n;i++) {
		if (!pre[i]) dfs(i);
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n) {
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=1;i<=n;i++){
			int x;
			while (cin >> x && x) {
				g[i].push_back(x);
			}
		}
		find_scc();
		if (scc_cnt==1) {
			cout << 1 << '\n' << 0 << endl;
			continue;
		}
		else {
//			lookln(scc_cnt);
			CLR(ind);CLR(outd);
			for (int u=1;u<=n;u++) {
				for (int i=0;i<g[u].size();i++) {
					int v=g[u][i];
					if (sccno[u]!=sccno[v]) {
						outd[sccno[u]]++;
						ind[sccno[v]]++;
					}
				}
			}
			int ans1,ans2;
			ans1=ans2=0;
			for (int i=1;i<=scc_cnt;i++) {
				if (!ind[i]) ans1++;
			}
			for (int i=1;i<=scc_cnt;i++) {
				if (!outd[i]) ans2++;
			}
			cout << ans1 << endl;
			cout << max(ans1,ans2) << endl;
		}
 	}
	return 0;
}

