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

int n;
int a[110];
int zero[110],one[110];

int main(){
#ifdef LOCAL
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n) {
		for (int i=1;i<=n;i++) cin >> a[i];
		CLR(zero);CLR(one);
		int ans=0;
		for (int i=1;i<=n;i++) {
			if (a[i]) {
				ans++;
				zero[i]=zero[i-1];
				one[i]=one[i-1]+1;
			}
			else if (!a[i]) {
				zero[i]=zero[i-1]+1;
				one[i]=one[i-1];
			}
		}
		if (n==1) {
			cout  << 1-a[1] << endl;
			continue;
		}
		else if (ans==n) {
			cout << n-1 << endl;
			continue;
		}
		int tt=ans;
		for (int i=1;i<=n;i++) {
			for (int j=i;j<=n;j++) {
				int tmp_zero,tmp_one;
				tmp_zero=zero[j]-zero[i-1];
				tmp_one=one[j]-one[i-1];
				ans=max(ans,tt-tmp_one+tmp_zero);
			}
		}
		cout << ans << endl;
	}
	return 0;
}

