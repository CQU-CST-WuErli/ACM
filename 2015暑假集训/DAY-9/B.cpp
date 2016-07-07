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
#include <sstream>
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

int data[20];

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//  freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int n,t = 1;
	while (cin >> n) {
		for (int i = 1 ; i <= n ; ++ i)
			cin >> data[i];
		long long max = 0,neg = 0,pos = 0,tem;
		for (int i = 1 ; i <= n ; ++ i) {
			if (data[i] == 0) 
				neg = pos = 0;
			else if (data[i] > 0) {
				pos = pos*data[i];
				neg = neg*data[i];
				if (!pos) pos = data[i];
			}else if (data[i] < 0) {
				tem = pos*data[i];
				pos = neg*data[i];
				neg = tem;
				if (!neg) neg = data[i];
			}
			if (max < pos && data[i])
				max = pos;
		}
		
		cout << "Case #" << t ++ << ": The maximum product is " << max << ".\n\n";	
	}
	return 0;
}

