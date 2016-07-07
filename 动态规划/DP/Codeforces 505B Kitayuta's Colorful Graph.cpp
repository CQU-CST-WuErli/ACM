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
template <typename T> T gcd(const T& a,const T& b) {return b==0?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=250;
int pnt[N],nxt[N],head[N],cor[N];
int cnt;
int n,m,q;
int ans;
int vis[N];
int from,to;

void add_edge(int u,int v,int c) {
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt;
	cor[cnt++]=c;
}

void dfs(int fa,int u,int color) {
	vis[u]=1;
	if (u==to) {
		ans++;
		return;
	}
	for (int i=head[u];~i;i=nxt[i]) {
		int v=pnt[i];
		if (vis[v] || v==fa) continue;
		if (cor[i]!=color) continue;
		dfs(u,v,color);
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SII(n,m)==2) {
		OFF(head);cnt=0;
		rep(i,1,m) {
			int u,v,c;
			SIII(u,v,c);
			add_edge(u,v,c);
			add_edge(v,u,c);
		}
//		lookln(cnt);
		SI(q);
		while (q--) {
			SII(from,to);
			ans=0;
			rep(i,1,m) {
				CLR(vis);
				dfs(0,from,i);
			}
			cout << ans << endl;
		}
	}
	return 0;
}

