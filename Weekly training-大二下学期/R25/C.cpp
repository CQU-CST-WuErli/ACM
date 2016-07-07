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
#define SI(a) scanf("%d", &a)
#define SII(a,b) scanf("%d%d", &a, &b)
#define SIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

ll p[30];

void init() {
	p[0] = 2;
	for (int i = 1; i < 63; i++) p[i] = p[i - 1] * 2LL;
}

ll a, b;
ll a1[100], a2[100];

void gao(ll n, ll *x) {
	n++;
	for (int i = 0; i < 63; i++) {
		x[i] += (n - n % p[i]) / 2;
		if (n % p[i] > p[i] / 2) x[i] += n % p[i] - p[i] / 2;
		if (p[i] > n) break;
	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    init();
    while(cin >> a >> b) {
    	CLR(a1); CLR(a2);
    	gao(a - 1, a1);
 	   	gao(b, a2);
    	ll ans = 0;
    	ll carry = 0;
    	// for (int i = 0; i < 5; i++) cout << a1[i] << ' ';
    	// 	cout << endl;
    	// for (int i = 0; i < 5; i++) cout << a2[i] << ' ';
    	// 	cout << endl;
    	for (int i = 0; i < 63; i++) {
    		carry = (a2[i] - a1[i] + carry) / 2;
    		ans += carry;
    		if (carry == 0) break;
    	}
    	cout << ans << endl;
    }
	return 0;
}