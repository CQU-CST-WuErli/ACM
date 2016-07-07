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

struct P
{
	char name[210];
	int val;
	int ti;
	P(){}
	bool operator < (const P& rhs) const {
		if (val == rhs.val) return ti > rhs.ti;
		else return val < rhs.val;
	}
};

struct Q
{
	int ti, k;
	Q(int ti, int k):ti(ti), k(k) {}
	bool operator < (const Q& rhs) const {
		return ti < rhs.ti;
	}
	Q() {}
};
Q in[150010];

int k, m, q;
P peo[150010];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while(t--) {
        SIII(k, m, q);
        for (int i = 1; i <= k; i++) {
        	scanf("%s%d", peo[i].name, &peo[i].val);
        	peo[i].ti = i;
        }
        for (int i = 1; i <= m; i++) {
        	int ti, num;
        	SII(ti, num);
        	in[i] = Q(ti, num);
        }
        sort(in + 1, in + 1 + m);
        priority_queue<P> pq;
        vector<int> ans;
        int cnt = 1;
        for (int i = 1 ; i <= m; i++) {
        	for (;cnt <= in[i].ti; cnt++) {
				pq.push(peo[cnt]);
			}
        	int tt = 0;
        	while(pq.size() && tt < in[i].k) {
        		P x = pq.top(); pq.pop();
        	    ans.push_back(x.ti);
        	    tt++;
        	}
        }
        for (; cnt <= k; cnt++) pq.push(peo[cnt]);
        while(pq.size()) {
        	P x = pq.top(); pq.pop();
            ans.push_back(x.ti);
        }
        for (int i = 1; i <= q; i++) {
        	int qq; SI(qq);
        	printf("%s", peo[ans[qq - 1]].name);
        	if (i < q) printf(" ");
        	else printf("\n");
        }
    }
	return 0;
}