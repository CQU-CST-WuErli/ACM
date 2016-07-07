//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015 CQU_CST_WuErli. All rights reserved.
//
// #include<bits/stdc++.h>
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
#define For_UVa if (kase!=1) cout << endl
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
template <typename T> T gcd(const T& a,const T& b) {return b==0?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

ll l,r;

ll dp[20];
ll fac[20];

ll cal(ll x) {
	if (x<10) return x;
	if (x<100) return 9+x/11;
	int A[20];
	int cnt=0;
	while (x) {
		A[++cnt]=x%10;
		x/=10;
	}
	ll ret=0;
	rep(i,1,cnt-1) 	ret+=dp[i];
	rep(i,1,A[cnt]-1) ret+=fac[cnt-2];
//	lookln(ret);
	ll tmp=0;
	Rep(i,cnt-1,2) tmp=tmp*10+A[i];
//	lookln(tmp);
	if (A[cnt]<=A[1]) ret++;
	return ret+tmp;
}

int main(){
#ifdef LOCAL
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	dp[0]=0;dp[1]=9;dp[2]=9;
	rep(i,3,18) dp[i]=10*dp[i-1];
	fac[0]=1;fac[1]=10;
	rep(i,2,18) fac[i]=fac[i-1]*10;
//	cal(8547);
	while (cin >> l >> r) {
		ll L=cal(l-1),R=cal(r);
//		lookln(L);
//		lookln(R);
		ll ans=R-L;
		cout << ans << endl;
	}
	return 0;
}

