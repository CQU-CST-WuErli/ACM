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

double dp[300][2];
int n,m,l,r;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SII(n,m)==2) {
	    SII(l,r);
	    if (!n && !m && !l && !r) break;
	    CLR(dp);
	    dp[0][0]=1.0;
	    int cnt=1;
	    rep(j,1,m) {
	    	int w;SI(w);
	 	   	for (int i=0;i<n;i++) {
	 	   		dp[(i+w)%n][cnt]+=dp[i][cnt^1]*0.5;
	 	   		int tmp=i-w;
	 	   		while(tmp<0) tmp+=n;
	 	   		dp[tmp][cnt]+=dp[i][cnt^1]*0.5;
	    	}
	    	cnt^=1;
	    	for (int i=0;i<n;i++) dp[i][cnt]=0;
	    }
	    double ans=0.0;
	    for (int i=l-1;i<=r-1;i++) {
	    	ans+=dp[i][cnt^1];
	    }
	    printf("%.4f\n", ans);
	}
	return 0;
}