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

const int N=60;
int n,m,d;
double dp[10010][N];
vector<int> g[N];

double cal(int x) {
	CLR(dp);
	for (int i=1;i<=n;i++)
		dp[0][i]=1.0/n;
	for (int i=0;i<d;i++) {
		for (int j=1;j<=n;j++) {
			if (j==x) continue;
			double tmp=1.0/g[j].size();
			for (int k=0;k<g[j].size();k++) {
				dp[i+1][g[j][k]]+=dp[i][j]*tmp;
			}
		}
	}
	double ret=0.0;
	for (int i=0;i<=d;i++) ret+=dp[i][x];
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int t;SI(t);
	while(t--) {
	    SIII(n,m,d);
	    rep(i,1,n) g[i].clear();
	    rep(i,1,m) {
	    	int u,v;
	    	SII(u,v);
	    	g[u].push_back(v);
	    	g[v].push_back(u);
	    }
	    rep(i,1,n) printf("%.10f\n", 1-cal(i));
	}
	return 0;
}