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
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n;
int ans[1100];
int cnt;
int maxd;

bool dfs(int cur, int dep) {
	if (dep == maxd) return cur == n;
	int maxv = *max_element(ans, ans + cnt);
	if (cur << (maxd - dep) < n) return false;
	if (maxv << (maxd - dep) < n) return false;
	if ((maxv + cur) << (maxd - dep - 1) < n) return false;
	for (int i = 0; i < cnt; i++) {
		ans[cnt++] = cur + ans[i];
		if (dfs(cur + ans[i], dep + 1)) return true;
		cnt--;
		ans[cnt++] = cur - ans[i];
		if (cur - ans[i] >= 0 && dfs(ans[cnt - 1], dep + 1)) return true;
		cnt--;
	}
	return false;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while(t--) {
        SI(n);
        for (maxd = 0; ; maxd++) {
        	CLR(ans);
        	ans[0] = 1;
        	cnt = 1;
        	if (dfs(1, 0)) {
        		cout << maxd << endl;
        		break;
        	}
        }
    }
	return 0;
}