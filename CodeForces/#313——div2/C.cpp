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

int a[6];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//  freopen("C:\\Users\\john\\Desktop\\out.txt","r",stdout);
#endif
	while (cin >> a[0]){
	int maxc,tmp;ll sum;
	for (int i=1;i<6;i++) {
		cin >> a[i];
	}
	int x=(a[0]+a[1]+a[2]);
//	cout << x;
	sum=x*x-(a[0]*a[0]+a[2]*a[2]+a[4]*a[4]);
	cout << sum << endl;
}
	return 0;
}


