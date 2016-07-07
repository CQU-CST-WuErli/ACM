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
#define Rep(flag,start,end) for (int flag=start;flag>=end;flag--)
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
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=1e5+100;
ll prime[N];
int isprime[N];
int cnt;
int n;

void getPrime() {
	CLR(isprime);cnt=1;
	for (int i=2;i<N;i++) if (!isprime[i]) {
		for (int j=i+i;j<N;j+=i) isprime[j]=1;
	}
	prime[0]=0;
	for (int i=2;i<N;i++) if (!isprime[i]) prime[cnt++]=i;
	
	for (int i=0;i<cnt;i++) prime[i]*=prime[i];
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int t;
	SI(t);
	getPrime();
//	for (int i=1;i<10;i++) cout << prime[i] << endl;
	while (t--) {
		cin >> n;
		int pos=lower_bound(prime,prime+cnt,n)-prime;
		int dis=INF_INT;
		ll ans;
		if (prime[pos-1]!=0 && abs(n-prime[pos-1])<dis){
			ans=prime[pos-1];
			dis=abs(n-prime[pos-1])	;
		}
		if (abs(n-prime[pos])<dis) {
			ans=prime[pos];
			dis=abs(n-prime[pos]);
		}
		cout << ans << endl;
	}
	return 0;
}

