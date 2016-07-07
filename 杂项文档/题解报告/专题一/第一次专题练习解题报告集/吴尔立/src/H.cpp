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
char s[10][10];
int len[10];
int top[10];
char ch[4] = {'A', 'G', 'T', 'C'};
int maxd;

int h() {
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		ret = max(ret, len[i] - top[i]);
	}
	return ret;
}

bool check() {
	for (int i = 1; i <= n; i++) if (top[i] < len[i]) return false;
	return true;
}
bool dfs(int cnt) {
	if (cnt + h() > maxd) return false;
	if (check()) return true;
	int temp[10];
	for (int i = 0; i < 4; i++) {
		memcpy(temp, top, sizeof top);
		int flag = 0;
		for (int j = 1; j <= n; j++) {
			if (s[j][top[j]] == ch[i]) {
				flag = 1;
				top[j]++;
			}
		}
		if (flag) {
			if (dfs(cnt + 1)) return true;
			memcpy(top, temp, sizeof temp);
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
	    for (int i = 1; i <= n; i++) {
	    	scanf("%s", s[i]);
	    	len[i] = strlen(s[i]);
	    }
	    for (maxd = 1; ; maxd++) {
	    	CLR(top);
	    	if (dfs(0)) {
	    		cout << maxd << endl;
	    		break;
	    	}
	    }
	}
	return 0;
}