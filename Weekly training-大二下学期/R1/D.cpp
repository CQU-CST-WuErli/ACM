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

const int N=60;
const int M=50*50*100+100;
int sum;
int val[N],num[N];
int dp[M/2];
int n;
int V;

void zero(int cost) {
    for(int i=V;i>=cost;i--)
        dp[i]=max(dp[i],dp[i-cost]+cost);
}

void complete(int cost) {
    for(int i=cost;i<=V;i++)
        dp[i]=max(dp[i],dp[i-cost]+cost);
}
void multi(int cost,int amount) {
    if(cost*amount>=V) {
        complete(cost);
        return ;
    }
    int k=1;
    while(k<amount) {
        zero(k*cost);
            amount-=k;
        k<<=1;
    }
    zero(amount*cost);
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SI(n)==1) {
	    if (n<0) break;
	    sum=0;
	    rep(i,1,n) {
	    	SII(val[i],num[i]);
	    	sum+=val[i]*num[i];
	    }
	    V=sum/2;
	    // lookln(V);
	    CLR(dp);
	    rep(i,1,n) multi(val[i],num[i]);
	    int ans=0;
	    rep(i,0,V) if (dp[i]<INF_INT) {
	    	ans=max(ans,dp[i]);
	    }
	    cout << sum-ans << ' ' << ans << endl;
	}
	return 0;
}