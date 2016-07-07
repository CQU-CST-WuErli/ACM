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
const int MOD=100000000;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n1,n2,k1,k2;
int dp[220][220][2];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SII(n1,n2)==2) {
        SII(k1,k2);
        CLR(dp);
        rep(i,1,k1) dp[i][0][0]=1;
        rep(i,1,k2) dp[0][i][1]=1;
        rep(i,1,n1) rep(j,1,n2) {
        	rep(k,1,min(i,k1)) dp[i][j][0]=(dp[i][j][0]+dp[i-k][j][1])%MOD;
        	rep(k,1,min(j,k2)) dp[i][j][1]=(dp[i][j][1]+dp[i][j-k][0])%MOD;
        }
        cout << (dp[n1][n2][0]+dp[n1][n2][1])%MOD << endl;
    }
	return 0;
}