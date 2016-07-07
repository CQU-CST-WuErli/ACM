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
#include <numeric>
#include <functional>
#include <unordered_map>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int T;
int w;
int flag;

int solve(){
	int lw,ld,rw,rd;
	cin >> lw >> ld >> rw >> rd;
//	cout << lw << " " << ld << " " << rw << " " << rd << endl; 
	int b1=0,b2=0;
	if (!lw) lw=solve();
	if (!rw) rw=solve();
	if (lw*ld!=rw*rd) flag=0;
	return lw+rw;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//  freopen("C:\\Users\\john\\Desktop\\out.txt","r",stdout);
#endif
	cin >> T;
	while (T--){
		flag=1;
		solve();
		if (flag) cout << "YES\n";
		else cout << "NO\n";
		if (T) cout << endl;

	}
	return 0;
}


