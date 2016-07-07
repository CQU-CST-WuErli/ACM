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
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=100010;
int n,m;
int vis[N];
vector<int> g[N];
void init() {
	rep(i,1,n) g[i].clear();
}

bool dfs(int fa,int u) {
	vis[u]=1;
	for (int i=0;i<g[u].size();i++) {
		int v=g[u][i];
		if (v==fa) continue;
		if (vis[v]) return true;
		else if (dfs(u,v)) return true;
	}
	return false;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SII(n,m)==2) {
	    init();
	    rep(i,1,m) {
	    	int u,v;
	    	SII(u,v);
	    	g[u].push_back(v);
	    	g[v].push_back(u);
	    }
	    CLR(vis);
	    int ans=0;
	    rep(i,1,n) if (!vis[i]) {
	    	ans+=!dfs(-1,i);
	    }
	    cout << ans << endl;
	}
	return 0;
}