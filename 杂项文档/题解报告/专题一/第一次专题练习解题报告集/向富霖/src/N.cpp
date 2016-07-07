#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define lson id << 1
#define rson id << 1 | 1
using namespace std;
typedef pair<int, int> P;
const int  inf = 0x3f3f3f3f;
const int maxn = 1e4 + 15;
const int  mod = 10007;

int ch[maxn][27];
int val[maxn], fail[maxn], last[maxn];

class Aho_Corasick {
public:	
	int sz;
	Aho_Corasick() { clear(); }
	
	void clear() {
		memset(val, false, sizeof val);
		memset(ch[0], 0, sizeof ch[0]);	
		sz = 1;
	}
	
	int idx(char c) { return c - 'A'; }
	int size() { return sz; }
	
	void insert(char* s, int v) {
		int n = strlen(s), u = 0;
		for(int i = 0; i < n; i++) {
			int c = idx(s[i]);	
			if(!ch[u][c]) {
				memset(ch[sz], 0, sizeof ch[sz]);	
				val[sz] = false;
				ch[u][c] = sz++;
			}
			u = ch[u][c];
		}
		val[u] = true;
	}
	
	void getFail() {
		queue<int> que; fail[0] = 0;		
		for(int c = 0; c < 26; c++) {
			int u = ch[0][c];
			if(u) { fail[u] = 0; que.push(u); last[u] = 0; }
		}
		
		while(que.size()) {
			int u = que.front(); que.pop();
			if(val[fail[u]]) val[u] = true;	
			for(int c = 0; c < 26; c++) {
				int v = ch[u][c];	
				if(!v) { ch[u][c] = ch[fail[u]][c]; continue; }
				que.push(v); fail[v] = ch[fail[u]][c];
				last[v] = val[fail[v]] ? fail[v] : last[fail[v]];
			}
		}			
	}
	
}ac;

int quickPow(int m) {
	int b = 26, res = 1;
	while(m) {
		if(m & 1) res = res * b % mod;
		b = b * b % mod;
		m >>= 1;
	}
	return res;
}

int dp[105][maxn];

int main(){
#ifdef NEKO
	freopen("Nya.txt", "r", stdin);
#endif
	int n, m; char p[1000];
	int t; scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		int ans = quickPow(m) % mod;
		ac.clear();
		for(int i = 1; i <= n; i++) {
			scanf("%s", p);
			ac.insert(p, i);
		}
		ac.getFail();
		dp[0][0] = 1;
		for(int i = 1; i < ac.sz; i++) dp[0][i] = 0;
		
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < ac.sz; j++)
				dp[i + 1][j] = 0;
			
			for(int j = 0; j < ac.sz; j++)
			for(int k = 0; k < 26; k++) {
				int v = ch[j][k];	
				if(val[v]) continue;
				dp[i + 1][v] = (dp[i + 1][v] + dp[i][j]) % mod;
			}
		}
		
		for(int i = 0; i < ac.sz; i++)
			ans = (ans - dp[m][i] % mod + mod) % mod;
		printf("%d\n", ans);
	}
	return 0;
}

