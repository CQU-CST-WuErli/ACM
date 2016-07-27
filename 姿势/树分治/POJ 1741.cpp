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
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=1e4+100;

int n,k;
int pnt[N<<1],nxt[N<<1],head[N],w[N<<1];
int cnt;
void add_edge(int u,int v,int cost) {
	pnt[cnt]=v;nxt[cnt]=head[u];w[cnt]=cost;head[u]=cnt++;
}

int centroid;
int sz[N],mx[N];
int vis[N];
int ans;

int getSize(int fa,int u) {
	int ret=1;
	for (int i=head[u];~i;i=nxt[i]) {
		int v=pnt[i];
		if (vis[v] || v==fa) continue;
		ret+=getSize(u,v);
	}
	return ret;
}

void getCentroid(int fa,int u,int all) {
	sz[u]=1;mx[u]=0;
	for (int i=head[u];~i;i=nxt[i]) {
		int v=pnt[i];
		if (v==fa || vis[v]) continue;
		getCentroid(u,v,all);
		sz[u]+=sz[v];
		mx[u]=max(mx[u],sz[v]);
	}
	mx[u]=max(mx[u],all-sz[u]);
	if (!centroid || mx[u]<mx[centroid]) centroid=u;
}

void getDis(int fa,int u,int dis,vector<int>& ds) {
	ds.push_back(dis);
	for (int i=head[u];~i;i=nxt[i]) {
		int v=pnt[i];
		if (vis[v] || v==fa) continue;
		getDis(u,v,dis+w[i],ds);
	}
}

int cal(vector<int>& ds) {
	sort(ds.begin(),ds.end());
	int ret=0;
	for (int i=0,j=ds.size()-1;i<j;i++) {
		while (i<j && ds[i]+ds[j]>k) j--;
		ret+=j-i;
	}
	return ret;
}

void solve(int u) {
	// lookln(u);
	centroid=0;
	getCentroid(-1,u,getSize(-1,u));
	int x=centroid;
	vis[x]=1;
	for (int i=head[x];~i;i=nxt[i]) {
		int v=pnt[i];
		if (vis[v]) continue;
		solve(v);
	}
	vector<int> ds;
	ds.push_back(0);
	for (int i=head[x];~i;i=nxt[i]) {
		int v=pnt[i];
		if (vis[v]) continue;
		vector<int> tds;
		getDis(x,v,w[i],tds);
		ans-=cal(tds);
		ds.insert(ds.end(),tds.begin(),tds.end());
	}
	ans+=cal(ds);
	vis[x]=0;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SII(n,k)==2 && (n|| k)) {
		OFF(head);cnt=0;
	    rep(i,1,n-1) {
	    	int u,v,cost;
	    	SIII(u,v,cost);
	    	// cout << u << ' ' << v << ' ' << cost << endl;
	    	add_edge(u,v,cost);
	    	add_edge(v,u,cost);
	    }
	    ans=0;
	    solve(1);
	    cout << ans << endl;
	}
	return 0;
}