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
#define rep(flag,start,end) for(int flag = start; flag <= end; flag++)
#define Rep(flag,start,end) for(int flag = start; flag >= end; flag--)
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

double n,l;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(cin >> n >> l) {
		double tmp = n - l;
		double tt = n * n * n / l / 2 - 2 * n * n + l * n;
		double delta = tmp * tmp - 4 * tt;
		if (delta < 0) {
			puts("Oh, my god!");
			continue;
		}
		double x1 = (-tmp + sqrt(delta)) / 2;
		double x2 = (-tmp - sqrt(delta)) / 2;
		if (x1 >= 0 && x1 <= n) printf("%.2f\n", x1);
		else if (x2 >= 0 && x2 <= n) printf("%.2f\n", x2);
		else puts("Oh, my god!");
	}
	return 0;
}