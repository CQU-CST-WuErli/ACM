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

int n,m;
int a[110],b[110]; 
int g[110][110];

int used[110],vis[110],match[110];

int dfs(int u) {
	for (int i=1;i<=m;i++) if (g[u][i]){
		if (!vis[i]) {
			vis[i]=1;
			if (match[i]==0 || dfs(match[i])) {
				match[i]=u;
				return 1;
			}
		}
	}
	return 0;
}

int hungry() {
	int ret=0;
	CLR(match);
	for (int i=1;i<=n;i++) {
		CLR(vis);
		if (!vis[i]) ret+=dfs(i);
	}
	return ret;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n) {
		
		for (int i=1;i<=n;i++) cin >> a[i];
		cin >> m;
		for (int i=1;i<=m;i++) cin >> b[i];
		CLR(g);
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) {
				if (abs(a[i]-b[j])<=1) {
					g[i][j]=1;
				}
			}
		}
		int ans=hungry();
		cout << ans << endl;
	}
	return 0;
}

