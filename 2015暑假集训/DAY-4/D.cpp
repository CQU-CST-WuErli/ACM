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

ll n;
typedef pair<ll,ll> P;

map<P,ll> sp;

int main(){
#ifdef LOCAL
	   freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	while (scanf("%lld",&n)!=EOF && n){
		ll cnt=0;
		for (int i=0;i<n;i++){
			ll u,v;
			scanf("%lld%lld",&u,&v);
			P tmp;
			tmp.first=min(u,v);
			tmp.second=max(u,v);
			if (!sp.count(tmp)) sp[tmp]=1;
			else sp[tmp]++;
		}
		int flag=0;
		for (map<P,ll>::iterator it=sp.begin();it!=sp.end();it++){
			if (it->second %2!=0){
				flag=1;
				break;
			}
		}
		if (flag) printf("NO\n");
		else printf("YES\n");
		sp.clear();
	}
	return 0;
}


