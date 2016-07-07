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
const int MOD=9973;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int q, n;
char s[100010];
int sum[100100];

int inv(int a, int mod) {
	if (a == 1) return 1;
	return inv(mod % a, mod) * (mod - mod / a) % mod;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SI(q) == 1) {
    	scanf("%s", s + 1);
    	int n = strlen(s + 1);
    	sum[0] = 1;
    	for (int i = 1; i <= n; i++)
    		sum[i] = s[i] - 28;
    	for (int i = 1; i <= n; i++)
    		sum[i] = sum[i] * sum[i - 1] % MOD;
    	while(q--) {
    	    int l, r;
    	    scanf("%d %d", &l, &r);
    	    if (l > r) swap(l, r);
    	    int rev = inv(sum[l - 1], 9973);
    	    int ans = sum[r] * rev % MOD;
    	    cout << ans << endl;
    	}
    }
	return 0;
}