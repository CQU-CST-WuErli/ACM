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
#define maxn 100
ll W,w[maxn];
ll d[1<<20];
int N;
ll ans;

int main()
{
///	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	while (scanf("%d%lld",&N,&W)==2){
		for (int i=0;i<N;i++)
			scanf("%lld",&w[i]);
		int n2=N>>1;
		ll p1=1<<n2;
		ll p2=1<<(N-n2);
		int cnt=0;
		ans=0;
		for (ll i=0;i<p1;i++){
			ll temp=0;
			for (ll j=0;j<n2;j++)
				if (i>>j & 1){
					temp+=w[j];
				}
			if (temp<=W) d[cnt++]=temp;
		} 
		sort(d,d+cnt);
//		for (int i=0;i<cnt;i++) cout << d[i] << " ";
//		cout << endl;
		ans=d[cnt-1];
		for (int i=0;i<p2;i++){
			ll temp=0;
			for (int j=0;j<(N-n2);j++){
				if (i>>j&1){
					temp+=w[j+n2];
				}
			}
			if (temp<=W){
//				cout << "temp=" << temp << endl;
				ll loc=upper_bound(d,d+cnt,W-temp)-d-1;
//				cout << "loc=" << loc << endl;
				ans=max(ans,temp+d[loc]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}


