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


int sum[25000];
int maxl,maxr;

void built(int p){
	int l,r;
	maxl=min(p,maxl);
	maxr=max(p,maxr);
	cin >> l;
	if (l!=-1) {
		sum[p-1]+=l;
		built(p-1);
	}  
	cin >> r;
	if (r!=-1) {
		sum[p+1]+=r;
		built(p+1);
	} 
	return;
}


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//  freopen("C:\\Users\\john\\Desktop\\out.txt","r",stdout);
#endif
	int kase=1;
	int x;
	while (cin >> x && x!=-1){
		printf("Case %d:\n",kase++);
		CLR(sum);
		sum[10000]=x;
		maxl=maxr=10000;
		built(10000);
//		cout << maxl << " " << maxr << endl;
		for (int i=maxl;i<=maxr;i++) {
			cout << sum[i];
			if (i!=maxr) cout << " ";
		}
		cout << endl << endl;
	}
	return 0;
}


