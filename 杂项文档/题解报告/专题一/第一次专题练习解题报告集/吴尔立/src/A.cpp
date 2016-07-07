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

int n, m;
int a[1000100];
int b[1000100];


struct Trie
{
	const static int maxn=5e6+10;
    const static int maxv=2;
    int cnt, root;
    int nxt[maxn][maxv];
    void init() {
    	cnt = 0;
    	root = newNode();
    }
    int newNode() {
    	nxt[cnt][0] = nxt[cnt][1] = -1;
    	cnt++;
    	return cnt - 1;
    }
    void insert(int x) {
    	int now = root;
    	for (int i = 30; i >= 0; i--) {
    		int id = (x >> i) & 1;
    		if (nxt[now][id] == -1) nxt[now][id] = newNode();
    		now = nxt[now][id];
    	}
    }
    int find(int x) {
    	int now = root;
    	int ret = 0;
    	for (int i = 30; i >= 0; i--) {
    		int id = (x >> i) & 1;
    		int tmp = id;
    		if (nxt[now][id ^ 1] == -1) {
    			now = nxt[now][id];
    		}
    		else {
    			ret |= (1 << i);
    			now = nxt[now][id ^ 1];
    		}
    	}
    	return ret;
    }
}trie;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int t; SI(t);
	while(t--) {
		SII(n, m);
		for (int i = 1; i <= n; i++) SI(a[i]);
		for (int i = 1; i <= m; i++) SI(b[i]);
		trie.init();
		for (int i = 1; i <= n; i++) trie.insert(a[i]);
		int ans = 0;
		for (int i = 1; i <= m; i++) ans = max(ans, trie.find(b[i]));
		cout << ans << endl;
	}
	return 0;
}