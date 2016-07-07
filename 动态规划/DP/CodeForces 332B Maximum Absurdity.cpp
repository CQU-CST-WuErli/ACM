//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
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
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for(int flag=start;flag>=end;flag--)
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

const int N=2e5+10;
int n,k;
ll a[N],sum[N];
ll Max[N];
int Max_id[N];


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SII(n,k)==2) {
		rep(i,1,n) SI(a[i]);
		ll tmp=0LL;
		rep(i,1,k) tmp+=a[i];
		sum[1]=tmp;
		rep(i,2,n-k+1) {
			tmp=tmp-a[i-1]+a[i+k-1];
			sum[i]=tmp;
		}

		int m=n-k+1;
		// lookln(m);
		rep(i,1,m) Max[i]=sum[i],Max_id[i]=i;
		Rep(i,m-1,1) {
			if (Max[i+1]>Max[i]) {
				Max[i]=Max[i+1];
				Max_id[i]=Max_id[i+1];
				// BUG;
			}
			else if (Max[i+1]==Max[i]) {
				Max[i]=Max[i+1];
				Max_id[i]=i;
				// BUG;
			}
			else {
				Max[i]=sum[i];
				Max_id[i]=i;
			}
		}
		// rep(i,1,m) cout << Max_id[i] << ' ' << Max[i] << endl;
		ll ans=0;
		int L,R;
		rep(i,1,n-2*k+1) {
			tmp=sum[i]+Max[i+k];
			if (tmp>ans) {
				ans=tmp;
				L=i;R=Max_id[i+k];
			}
		}
		printf("%d %d\n",L,R);
	}
	return 0;
}