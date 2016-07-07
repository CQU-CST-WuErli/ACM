//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for(int flag=start;flag>=end;flag--)
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n;
int isprime[2000010];
ll prime[2000100];
int cnt;

void getprime() {
	CLR(isprime);
	for (ll i=2;i<=100001;i++) if (!isprime[i]) {
		for (ll j=i*i;j<=100001;j+=i) isprime[j]=1;
	}
	cnt=0;
	for (int i=2;i<=100001;i++) if (!isprime[i]) prime[cnt++]=i;
	// for (int i=0;i<10;i++) cout << prime[i] << endl;
}

set<ll> st;
void init() {
	for (int i=0;i<cnt;i++) st.insert(prime[i]*prime[i]);
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("2.in","r",stdin);
    freopen("test.out","w",stdout);
#endif
    getprime();
    init();
    int t;SI(t);
    for (int kase=1;kase<=t;kase++) {
        int n;cin >> n;
    	ll x;
        printf("Case #%d:\n", kase);
    	for (int i=1;i<=n;i++) {
    		cin >> x;
    		if (!st.count(x)) puts("NO");
    		else puts("YES");
    	}
    }
	return 0;
}