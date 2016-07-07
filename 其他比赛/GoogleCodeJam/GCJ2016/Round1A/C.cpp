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

const int N=4000;
const int M=1010;
int n;
int vis[N];
int a[N];
int dp[N];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    for (int T_T,kase=SI(T_T);kase<=T_T;kase++) {
    	SI(n);
    	rep(i,1,n) SI(a[i]);
    	int ans=0;
    	for (int i=1;i<=n;i++) {
    		int v=i;
    		CLR(vis);
    		int tmp=0;
    		while(1) {
    		    vis[v]=1;
    		    v=a[v];
    		    tmp++;
    		    if (vis[v]) break;
    		}
    		if (v==i) ans=max(ans,tmp);
    	}
    	CLR(dp);
    	rep(i,1,n) rep(j,1,n) if (a[a[j]]!=j) dp[a[j]]=max(dp[a[j]],dp[j]+1);
    	CLR(vis);
    	int sum=0;
    	rep(i,1,n) if (vis[i]==0 && a[a[i]]==i) {
    		sum+=dp[i]+dp[a[i]]+2;
    		vis[i]=vis[a[i]]=1;
    	}
    	ans=max(ans,sum);
    	printf("Case #%d: %d\n", kase, ans);
    }
	return 0;
}