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
const int MOD=10056;
const double eps=1e-9;
const double pi=acos(-1);
typedef unsigned long long  ll;
using namespace std;

int T;
int n;
ll f[1010];
ll c[1010][1010];

void init_1(){
	c[0][0]=1;
	for (int i=1;i<=1000;i++)
		for (int j=0;j<=i;j++){
			if (j==0) c[i][j]=1;
			else {
				c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
			}
		}
}

void init(){
	CLR(f);
	init_1();
	f[0]=1;
	f[1]=1;
	f[2]=3;	
	for (int i=3;i<=1000;i++){
		for (int j=1;j<=i;j++){
			f[i]=(f[i]+(c[i][j]*f[i-j])%MOD)%MOD;
		}
	}
} 

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	init();
	int _;
	for (int kase=scanf("%d",&_);kase<=_;kase++){
		SI(n);
		cout << "Case " << kase << ": " << f[n] << endl; 
	}
	return 0;
}


