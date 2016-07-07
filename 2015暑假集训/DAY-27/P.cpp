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
#define BUG cout << "I am in line" << x << endl
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
typedef long long  ll;
using namespace std;
const int N=1e6+10;
int is_prime[N];
int prime[N];
int len;

void init(){
	CLR(is_prime);
	for (int i=2;i<=N;i++) if (!is_prime[i]){
		for (int j=i*2;j<=N;j+=i) is_prime[j]=1;
	}
	len=0;
	for (int i=2;i<=N;i++) if (!is_prime[i]) prime[len++]=i;
}

ll quick_pow(ll a,ll n){
	if (n==0) return 1;
	ll x=quick_pow(a,n/2);
	ll ans=x*x;
	if (n%2) ans=ans*a;
	return ans;
}

ll solve(ll n){
	vector<int> e;
	ll tmp=abs(n);
	for (ll i=0;i<len;i++){
		ll p=prime[i];
		if (p>abs(n)) break;
		if (tmp%p==0) {
			ll cnt=0; 
			while (tmp%p==0) {
				tmp/=p;
				cnt++;
			}
			e.push_back(cnt);
		}
		if (tmp==1) break;
	}
	if (tmp>1) return 1;
	ll ans=0;
	for (ll i=0;i<e.size();i++){
		ll x=e[i];
		ans=__gcd(ans,x);
	}
	if (ans==0 ) return 1;
	else return ans;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	init();
	ll n;
	while (cin >> n && n){
		int ans=solve(n);
		if (n<0) {
			while (ans%2==0) ans/=2;
		}
		cout << ans << endl;
	} 
	return 0;
}


