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
char s[100010];
char p[5505];
int ans[1000010];

int check(int pos) {
	for (int i = 1; i <= m; i++) {
		if (s[pos + i - 1] == p[i]) {
			continue;
		}
		else {
			if (s[pos + i - 1] == p[i + 1] && s[pos + i] == p[i]) i++;
			else return 0;
		}
	}
	return 1;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int T; SI(T);
    while (T--) {
    	SII(n, m);
    	scanf("%s%s", s + 1, p + 1);
    	CLR(ans);
    	for (int i = 1; i <= n - m + 1; i++) {
    		ans[i] = check(i);
    	}
    	for (int i = 1; i <= n; i++) {
    		printf("%d", ans[i]);
    	}
    	puts("");
    }
	return 0;
}