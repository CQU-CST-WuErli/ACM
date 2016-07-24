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

int n;
int a[1000010];
int b[1000010];
int c[1000010];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (SI(n) == 1) {
    	for (int i = 1; i <= n; i++) {
    		int x; SI(x);
    		a[x] = i;
    	}
		for (int i = 1; i <= n; i++) {
			int x; SI(x);
			b[i] = a[x];
		}
		reverse(b + 1, b + 1 + n);
		c[1] = b[1];
		int len = 1;
		for (int i = 2; i <= n; i++) {
			if (b[i] > c[len]) {
				c[++len] = b[i];
			}
			else {
				int pos = lower_bound(c + 1, c + 1 + len, b[i]) - c;
				c[pos] = b[i];
			}
		}
		printf("%d\n", len);
    }
	return 0;
}