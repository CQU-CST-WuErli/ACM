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
#include <ctime>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <functional>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define for_uva if (kase!=1) cout << endl
#define BUG(x) cout << "I am in line" << x << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=1e5+10;

int n,p[N],t[N];
int dp[10005][10005][2];
int kase,vis[10005][10005][2];

int dfs(int l,int r,bool rig){
	int &ret=dp[l][r][rig];
	if (vis[l][r][rig]==kase) return ret;
	vis[l][r][rig]=kase;
	if (l>r) return INF;
	if (l==r) return 0;
	ret=INF;
	if (rig){
		int tim=min(dfs(l,r-1,0)+p[r]-p[l],dfs(l,r-1,1)+p[r]-p[r-1]);
		if (tim<=t[r]) ret=min(ret,tim);
	}
	else {
		int tim=min(dfs(l+1,r,0)+p[l+1]-p[l],dfs(l+1,r,1)+p[r]-p[l]);
		if (tim<=t[l]) ret=min(ret,tim);
	}
	return ret;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	kase=1;CLR(vis);
	while (scanf("%d",&n)==1){
		for (int i=1;i<=n;i++) scanf("%d%d",p+i,t+i);
		int ans=min(dfs(1,n,0),dfs(1,n,1));
		if (ans=INF) cout << "No solution\n";
		else cout << ans << endl;
		kase++;
	}
	return 0;
}
