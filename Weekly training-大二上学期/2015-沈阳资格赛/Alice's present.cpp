//
//  Created by  CQUWEL
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
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
typedef long long  ll;
using namespace std;

const int INF=0x3f3f3f3f;
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1


const int N=5e5+200;
int n,m;
int a[N],p[N];

map<int,int> mp; 

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	while (cin >> n) {
		mp.clear();
		for (int i=1;i<=n;i++) {
			scanf("%d",a+i);
			mp[a[i]]=-1;
		}
		for (int i=n;i>=1;i--) {
			p[i]=mp[a[i]];
			mp[a[i]]=i;
		}
//		for (int i=1;i<=n;i++) cout << p[i] << ' ';
//		puts("");
		cin >> m;
		while (m--) {
			int l,r;
			scanf("%d%d",&l,&r);	
			int ans=-1;
			for (int i=r;i>=l;i--) {
				if (p[i]<=r && p[i]!=-1) {
					ans=i;break;
				}
			}
			if (ans==-1) puts("OK");
			else printf("%d\n",a[ans]);
		}
		puts("");
	}
	return 0;
}

