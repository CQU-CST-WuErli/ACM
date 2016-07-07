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
#include <cassert>
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

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    string s, t;
    int pos = 0;
    int neg = 0;
    queue<char> q;
	while(1) {
		cin >> s >> t;
		if (t == "=") break;
		else if (t == "+") pos++;
		else if (t == "-") neg++;
		q.push(t[0]);

	}
	SI(n);
	if (!pos && !neg) {
		printf("Possible\n");
		printf("%d = %d\n", n, n);
		return 0;
	}
	// cout << pos << ' ' << neg << endl;
	if (pos - n * neg > n || n * (pos + 1) - neg < n) {
        printf("Impossible\n");
        return 0;
    }
	else {
		puts("Possible");
		if (pos == neg) {
			printf("%d", n);
			while(q.size()) {
			    printf(" %c 1", q.front());
			    q.pop();
			}
			printf(" = %d\n", n);
		}
		else if (pos > neg) {
			int tmp = abs(pos - neg);
			queue<int> qq;
			for (int i = 1; i <= neg; i++) {
				if (tmp >= n - 1) qq.push(n), tmp -= n - 1;
				else qq.push(1 + tmp), tmp = 0;
			}
			printf("%d", n - tmp);
			while(q.size()) {
			    char c = q.front(); q.pop();
			    if (c == '-') printf(" - %d", qq.front()), qq.pop();
			    else printf(" + 1");
			}
			printf(" = %d\n", n);
		}
		else if (pos < neg) {
			printf("%d", n);
			int tmp = abs(pos - neg);
			queue<int> qq;
			for (int i = 1; i <= pos; i++) {
				if (tmp >= n - 1) qq.push(n),tmp -= n - 1;
				else qq.push(1 + tmp), tmp = 0;
			}
			while(q.size()) {
				char c = q.front(); q.pop();
				if (c == '+') printf(" + %d", qq.front()), qq.pop();
				else printf(" - 1");
			}
			printf(" = %d\n", n);
		}
	}
	return 0;
}