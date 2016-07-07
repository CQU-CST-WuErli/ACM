//
//  Created by  CQUWEL
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define filetest
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n;

int main(){
#ifdef LOCAL
	   freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	while (cin >> n && n){
		queue<int> q,q1;
		for (int i=1;i<=n;i++) q.push(i);
		while (q.size()>1){
			int x=q.front();q.pop();
			q1.push(x);
			x=q.front();q.pop();
			q.push(x);
		}
		printf("Discarded cards:");
//		int cnt=1;
		while (q1.size()){
			int x=q1.front();q1.pop();
			printf(" %d",x);
			if (q1.size()!=0)printf(",");
//			cnt++;
		}
		printf("\n");
		int x=q.front();
		printf("Remaining card: %d\n",x); 
	}
	return 0;
}


