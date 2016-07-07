//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
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
#include <ctime>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
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
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=33;

int mp[N][N];
int n;
int dead[N];

int vis[33];
int ans;
void dfs(int u,int cnt,int dis,int sum) {
	if (sum>=ans) return;
	if (sum+(n-cnt)*dis>=ans) return;
	if (cnt==n) {
		ans=min(ans,sum);
		return;
	}
	for (int i=1;i<=n;i++) if (!vis[i] && dead[i]<dis) return;
	for (int v=1;v<=n;v++) if (v!=u) {
		if (dis+mp[u][v]<=dead[v]) {
			if (!vis[v]) {
				vis[v]=1;
				dfs(v,cnt+1,dis+mp[u][v],sum+dis+mp[u][v]);
				vis[v]=0;
			}
		}
	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SI(n)==1) {
	    rep(i,1,n) rep(j,1,n) SI(mp[i][j]);
	    dead[1]=0;
	    rep(i,2,n) SI(dead[i]);
	    rep(k,1,n) rep(i,1,n) rep(j,1,n) mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
	    ans=INF_INT;
 		CLR(vis);
 		vis[1]=1;
 		dfs(1,1,0,0);
 		if (ans>=INF_INT) puts("-1");
 		else cout << ans << endl;
	}
	return 0;
}