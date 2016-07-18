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
template <typename T> T max(T& a,T& b) {return a>b?a:b;}
template <typename T> T min(T& a,T& b) {return a<b?a:b;}
int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
long long gcd (long long a,long long b) {return b==0LL?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1000000000;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=1010;

ll f[N];
ll sum[N];
int n,x,y;
 
void init() {
	f[0]=1;f[1]=1;f[2]=2;
	rep(i,3,1000) {
		f[i]=0;
		rep(j,0,i-1) {
			f[i]=(f[i]+(f[j]*f[i-1-j])%MOD)%MOD;
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	init();
	while (SIII(n,x,y)==3) {
		ll ans=0;
		int len=n-y;
		rep(i,1,n-y) {
			ans=(ans+((f[x]*f[y-x+i])%MOD*f[len--])%MOD)%MOD;
		}
		len=1;
		Rep(i,x-1,1) {
			ans=(ans+(f[i]*(f[y-x+len++]*f[n-y])%MOD)%MOD)%MOD;
		}
		cout << ans+1 << endl;
	}
	return 0;
}
