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

const int N=5050;

vector<int> g[N];
int n;
int dis[N];
int vis[N];

void dfs(int fa,int u,int d) {
	vis[u]=1;
	dis[u]=max(d,dis[u]);
	rep(i,0,g[u].size()-1) {
		int v=g[u][i];
		if (v==fa || vis[v]) continue;
		dfs(u,v,d+1);
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SI(n)==1) {
		rep(i,0,n) g[i].clear();
		CLR(vis);
		rep(i,1,n) {
			int x;SI(x);
			while (x--) {
				int v;SI(v);
				g[i].push_back(v);
				g[v].push_back(i);
			} 
		}
		OFF(dis);
		CLR(vis);
		dfs(-1,1,0); 
		int Max=-1,root;
		rep(i,1,n) {
			if (dis[i]>Max) {
				Max=dis[i];
				root=i;
			}
		}
		CLR(vis);
		dfs(-1,root,0);
		Max=-1;
		rep(i,1,n) {
			if (dis[i]>Max) {
				Max=dis[i];
				root=i;
			}
		}
		CLR(vis);
		dfs(-1,root,0);
		int tmp=INF_INT;
		rep(i,1,n) tmp=min(tmp,dis[i]);
		cout << "Best Roots  :";
		rep(i,1,n) if (dis[i]==tmp) cout << ' ' << i;
		cout << endl;
		tmp=-1;
		rep(i,1,n) tmp=max(tmp,dis[i]);
		cout << "Worst Roots :";
		rep(i,1,n) if (dis[i]==tmp) cout << ' ' << i;
		cout << endl;
	}
	return 0;
}

