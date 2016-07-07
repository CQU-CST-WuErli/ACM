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
const int N=1e5+10;
ll n;
ll e[N];
int is_prime[N];

void init(){
	CLR(is_prime);
	for (int i=2;i<=N;i++) if (!is_prime[i]){
		for (int j=i*2;j<=N;j+=i) is_prime[j]=1;
	}
}

ll fast_pow(ll a,ll n){
	if (n==0) return 1;
	ll x=fast_pow(a,n/2);
	ll ans=x*x;
	if (n%2) ans=ans*a;
	return ans;
}
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	init();
	int kase=1;
	while (cin >> n && n){
		if (n==1){
			printf("Case %d: 2\n",kase++);
			continue;
		}
		CLR(e);
		vector<ll> prime;
		int cnt=0;
		ll m=sqrt(n+0.5);
		for (ll i=2;i<=m;i++){               // Î¨Ò»·Ö½â 
			int flag=0;
			while (!is_prime[i] && n%i==0){
				if (!flag) {
					flag=1;
					prime.push_back(i);
					cnt++;
				}
				n/=i;
				e[cnt-1]++;
			}
			if (n==1 || n<i) break;
		}
		if (n!=1) {
			prime.push_back(n);
			e[cnt++]=1;
		}
		if (prime.size()<2) {
			prime.push_back(1);
			e[cnt++]=1;
		}
		ll sum=0;
		for (int i=0;i<prime.size();i++){
//			cout << prime[i] <<' ';
			sum+=fast_pow(prime[i],e[i]);
		}
//		cout << endl;
		printf("Case %d: %lld\n",kase++,sum);
	}
	return 0;
}


