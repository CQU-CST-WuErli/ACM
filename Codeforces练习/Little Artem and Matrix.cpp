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

int n, m, q;
int a[110][110];
struct P
{
	int op, pos;
	P(int op, int pos):op(op), pos(pos){}
};
vector<P> v;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SIII(n,m,q)==3) {
	    CLR(a);
		v.clear();
		for (int i = 1; i <= q; i++) {
			int op;
			SI(op);
			if (op == 1 || op ==2) {
				int x;SI(x);
				v.push_back(P(op, x));
			}
			else {
				int r, c, val;
				SIII(r, c, val);
				for (int i = v.size() - 1; i >= 0; i--) {
					if (v[i].op == 1 && v[i].pos == r) {
						c = c % m + 1;
					}
					else if (v[i].op == 2 && v[i].pos == c) {
						r = r % n + 1;
					}
				}
				a[r][c] = val;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <=m; j++) {
				cout << a[i][j] << ' ';
			}
			cout << endl;
		}
	}
	return 0;
}