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
typedef long long  ll;
using namespace std;

const int N=1300000;
int is_prime[N];
int prime[100010];
int n;
int cnt;

void get_prime(){
	CLR(is_prime);
	for (int i=2;i<=N;i++) if (!is_prime[i]){
		for (int j=2*i;j<=N;j+=i) is_prime[j]=1;
	}
	cnt=0;
	for (int i=2;i<=1299709;i++) if (!is_prime[i]) prime[cnt++]=i;
}


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	get_prime();
//	for (int i=0;i<10;i++) cout << prime[i] << endl;
	while (cin >> n && n){
		if (!is_prime[n]) {
			cout << "0\n";
		}
		else {
			int pos=upper_bound(prime,prime+cnt,n)-prime;
			cout << prime[pos]-prime[pos-1] << endl;
		}
	}
	return 0;
}


