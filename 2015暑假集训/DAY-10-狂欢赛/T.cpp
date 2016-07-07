//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015Äê CQU_CST_WuErli. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <time.h>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << "x=" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int MOD=1e9+7;
int n,m,k;
ll c[2000][2000];

ll solve(){
	if (2*k>n-1 || 2*k>m-1) return 0;
	return (c[n-1][2*k]*c[m-1][2*k])%MOD;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	for (int i=0;i<1000;i++){
		c[i][0]=1;
		c[i][i]=1;
		for (int j=1;j<=i-1;j++){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
		}
	}
	while (cin >> n >> m >> k) cout << solve() << endl;
	return 0;
}


