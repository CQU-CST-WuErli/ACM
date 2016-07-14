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

int n, k;
int a[101000], b[101000];

struct P
{
	int id;
	int num;
	int rest;
	bool operator < (const P& rhs) const {
		if (num == rhs.num) return a[id] - rest > a[rhs.id] - rhs.rest;
		else return num > rhs.num;
	}
};
P p[100010];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SII(n, k) == 2) {
        for (int i = 1; i <= n; i++)
        	SI(a[i]);
        for (int j = 1; j <= n; j++)
        	SI(b[j]);
        for (int i = 1; i <= n; i++) {
        	p[i].id = i;
        	p[i].num = b[i] / a[i];
        	p[i].rest = b[i] % a[i];
        }
        priority_queue<P> q;
        for (int i = 1; i <= n; i++)
        	q.push(p[i]);
	        // while(q.size()) {
	        //     P now = q.top(); q.pop();
	        //     cout << now.num << ' ' << now.rest << endl;
	        // }
        int ans = 0;
        P now;
        while(k > 0) {
            now = q.top(); q.pop();
			int tmp = min(k, a[now.id] - now.rest);
			k -= tmp;
			now.rest += tmp;
			if (now.rest >= a[now.id]) {
				now.num++;
				now.rest %= a[now.id];
			}
            q.push(now);
        }
        ans = q.top().num;
        cout << ans << endl;
    }
	return 0;
}