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

const int N=100000+100;

vector<int> G[N];
int deg[N];
int n,m;
int vis[N];

bool solve() {
	queue<int> q;
	CLR(vis);
	int cnt=n;
	for (int i=1;i<=n;i++) {
		if (!deg[i]) {
			q.push(i);
			vis[i]=1;
			cnt--;
		}
	}
	while(q.size()) {
	    int x=q.front();q.pop();
	    for (int i=0;i<G[x].size();i++) {
	    	int v=G[x][i];
	    	if (vis[v]) continue;
	    	deg[v]--;
	    	if (deg[v]==0) {
	    		q.push(v);
	    		vis[v]=1;
	    		cnt--;
	    	}
	    }
	}
	return cnt!=0;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("4.in","r",stdin);
    freopen("4.out","w",stdout);
#endif
	while(SII(n,m)==2) {
	    for (int i=1;i<=n;i++) G[i].clear();
	    CLR(deg);
		for (int i=1;i<=m;i++) {
			int u,v;
			SII(u,v);
			G[v].push_back(u);
			deg[u]++;
		}
		if (solve()) puts("Yes");
		else puts("No");
	}
	return 0;
}