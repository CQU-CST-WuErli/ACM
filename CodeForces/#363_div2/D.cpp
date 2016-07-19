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
int p[200020];
int par[200020];
vector<int> g[200020];
int find(int x) {
	if (x == par[x]) return par[x];
	else return par[x] = find(par[x]);
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (SI(n) == 1) {
    	for (int i = 1; i <= n; i++)
    		par[i] = i;
    	for (int i = 1; i <= n; i++) {
    		SI(p[i]);
    	}
    	int ans = 0;
    	int root = 0;
    	for (int i = 1; i <= n; i++) {
    		if (p[i] == i) root = i, ans++;
    		else {
    			int fa = find(i), fb = find(p[i]);
    			if (fa == fb) p[i] = i, ans++;
    			else par[fa] = par[fb];
    		}
    	}
    	if (root == 0) {
    		for (int i = 1; i <= n; i++)
    			if (p[i] == i) root = i, ans++;
    	}
    	cout << ans - 1 << endl;
    	for (int i = 1; i <= n; i++) {
    		if (p[i] == i) p[i] = root;
    		cout << p[i] << ' ';
    	}
    	cout << endl;
    }
	return 0;
}