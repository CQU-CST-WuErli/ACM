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

const int B=700;
const int N=300010;
ll n,m,u;
vector<ll> bc[N/B+1];
ll a[N];

void update(ll l,ll r,ll v,ll p) {
	ll i=l,j=r,cnt=0;
	while (i<=j && i%B) if (a[i++]<v) cnt++;
	while (j>=i && (j+1)%B) if (a[j--]<v) cnt++;
	while (i<=j) {
		int pos=i/B;
		cnt+=lower_bound(bc[pos].begin(),bc[pos].end(),v)-bc[pos].begin();
		i+=B;
	}
	a[p]=u*cnt/(r-l+1);
	int pos=p/B;
	for (int i=0;i<bc[pos].size();i++) 
		bc[pos][i]=a[pos*B+i];
	sort(bc[pos].begin(),bc[pos].end());
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> m >> u) {
		for (int i=0;i<=n/B;i++) bc[i].clear();
		for (int i=0;i<n;i++) {
			scanf("%lld",a+i);
			bc[i/B].push_back(a[i]);
		}
		for (int i=0;i<n/B;i++) sort(bc[i].begin(),bc[i].end());
		while (m--) {
			ll l,r,v,p;
			scanf("%lld%lld%lld%lld",&l,&r,&v,&p);
			update(l-1,r-1,v,p-1);			
		}
		for (int i=0;i<n;i++) printf("%lld\n",a[i]);
	}
	return 0;
}

