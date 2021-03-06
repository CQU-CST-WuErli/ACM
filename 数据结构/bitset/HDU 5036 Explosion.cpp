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

const int N = 1010;

int n;
bitset<N> bit[N];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    for (int T_T, kase = SI(T_T); kase <= T_T; kase++) {
    	SI(n);
    	for (int i = 1; i <= n; i++)
    		bit[i].reset();
    	for (int i = 1; i <= n; i++) {
    		int x; SI(x);
    		bit[i].set(i);
    		while (x--) {
    			int pos; SI(pos);
    			bit[i].set(pos);
    		}
    	}
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= n; j++) if (bit[j][i]) {
    			bit[j] |= bit[i];
    		}
    	}
    	double ans = 0.0;
    	for (int i = 1; i <= n; i++) {
    		double tmp = 0.0;
    		for (int j = 1; j <= n; j++) if (bit[j][i])
    			tmp += 1.0;
    		ans += 1.0 / tmp;
    	}
    	printf("Case #%d: %.5f\n", kase, ans);
    }
	return 0;
}