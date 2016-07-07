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

int n, m;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SII(n, m)==2) {
	    deque<int> l1, l2, r1, r2;
	    for (int i = 1; i <= m; i++) {
	    	if (i <= 2 * n) {
	    		if (i % 2) l1.push_back(i);
	    		else r1.push_back(i);
	    	}
	    	else {
	    		if (i % 2) l2.push_back(i);
	    		else r2.push_back(i);
	    	}
	    }
	    vector<int> ans;
	    while(m) {
	        if (l2.size()) ans.push_back(l2.front()), l2.pop_front(), m--;
	        if (l1.size()) ans.push_back(l1.front()), l1.pop_front(), m--;
	        if (r2.size()) ans.push_back(r2.front()), r2.pop_front(), m--;
	        if (r1.size()) ans.push_back(r1.front()), r1.pop_front(), m--;
	    }
	    for (int x : ans) cout << x << ' ';
	    	cout << endl;
	}
	return 0;
}