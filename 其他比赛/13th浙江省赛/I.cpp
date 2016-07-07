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

char a[110][110];
int h, w;

int dir[5][2] = {1,-1,1,0,1,1,2,-1,2,1};

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int t;SI(t);
	while(t--) {
	    SII(h, w);
	    for (int i = 1; i <= h; i++) {
	    	for (int j = 1; j <= w; j++) cin >> a[i][j];
	    }
		int ans = 0;
		for (int i = -1; i < h; i++) {
			for (int j = 0; j <= w + 1; j++) {
				int flag = 0;
				if (a[i][j] == 'O') flag = 1;
				for (int k = 0; k < 5; k++) {
					int tx = i + dir[k][0], ty = j + dir[k][1];
					if (tx < 1 || tx > h || ty < 1 || ty > w) continue;
					if (k == 0 && a[tx][ty] == '/') a[tx][ty] = '.',flag = 1;
					else if (k == 1 && a[tx][ty] == '|') a[tx][ty] = '.',flag = 1;
					else if (k == 2 && a[tx][ty] == '\\') a[tx][ty] = '.',flag = 1;
					else if (k == 3 && a[tx][ty] == '(') a[tx][ty] = '.',flag = 1;
					else if (k == 4 && a[tx][ty] == ')') a[tx][ty] = '.',flag = 1;
				}
				if (flag) ans++;
			}
		}
		for (int i = 1; i <= w; i++) if (a[h][i] !='.') ans++;
		cout << ans << endl;
	}
	return 0;
}