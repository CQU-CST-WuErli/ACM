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

ll n, m;
int col[100010], row[100010];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (cin >> n >> m) {
    	CLR(row); CLR(col);
    	ll sum = n * n;
    	int cnt = 0;
    	int r = n, c = n;
    	for (int i = 1; i <= m; i++) {
    		int x, y;
    		SII(x, y);
    		if (!row[x] && !col[y]) {
    			sum -= (r + c - 1);
    			r--; c--;
    		}
    		else if (row[x] && !col[y]) {
    			sum -= c;
    			r--;
    		}
    		else if (!row[x] && col[y]) {
    			sum -= r;
    			c--;
    		}
    		row[x] = col[y] = 1;
    		printf("%I64d\n", sum);
    	}
    }
	return 0;
}