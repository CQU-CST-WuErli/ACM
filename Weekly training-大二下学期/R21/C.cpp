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
const int MOD=20090818;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n,m;
ll f[1010];
ll c[1010][1010];
void init() {
	f[0]=1;
	f[1]=0;f[2]=1;
	rep(i,3,1000) f[i]=(f[i-2]+f[i-1])%MOD*(ll)(i-1)%MOD;
	c[0][0]=1;
	rep(i,1,1000) c[i][0]=1;
	rep(i,1,1000)rep(j,1,i) {
		c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    init();
    while(SII(n,m)==2) {
        int ans=0;
        for (int i=n-m;i<=n;i++) {
     	   	ans+=c[n][i]*f[i]%MOD;
     	   	ans%=MOD;
        }
        printf("%lld\n", ans);
    }
	return 0;
}