#include <set>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 15;
const int maxm = 1e6 + 15;
const int inf = 0x3f3f3f3f;
typedef long long ll;

int ch[maxn * 31][2];

class Aho_Corasick {
private:
	int sz;	
public:	
	Aho_Corasick() { clear(); }
	void clear() {
		memset(ch[0], 0, sizeof ch[0]);	
		sz = 1;	
	}
	int idx(char c) { return c - '0'; }
	void insert(char* s) {
		int n = strlen(s), u = 0;
		for(int i = 0; i < n; i++) {
			int c = idx(s[i]);	
			if(!ch[u][c]) {
				memset(ch[sz], 0, sizeof ch[sz]);	
				ch[u][c] = sz++;
			}
			u = ch[u][c];
		}
	}
	int find(char* p) {
		int n = strlen(p), u = 0;	
		int j = 30, res = 0;
		for(int i = 0; i < n; i++, j--) {
			int c = idx(p[i]);
			if(c) {
				if(ch[u][0]) {
					res += 1 << j;
					u = ch[u][0];
				} else if(ch[u][1])
					u = ch[u][1];
			}
			if(!c) {
				if(ch[u][1]) {
					res += 1 << j;
					u = ch[u][1];
				} else if(ch[u][0])
					u = ch[u][0];	
			}
		}
		return res;
	}
}ac;

char s[1005];

int main() {
#ifdef NEKO
	freopen("Nya.txt", "r", stdin);
#endif	
	int t; scanf("%d", &t);
	while(t--) {
		int n, m; scanf("%d %d", &n, &m);
		ac.clear();
		for(int i = 1; i <= n; i++) {
			int x; scanf("%d", &x);
			for (int j = 30; j >= 0; j--)
				s[30 - j] = ((1 << j) & x) ? '1' : '0';
			s[31] = '\0';
			ac.insert(s);
		}
		int ans = 0;
		for(int i = 1; i <= m; i++) {
			int x; scanf("%d", &x);
			for (int j = 30; j >= 0; j--)
				s[30 - j] = ((1 << j) & x) ? '1' : '0';
			s[31] = '\0';
			ans = max(ans, ac.find(s));
		}	
		printf("%d\n", ans);
	}
	return 0;
}
