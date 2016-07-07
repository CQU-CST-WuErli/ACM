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

int g[330][330];
int n;
int vis[330],d[330],dr[330];

int spfa(int s,int *dp){
	CLR(vis);
	for (int i=1;i<=n;i++) dp[i]=INF_INT;
	int cir=INF_INT;
	queue<int> q;
	for (int i=1;i<=n;i++){
		if (i==s) continue;
		q.push(i);
		vis[i]=1;
		dp[i]=g[s][i];
	}
	while (!q.empty()){
		int x=q.front();q.pop();
		vis[x]=0;
		for (int i=1;i<=n;i++){
			int v=i;
			if (dp[v]>dp[x]+g[x][v]){
				dp[v]=dp[x]+g[x][v];
				if (!vis[v]) {
					q.push(v);
					vis[v]=1;
				}
				if (v==s) {
					cir=min(cir,dp[x]+g[x][v]);
				}
			}
		}
	}
	return cir;
}
 

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n){
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++) scanf("%d",&g[i][j]);
		int cir_1,cir_n;
		cir_1=spfa(1,d);
		cir_n=spfa(n,dr);
//		cout << d[n] << ' ' << dr[1] << endl;
//		cout <<cir_1 << ' ' << cir_n << endl;
		cout << min(d[n],cir_1+cir_n) << endl;
	} 
	return 0;
}

