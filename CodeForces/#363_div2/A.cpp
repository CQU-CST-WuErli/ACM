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
int a[200020];
int dir[200020];
char s[200020];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (SI(n) == 1) {
    	scanf("%s", s + 1);
    	for (int i = 1; i <= n; i++)
    		SI(a[i]);
    	int len =strlen(s + 1);
    	int ans = INF_INT;
    	for (int i = 1; i <= n; i++) {
    		if (s[i] == 'L') {
    			if (i > 1 && s[i - 1] == 'R') {
    				ans = min(ans, (a[i] - a[i - 1]) / 2);
    			}
    		}
    		else if (s[i] == 'R') {
    			if (i < n && s[i + 1] == 'L') {
    				ans = min(ans, (a[i + 1] - a[i]) / 2);
    			}
    		}
    	}
    	if (ans >= INF_INT) cout << - 1;
    	else cout << ans << endl;
    }
	return 0;
}