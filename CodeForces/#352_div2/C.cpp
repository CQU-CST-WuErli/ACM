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
double ax,ay,bx,by,tx,ty;

struct P {
	double x, y;
	int id;
	double dis;
	bool operator < (const P& rhs) const {
		return dis < rhs.dis;
	}
};
P p[100010];
int vis[100010];

double cal(double x, double y, double xx, double yy) {
	double ret = sqrt((x-xx)*(x-xx) + (y-yy)*(y-yy));
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(cin >> ax >> ay >> bx >> by >> tx >> ty) {
        SI(n);
        for (int i = 1; i <= n; i++) {
        	scanf("%lf%lf", &p[i].x, &p[i].y);
        	p[i].id = i;
        }

        for (int i = 1; i <= n; i++)
        	p[i].dis = cal(tx, ty, p[i].x, p[i].y);
        double ans1 = 0;
        for (int i = 1; i <= n; i++) ans1 += 2 * p[i].dis;
        int id = 0; double t1 = 1e25;
        for (int i = 1; i <= n; i++) {
        	double tmp = ans1 - p[i].dis + cal(p[i].x, p[i].y, ax, ay);
        	if (tmp < t1) {
        		id = i;
        		t1 = tmp;
        	}
        }
        double t2 = t1;
        for (int i = 1; i <= n; i++) if (i != id) {
        	double tmp = t1 - p[i].dis + cal(p[i].x, p[i].y, bx, by);
        	if (tmp < t2) {
        		t2 = tmp;
        	}
        }
        ans1 = t2;
        double ans2 = 0;
        for (int i = 1; i <= n; i++) ans2 += 2 * p[i].dis;
        id = 0; t1 = 1e25;
        for (int i = 1; i <= n; i++) {
        	double tmp = ans2 - p[i].dis + cal(p[i].x, p[i].y, bx, by);
        	if (tmp < t1) {
        		id = i;
        		t1 = tmp;
        	}
        }
        t2 = t1;
        for (int i = 1; i <= n; i++) if (i != id) {
        	double tmp = t1 - p[i].dis + cal(p[i].x, p[i].y, ax, ay);
        	if (tmp < t2) {
        		t2 = tmp;
        	}
        }
        ans2 = t2;
       	printf("%.12f\n", min(ans1, ans2));
    }
	return 0;
}