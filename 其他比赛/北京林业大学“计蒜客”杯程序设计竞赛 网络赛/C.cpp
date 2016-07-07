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

int n;
int value[330];
int l[330], r[330];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SI(n)==1) {
		CLR(value);
		CLR(l),CLR(r);
		int ans = 0;
		for (int i = 1; i <= n; i++) SI(value[i]);
		l[1] = 1;
		for (int i = 2; i <= n; i++) {
			if (value[i] > value[i - 1]) l[i] = l[i - 1] + 1;
			else if (value[i] == value[i - 1]) l[i] = l[i - 1];
			else l[i] = 1;
		}
		r[n] = 1;
		for (int i = n - 1; i >= 1; i--) {
			if (value[i] > value[i + 1]) r[i] = r[i + 1] + 1;
			else if (value[i] == value[i + 1]) r[i] = r[i + 1];
			else r[i] = 1;
		}
		// for (int i = 1; i <= n; i++) cout << l[i] << ' ';
		// cout << endl;
		// for (int i = 1; i <= n; i++) cout << r[i] << ' ';
		// cout << endl;
		for (int i = 1; i<= n; i++) ans += max(l[i], r[i]);
		cout << ans << endl;
	}
	return 0;
}