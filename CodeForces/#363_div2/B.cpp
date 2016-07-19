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
char a[1100][1100];
int row[1100], col[1100];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (SII(n, m) == 2) {
    	for (int i = 1; i <= n; i++)
    		scanf("%s", a[i] + 1);
    	int sum = 0;
    	for (int i= 1; i <= n; i++) {
    		for (int j=  1;j <= m; j++) {
    			if (a[i][j]== '*') sum++;
    		}
    	}
    	for (int i = 1; i <= n; i++) {
    		row[i] = 0;
    		for (int j = 1; j <= m; j++) {
    			if (a[i][j] == '*') row[i]++;
    		}
    	}
    	CLR(col);
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= m; j++) {
    			if (a[i][j] == '*')
    				col[j]++;
    		}
    	}
    	int flag = 0;
    	int sx, sy;
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= m; j++) {
    			int tmp = 0;
    			if (a[i][j] == '*') tmp = 1;
    			if (row[i] + col[j] - tmp == sum) {
    				flag = 1;
    				sx = i, sy = j;
    				break;
    			}
    		}
    		if (flag) break;
    	}
    	if (!flag) puts("NO");
    	else {
    		puts("YES");
    		cout << sx << ' ' << sy << endl;
    	}
    }
	return 0;
}