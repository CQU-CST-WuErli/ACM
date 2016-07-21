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
char mp[1100][1100];
int sumx[1010], sumy[1010];
int posx[1010], posy[1010];
ll ans;

ll cal(int n, int m, int pos[]) {
    ll sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; i++) {
        if (pos[i] > pos[i - 1]) sum1 += pos[i] - 1;
        else if (pos[i] == 0) sum1 = 0;
        else sum1 = pos[i] - 1;
        ans += 1LL * sum1 * 4 * (m - pos[i]);
        if (pos[i] > pos[i - 1]) sum2 = 0;
        if (pos[i] != 0) ans += 1LL * sum2 * 4 * (pos[i] - 1);
        if (pos[i - 1] > pos[i]) sum2 += m - pos[i];
        else if (pos[i] == m) sum2 = 0;
        else sum2 = m - pos[i];
    }
}


int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while (t--) {
    	SII(n, m);
        ll tot = 0;
        CLR(sumx); CLR(sumy);
        CLR(posx); CLR(posy);
    	for (int i = 1; i <= n; i++) {
    		scanf("%s", mp[i] + 1);
    		for (int j = 1; j <= m; j++) {
                if (mp[i][j] == 'G') posx[i] = j, posy[j] = i;
                else if (mp[i][j] == '#') sumx[i]++, sumy[j]++, tot++;
    		}
    	}
        ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ans += 1LL * abs(j - i) * sumx[i] * sumx[j];
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                ans += 1LL * abs(j - i) * sumy[i] * sumy[j];
            }
        }
        cal(n, m, posx);
        cal(m, n, posy);
        tot *= tot;
        double d = 1.0 * ans / tot;
        printf("%.4f\n", d);
    }
	return 0;
}