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

const int N=1010;

int n,v,X;
struct P
{
	int x,v;
	bool operator < (const P& rhs) const {
		return x<rhs.x;
	}
}a[N];
int sum[N];
int dp[N][N][2];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SIII(n,v,X)==3) {
		a[n+1].x=X;a[n+1].v=0;
	    rep(i,1,n) SII(a[i].x,a[i].v);
	    sort(a+1,a+1+n+1);
	    sum[0]=0;
	    rep(i,1,n+1) sum[i]=sum[i-1]+a[i].v;
	    int pos;
	    rep(i,1,n+1) if (a[i].x==X) pos=i;
	    MEM(dp,INF_INT);
	    dp[pos][pos][0]=dp[pos][pos][1]=0;
	    // lookln(pos);
	    for (int i=pos;i>=1;i--) for (int j=pos;j<=n+1;j++) {
	    	if (i==j) continue;
	    	dp[i][j][0]=min(dp[i+1][j][1]+(sum[i]+sum[n+1]-sum[j])*(a[j].x-a[i].x),
	    		dp[i+1][j][0]+(sum[i]+sum[n+1]-sum[j])*(a[i+1].x-a[i].x));
	    	dp[i][j][1]=min(dp[i][j-1][0]+(sum[i-1]+sum[n+1]-sum[j-1])*(a[j].x-a[i].x),
	    		dp[i][j-1][1]+(sum[i-1]+sum[n+1]-sum[j-1])*(a[j].x-a[j-1].x));
	    }
	    cout << min(dp[1][n+1][1],dp[1][n+1][0])*v << endl;
	}
	return 0;
}