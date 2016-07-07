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

char s[maxn], temp[maxn * 3];
int len[maxn * 3]; ll mod; 

void Init(){
	int slen = strlen(s);
	temp[0] = '@';
	for(int i = 1; i <= 2 * slen; i += 2) {
		temp[i] = '#';
		temp[i + 1] = s[i / 2];
	}
	temp[2 * slen + 1] = '#';
	temp[2 * slen + 2] = '\0';	
}

int Manacher(){
	int ma = 0, ans = 0, po = 0, tlen = strlen(temp);
	for(int i = 1; i < tlen; i++){
		if(ma > i) len[i] = min(ma - i, len[2 * po - i]);
		else len[i] = 1;
		while(temp[i - len[i]] == temp[i + len[i]]) len[i]++;
		if(len[i] + i > ma){
			ma = len[i] + i;
			po = i;	
		}
		if(i % 2 == 0) ans = max(ans, len[i] - 1);
	}
	return ans;
}

ll quickPow(ll x, ll y) {
	ll res = 1;
	while(y) {
		if(y & 1) res = res * x % mod;  
		y = y >> 1LL;
		x = x * x % mod;
	}
	return res;
}

int sum[maxn * 3];
int ch[maxn * 31][2];

class Aho_Corasick {
private:
	int sz;	
public:	
	Aho_Corasick() { clear(); }
	void clear() {
		memset(ch[0], 0, sizeof ch[0]);	sz = 1;	
	}
	int idx(char c) { return c - '0'; }
	void insert(char* ss) {
		int n = strlen(ss), u = 0;
		for(int i = 0; i < n; i++) {
			int c = idx(ss[i]);	
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

int main() {
#ifdef NEKO
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w+", stdout);
#endif
	int t; scanf("%d", &t);
	while(t--) {	
		scanf("%s", s);
		ll k = strlen(s);
		Init(); ll Mz = Manacher();
		mod = Mz / 3 * 5 + 1;
		ll jd = quickPow(Mz, k * k * k) + Mz * 4 / 5;
		sum[0] = 0;
		for(int i = 2; i <= 2 * k; i += 2)
			sum[i >> 1] = sum[i / 2 - 1] ^ (len[i] - 1);

		ac.clear(); char p[55];
		for(int i = 0; i <= k; i++) {
			for(int j = 30; j >= 0; j--)
				p[30 - j] = ((1 << j) & sum[i]) ? '1' : '0';
			p[31] = '\0';
			ac.insert(p);
		}

		int fjd = 0;
		for(int i = 0; i <= k; i++) {
			for(int j = 30; j >= 0; j--)
				p[30 - j] = ((1 << j) & sum[i]) ? '1' : '0';
			p[31] = '\0';
			fjd = max(fjd, ac.find(p));
		}
		if(jd > fjd) puts("liujc");
		else puts("luoxinchen");
	}
	return 0;
}
