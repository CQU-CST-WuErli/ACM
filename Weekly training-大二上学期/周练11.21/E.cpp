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

const int N=2e4+110;
int n,m;
int w[N];
int sum[N];

int pnt[N],nxt[N],head[N],cnt;
void add_edge(int u,int v) {
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt++;
}

// tarjan
int low[N],pre[N],bccno[N],in[N];
int dfs_clock,bcc_cnt;
stack<int> S;

void dfs(int fa,int u) {
	low[u]=pre[u]=++dfs_clock;
	S.push(u);in[u]=1;
	int flag=1;
	for (int i=head[u];~i;i=nxt[i]) {
		int v=pnt[i];
		if (v==fa && flag) {
			flag=0;
			continue;
		}
		if (!pre[v]) {
			dfs(u,v);
			low[u]=min(low[u],low[v]);
		}
		else if (in[v]) low[u]=min(low[u],pre[v]);
	}
	if (low[u]==pre[u]) {
		int v=-1;bcc_cnt++;
		do {
			v=S.top();S.pop();
			bccno[v]=bcc_cnt;
			sum[bcc_cnt]+=w[v];
			in[v]=0;
		}while(u!=v);
	}
}

void find_bcc(){
	dfs_clock=bcc_cnt=0;
	while(S.size()) S.pop();
	CLR(low);CLR(pre);CLR(bccno);CLR(in);CLR(sum);CLR(in);
	for (int i=0;i<n;i++) if (!pre[i]) dfs(-1,i);
}

// tree dp
vector<int> g[N];
int tot,ans;

int vis[N];
int DP(int fa,int u) {
	int tmp=sum[u];
	vis[u]=1;
	for (int i=0;i<g[u].size();i++) {
		int v=g[u][i];
		if (v==fa || vis[v]) continue;
		tmp+=DP(u,v);
	}
	ans=min(ans,abs(tot-2*tmp));
	return tmp;
}


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> m) {
		OFF(head);cnt=0;tot=0;
		for (int i=0;i<n;i++) scanf("%d",w+i),tot+=w[i];
		for (int i=1;i<=m;i++) {
			int u,v;
			SII(u,v);
			add_edge(u,v);
			add_edge(v,u);
		}
		find_bcc();
//		lookln(bcc_cnt);
		if (bcc_cnt==1) {
			cout << "impossible\n";
			continue;
		}
//		for (int i=1;i<=bcc_cnt;i++) cout << sum[i] << ' ';
//		cout << endl;
		for (int i=0;i<=n;i++) g[i].clear();
		for (int u=0;u<n;u++) {
			for (int i=head[u];~i;i=nxt[i]) {
				int v=pnt[i];
//				cout << "u=" << u << "v=" << v << endl;
				if (bccno[u]!=bccno[v]) {
					g[bccno[u]].push_back(bccno[v]);
					g[bccno[v]].push_back(bccno[u]);
				}
			}
		}
		CLR(vis);
		ans=INF_INT;
		DP(-1,1);
		cout << ans << endl;
	}
	return 0;
}

