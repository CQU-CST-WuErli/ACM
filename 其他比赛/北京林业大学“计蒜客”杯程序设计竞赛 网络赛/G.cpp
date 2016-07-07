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

int n,m;

int nxt[1000];

void getnxt(string &t) {
	nxt[0] = -1;
	int i = 0, j = -1;
	while(i < t.size()) {
	    if (j == -1 || t[i] == t[j]) nxt[++i] = ++j;
	    else j = nxt[j];
	}
}

int kmp(string& s, string& t) {
	getnxt(t);
	int i = 0, j = 0;
	while(i < s.size()) {
	    if (j == -1 || s[i] == t[j]) ++i, ++j;
	    else j = nxt[j];
	    if (j == t.size()) return 1;
	}
	return 0;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SII(n,m)==2) {
	    string s;
	    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
	    	char c;cin >> c;
	    	if (c >= 'A' && c <= 'Z') c += 32;
	    	s += c;
	    }
	    // cout << s << endl;
	    string t;
	    cin >> t;
	    for (int i = 0; i < t.size(); i++) if (t[i] >= 'A' && t[i] <= 'Z') t[i] += 32;
	    // cout << t << endl;
	    int ans = kmp(s,t);
	    puts(ans?"YES":"NO");
	}
	return 0;
}