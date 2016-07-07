//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015 CQU_CST_WuErli. All rights reserved.
//
// #include<bits/stdc++.h>
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
#include <sstream>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=5e5+100;

ll a[N];
ll sum;
int n;

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n) {
		sum=0;
		for (int i=1;i<=n;i++) {
			int x;
			scanf("%d",&x);
			sum+=x;
			a[i]=(i==1?x:a[i-1]+x);
		}
		if (sum%3!=0) {
			cout << 0 << endl;
			continue;
		}
		if (sum!=0) {
			ll x=sum/3;
			ll y=x*2;
			vector<int> vc;
			for (int i=1;i<n;i++) {
				if (a[i]==x) vc.push_back(1);
				if (a[i]==y) vc.push_back(2);
			}
			ll ans=0,cnt=0;
			for (int i=0;i<vc.size();i++) {
				if (vc[i]==1) cnt++;
				if (vc[i]==2) ans+=cnt;
			}
			cout << ans << endl;
		}
		else {
			ll ans=0;
			for (int i=1;i<n;i++) {
				if (a[i]==0) ans++;
			}	
			ans=(ans*(ans-1))/2;
			cout << ans << endl;
		}
	}
	return 0;
}

