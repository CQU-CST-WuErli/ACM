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
int a[30];
int vis[30];

bool dfs(int root, int cnt, int son) {
	if (root == n + 1) return true;
	if (cnt + 1 == a[root]) {
		if (son != 1 && dfs(root + 1, 0, 0)) return true;
		return false;
	}
	int pre = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i] && cnt + a[i] < a[root] && a[i] > pre) {
			pre = a[i];
			vis[i] = 1;
			if (dfs(root, cnt + a[i], son + 1)) return true;
			vis[i] = 0;
		}
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
        for (int i = 1; i <= n; i++) SI(a[i]);
        sort(a + 1, a + 1 + n);
    	CLR(vis);
    	if (a[n] != n) puts("NO");
    	else {
    		if (dfs(1, 0, 0)) puts("YES");
    		else puts("NO");
    	}
    }
	return 0;
}