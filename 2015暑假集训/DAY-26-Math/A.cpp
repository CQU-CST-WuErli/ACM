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
#include <ctime>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <functional>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define For_UVa if (kase!=1) cout << endl
#define BUG(x) cout << "I am in line" << x << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef unsigned long long  ll;
using namespace std;

const int N=1e6+10;
int t;
ll a,b,n; 
ll f[N];

ll get_f(){
	f[1]=1%n;f[2]=1%n; 
	for (ll i=3;i<=n*n;i++) {
		f[i]=(f[i-1]+f[i-2])%n;
		if (f[i-1]==f[0] && f[i]==f[1]) {
			return i-1;
		}
	}
}   

ll pow_mod(ll a,ll n,ll m){
	if (n==0) return 1;
	ll x=pow_mod(a,n/2,m);
	ll ans=x*x%m;
	if (n%2==1) ans=ans*a%m;
	return ans;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	cin >> t;
	while (t--){
		cin >> a >> b >> n;
		if (n==1) {
			cout << '0' << endl;
			continue;
		}
		else {
        	ll len=get_f();
			int m=pow_mod(a%len,b,len);
			cout << f[m] << endl;
		}
	}
	return 0;
}


