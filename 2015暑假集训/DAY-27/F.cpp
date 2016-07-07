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

int phi[2010];

void init(){
	CLR(phi);
	phi[1]=1;
	for (int i=2;i<=2000;i++) if (!phi[i]){
		for (int j=i;j<=2000;j+=i){
			if (!phi[j]) phi[j]=j;
			phi[j]=phi[j]/i*(i-1);
		}
	}
}

ll a,b;


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	init();
	while (cin >> a >> b && (a || b)){
		double ans;
		ll N=(2*a+1)*(2*b+1)-1;
		ll sum=0;
		for (ll i=1;i<=a;i++){
			ll tmp=b/i;
			sum+=tmp*phi[i];
			for (ll j=tmp*i+1;j<=b;j++) 
				if (__gcd(j,i)==1) sum++;
		}
		sum=sum*4+4;
		ans=(double)sum/(double)(N)*1.00;
		printf("%.7f\n",ans);
	}
	return 0;
}


