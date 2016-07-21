//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
//#pragma comment(linker, "/STACK:102400000,102400000")
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
#include <bitset>
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

int n, m;
int a[110];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int T; SI(T);
    while (T--) {
    	SII(n, m);
    	OFF(a);
    	for (int i = 1; i <= m; i++) {
    		int x, y; SII(x, y);
    		a[x] = y;
    	}
    	if (a[1] == -1) a[1] = 100;
    	if (a[2] == -1) a[2] = a[1];
    	int last = 0;
    	for (int i = n; i >= 3; i--) {
    		if (a[i] == -1) a[i] = last;
    		else last = a[i];
    	}
    	int x = 0, y = 0;
    	x = a[1] + a[2];
    	for (int i = 1; i <= n; i++)
    		y += a[i];
    	int gcd = __gcd(x, y);
    	printf("%d/%d\n", x / gcd, y / gcd);
    }
	return 0;
}