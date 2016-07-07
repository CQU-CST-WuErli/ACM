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

int mab[11000];

int main(){
#ifdef LOCAL
	  freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	int n,q;
	int kase=1;
	while (cin >> n >> q && (n||q)){
		printf("CASE# %d:\n",kase++);
		for (int i=1;i<=n;i++) cin >> mab[i];
		sort(mab+1,mab+1+n);
		for (int i=1;i<=q;i++){
			int op;
			cin >> op;
			int ans=0;
			for (int j=1;j<=n;j++){
				if (mab[j]==op){
					ans=j;
					break;
				}
			}
			if (!ans) printf("%d not found\n",op);
			else printf("%d found at %d\n",op,ans);
		}
	}
	return 0;
}


