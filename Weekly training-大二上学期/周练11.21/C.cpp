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

vector<int> g[N];
int n,m;

int low[N],pre[N],in[N],sccno[N];
int dfs_clock,scc_cnt;
stack<int> S;

int dfs(int u) {
	low[u]=pre[u]=++dfs_clock;
	S.push(u);in[u]=1;
	for (int i=0;i<g[u].size();i++) {
		int v=g[u][i];
		if (!pre[v]) {
			low[v]=dfs(v);
			low[u]=min(low[v],low[u]);
		}
		else if (in[v]) low[u]=min(low[u],pre[v]);
	}
	if (pre[u]==low[u]) {
		scc_cnt++;
		int v;
		do {
			v=S.top();S.pop();
			sccno[v]=scc_cnt;in[v]=0;
		}while(u!=v);
	}
	return low[u];
}

void find_scc() {
	dfs_clock=scc_cnt=0;
	CLR(low);CLR(pre);CLR(in);
	while (S.size()) S.pop();
	for (int i=1;i<=n;i++) if (!pre[i]) dfs(i);
}

int ind[N],outd[N];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T_T;
	cin >> T_T;
	while (T_T--) {
		cin >> n >> m;
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=1;i<=m;i++) {
			int u,v;
			SII(u,v);
			g[u].push_back(v);
		}
		find_scc();
//		lookln(scc_cnt);
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
		int ans1=0,ans2=0;
		for (int i=1;i<=scc_cnt;i++) {
//			cout << ind[i] << ' ' << outd[i] << endl;	
			if (!ind[i]) ans1++;
			if (!outd[i]) ans2++;
		}
		cout << (scc_cnt==1?0:max(ans1,ans2)) << endl;
	}
	return 0;
}

