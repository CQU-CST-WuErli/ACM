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
const int MOD=10001;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=300;
ll X[N];
ll T;

void exgcd(ll a,ll b,ll &d,ll &x,ll &y){
	if (!b) {
		d=a;
		x=1;y=0;
	}
	else {
		exgcd(b,a%b,d,y,x);
		y-=x*(a/b);
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> T){
		for (int i=1;i<=2*T;i+=2) scanf("%lld",X+i);
		
		for (ll a=0;a<=10000;a++){
			ll k,b,d;
			ll tmp=(X[3]-a*a*X[1]);
			exgcd(MOD,a+1,d,k,b);
			if (tmp%d) continue;
			b=b*tmp/d;
			int flag=1;
			for (ll i=2;i<=2*T;i++){
				if (i%2){
					if (X[i]!=(a*X[i-1]+b)%MOD) {
						flag=0;
						break;
					}
				}
				else{
					X[i]=(a*X[i-1]+b)%MOD;
				}
			} 
			if (flag) break;
		}
		for (ll i=2;i<=2*T;i+=2) cout << X[i] << endl;
	}
	return 0;
}


