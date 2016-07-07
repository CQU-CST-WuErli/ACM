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
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;


ll n,m,k;
ll mm[12],a[12];

ll quick_pow_mod(ll a,ll b,ll p){
	 ll ans = 1;  
    a %= p;  
    while(b) {  
        if(b & 1) ans = ans * a % p;  
        b >>= 1;  
        a = a * a % p;  
    }  
    return ans; 
} 

ll quick_mul_mod(ll a,ll b,ll mod){
	ll ret = 0;  
    while(b) {  
        if(b & 1)    ret = (ret + a) % mod;  
        a = (a + a) % mod;  
        b >>= 1;  
    }  
    return ret;  
} 

ll ex_gcd(ll a,ll b,ll &x,ll &y){
	ll d;
	if (b==0) {
		x=1;y=0;
		return a;
	}
	d=ex_gcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}

ll C(ll n,ll m,ll p){
	if (m>n) return 0;
	ll ans=1;
	for (int i=1;i<=m;i++){
		ll a=(n+i-m);
		ll b=i%p;
		ans=ans*(a*quick_pow_mod(b,p-2,p)%p)%p;
	}
	return ans;
} 

ll Lucas(ll n,ll m,ll p){
	if (m==0) return 1%p;
	return C(n%p,m%p,p)*Lucas(n/p,m/p,p)%p;
}

ll CRT() {
	ll d,x,y,tmp,M,ret;
	ret=0;
	M=1;
	for (int i=0;i<k;i++) M*=mm[i];
	for (int i=0;i<k;i++){
		tmp=M/mm[i];
		d=ex_gcd(mm[i],tmp,x,y);
		ll temp=quick_mul_mod(y,tmp,M);
		temp=quick_mul_mod(temp,a[i],M);
		ret=(ret+temp)%M;
	}
	return (M+ret)%M;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int _;SI(_);
	while (_--){
		cin >> n >> m >> k;
		for (int i=0;i<k;i++){
			cin >> mm[i];
			a[i]=Lucas(n,m,mm[i]);
		}
		cout << CRT() << endl;
	}

	return 0;
}

