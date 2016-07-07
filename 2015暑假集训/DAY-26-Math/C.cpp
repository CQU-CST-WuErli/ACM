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

vector<int> prime;
int is_prime[10010];
int p,q,r,s;
int e[10010];

void init(){
	int m=sqrt(10000+0.5);
	CLR(is_prime);
	for (int i=2;i<=m;i++) if (!is_prime[i]){
//		prime.push_back(i);
		for (int j=i*2;j<=10000;j+=i) is_prime[j]=1;
	}
	for (int i=2;i<=10000;i++) if (!is_prime[i]) prime.push_back(i);
}

void add_integer(int n,int d){    // 唯一分解上的乘除法  d=-1 除 d=1 乘 
	for (int i=0;i<prime.size();i++){
		while (n%prime[i]==0){
			n/=prime[i];
			e[i]+=d;
		}
		if (n==1) break;
	}
}

void add_factorial(int n,int d){     // 对阶乘进行唯一分解乘除 
	for (int i=1;i<=n;i++)
		add_integer(i,d);
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	init();
//	for (int i=0;i<prime.size();i++) cout << prime[i] << endl;
	while (cin >> p >> q >> r >> s){
		CLR(e);
		add_factorial(p,1);
		add_factorial(q,-1);
		add_factorial(p-q,-1);
		add_factorial(s,1);
		add_factorial(r-s,1);
		add_factorial(r,-1);
		double ans=1.00;
		for (int i=0;i<prime.size();i++) {
			ans*=(double)pow(prime[i],e[i]);
		}
		printf("%.5lf\n",ans);
	}
	return 0;
}


