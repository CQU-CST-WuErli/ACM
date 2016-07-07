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

const int N=110;
int n,m;
int mp[N][N];

int F[N][N];
int dis[N];
int pre[N];
int vis[N];
int used[N][N];
int prim() {
	CLR(vis);CLR(F);
	CLR(used);
	rep(i,1,n) {
		dis[i]=mp[1][i];
		pre[i]=1;
	}
	dis[1]=0;vis[1]=1;
	int ret=0;
	rep (i,2,n) {
		int mincost=INF_INT-1;
		int minid=-1;
		rep(j,1,n) if (!vis[j] && dis[j]<mincost) {
			mincost=dis[j];
			minid=j;
		}
		vis[minid]=1;
		ret+=mincost;
		used[minid][pre[minid]]=used[pre[minid]][minid]=1;
		// lookln(mincost);
		rep(j,1,n) {
			if (!vis[j] && dis[j]>mp[minid][j]) {
				dis[j]=mp[minid][j];
				pre[j]=minid;
			}
			if (vis[j] && j!=minid) {
				F[minid][j]=F[j][minid]=max(F[j][pre[minid]],mincost);
			}
		}
	}
	return ret;
}

int SBMST() {
	int tmp=prim();
	int ans=INF_INT;
	rep(i,1,n) rep(j,1,n) if (!used[i][j] && i!=j) ans=min(ans,tmp+mp[i][j]-F[i][j]);
	if (tmp==ans) return -1;
	// lookln(ans);
	return tmp;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t;SI(t);
	while(t--) {
		SII(n,m);
		MEM(mp,INF_INT);
		rep(i,1,m) {
			int u,v;
			int w;
			SIII(u,v,w);
			mp[u][v]=mp[v][u]=w;
		}
		int ans=SBMST();
		if (ans==-1) puts("Not Unique!");
		else cout << ans << endl;
	}
	return 0;
}