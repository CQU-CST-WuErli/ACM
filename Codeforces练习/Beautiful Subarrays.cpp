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

ll k;
int n;

struct Trie
{
	int nxt[20000000][2];
	int size[20000000];
	int cnt;
	void init() {
		cnt = 1;
		CLR(size);
		CLR(nxt);
	}
	void insert(int x) {
		int v = 0;
		for (int i = 30; i >= 0; i--) {
			int tmp = (x >> i) & 1;
			if (!nxt[v][tmp])
				nxt[v][tmp] = cnt++;
			size[nxt[v][tmp]]++;
			v = nxt[v][tmp];
		}
	}
	ll query(ll x) {
		ll ret = 0;
		int v = 0;
		ll tmp = 0;
		for (int i = 30; i >= 0; i--) {
			int tt = (x >> i) & 1;
			if ((tmp | (1 << i)) >= k) {
				ret += size[nxt[v][tt ^ 1]];
				v = nxt[v][tt];
				if (!v) break;
			}
			else {
				tmp |= (1 << i);
				v = nxt[v][tt ^ 1];
				if (!v) break;
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
    while(cin >> n >> k) {
        ll sum = 0;
        ll ans = 0;
        trie.init();
        trie.insert(0);
        for (int i = 1; i <= n; i++) {
        	ll x;
        	scanf("%I64d", &x);
        	sum ^= x;
        	ans += trie.query(sum);
        	trie.insert(sum);
        }
        cout << ans << endl;
    }
	return 0;
}