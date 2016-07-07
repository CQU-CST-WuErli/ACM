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

int n,r;
double p[22];
double sum[22];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=1;
	while (SII(n,r)==2 && (n||r)){
		printf("Case %d:\n",kase++);
		CLR(sum);
		for (int i=0;i<n;i++) scanf("%lf",p+i);
		if (!r) {
			for (int i=0;i<n;i++) puts("0.000000");
			continue;
		}
		double tot=0.00;
		for (int i=0;i<(1<<n);i++){
			double tmp=1.00;
			if (__builtin_popcount(i)==r) {
				for (int j=0;j<n;j++){
					if ((1<<j)&i) tmp*=p[j];
					else tmp*=(1.0-p[j]);
				}
				tot+=tmp;
				for (int j=0;j<n;j++){
					if (i&(1<<j)) sum[j]+=tmp;
				}
			}
		}
		for (int i=0;i<n;i++)
			printf("%.6f\n",sum[i]/tot);
	}
	return 0;
}


