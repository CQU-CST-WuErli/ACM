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

char a[100010 << 1];
char s[100010 << 1];
int p[100010 << 1];
int sum[100010 << 1];

int manacher() {
	int l = 0;
	s[l++] = '@';
	s[l++] = '#';
	int len = strlen(a);
	for (int i = 0; i < len; i++) {
		s[l++] = a[i];
		s[l++] = '#';
	}
	s[l] = 0;
	int mx = 0, id = 0;
	int ret = 0;
	for (int i = 0; i < l; i++) {
		if (mx > i) p[i] = min(p[2 * id - i], mx - i);
		else p[i] = 1;
		while (s[p[i] + i] == s[i - p[i]]) p[i]++;
		if (p[i] + i > mx) mx = p[i] + i, id = i;
		ret = max(ret, p[i]);
	}
	int cnt = 0;
	for (int i = 0; i < l; i++) if (s[i] != '@' && s[i] != '#') sum[cnt++] = p[i] - 1;
	return ret - 1;
}

ll ksm(ll a, ll x, ll mod) {
	if (x == 0) return 1LL % mod;
	ll ret = ksm(a, x / 2, mod);
	ret *= ret;
	ret %= mod;
	if (x & 1) ret = ret * a % mod;
	return ret % mod;
}

int cal(ll MZ) {
	ll mod = (MZ / 3 * 5) + 1;
	int ret = MZ * 4 / 5;
	ll k = (ll)strlen(a);
	k = k * k * k;
	ret += ksm(MZ, k, mod);
	return ret;
}

struct XorTrie
{
	const static int maxn=5e6+10;
    const static int maxv=2;
    int cnt, root;
    int nxt[maxn][maxv];
    void init() {
    	OFF(nxt);
    	cnt = 0;
    	root = newNode();
    }
    int newNode() {
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

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int t; SI(t);
	while(t--) {
		scanf("%s", a);
		CLR(sum);CLR(p);
		int MZ = manacher();
		int len = strlen(a);
		int JD = 0;
		JD = cal((ll)MZ);
		for (int i = 1; i < len; i++) sum[i] ^= sum[i - 1];
		trie.init();
		trie.insert(0);
		int FJD = 0;
		for (int i = 0; i < len; i++) {
			FJD = max(FJD, trie.find(sum[i]));
			trie.insert(sum[i]);
		}
		if (JD > FJD) puts("liujc");
		else puts("luoxinchen");
	}
	return 0;
}