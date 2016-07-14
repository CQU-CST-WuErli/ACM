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

typedef pair<int,int> P;

P a,x,y;

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//  freopen("C:\\Users\\john\\Desktop\\out.txt","r",stdout);
#endif
	while (cin >> a.first >> a.second){
		cin >> x.first >> x.second;
		cin >> y.first >> y.second;
		int flag=0;
		if (x.first+y.first<=a.first && max(x.second,y.second)<=a.second) flag=1;
		if (x.first+y.second<=a.first && max(x.second,y.first)<=a.second) flag=1;
		if (x.second+y.first<=a.second && max(x.first,y.second)<=a.first) flag=1;
		if (x.second+y.second<=a.second && max(x.first,y.first)<=a.first) flag=1;
		if (x.second+y.first<=a.first && max(x.first,y.second)<=a.second) flag=1;
		if (x.second+y.second<=a.first && max(x.first,y.first)<=a.second) flag=1;
		if (x.first+y.first<=a.second && max(x.second,y.second)<=a.first) flag=1;
		if (x.first+y.second<=a.second && max(x.second,y.first)<=a.first) flag=1;
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}


