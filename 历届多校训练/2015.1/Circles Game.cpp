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
struct C
{
	int x, y, r;
	C(){}
	C(int x, int y, int r):x(x), y(y), r(r){}
	bool operator < (const C& rhs) const {
		return r < rhs.r;
	}
}circle[20010];

vector<int> g[20010];

int dfs(int u) {
	int ret = 0;
	for (int i = 0; i < (int)g[u].size(); i++) {
		int v = g[u][i];
		ret ^= dfs(v) + 1;
	}
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t;SI(t);
    while(t--) {
        SI(n);
        for (int i = 1; i <= n; i++) {
        	int x, y, r;
        	SIII(x, y, r);
        	circle[i] = C(x, y, r);
        }
        sort(circle + 1, circle + 1 + n);
        for (int i = 1; i <= n + 1; i++) g[i].clear();
        for (int i = 1; i <= n; i++) {
        	int flag = 0;
        	for (int j = i + 1; j <= n; j++) {
        		int r1 = (circle[i].r - circle[j].r) * (circle[i].r - circle[j].r);
        		int r2 = (circle[i].x - circle[j].x) * (circle[i].x - circle[j].x) +
        				 (circle[i].y - circle[j].y) * (circle[i].y - circle[j].y);
        		if (r1 > r2) {
        			g[j].push_back(i);
        			flag = 1;
        			break;
        		}
        	}
        	if (!flag) g[n + 1].push_back(i);
        }
        int ans = dfs(n + 1);
        puts(ans ? "Alice" : "Bob");
    }
	return 0;
}