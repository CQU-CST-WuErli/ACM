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

const int N=300;

int n;
int vis[N];
int g[110][110];
int ed;

int dfs(int u) {
//	lookln(u);
	vis[u]=1;
	ed=u;
	for (int i=1;i<=n;i++) {
		if (g[u][i]!=0 && !vis[i]) {
			return dfs(i)+(g[u][i]>0?g[u][i]:0);
		}
	}
	return 0;
}


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SI(n)==1) {
		int sum=0;
		CLR(g);
		rep(i,1,n) {
			int u,v,c;
			SIII(u,v,c);
			g[u][v]=c;
			g[v][u]=-c;
			sum+=c;
		}
		CLR(vis);
		int tmp=dfs(1)+(g[ed][1]>0?g[ed][1]:0);
		if (tmp<0) tmp=-tmp;
		cout << min(sum-tmp,tmp) << endl;
	}
	return 0;
}

