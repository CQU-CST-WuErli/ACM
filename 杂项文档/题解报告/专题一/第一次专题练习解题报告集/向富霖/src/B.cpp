#include <set>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 15;
const int maxm = 5e6 + 15;
const int inf = 0x3f3f3f3f;
typedef long long ll;

class KMP {
public:
	int nxt[maxm];
	void getNext(char *p) {
		int plen = strlen(p);
		nxt[0] = -1;
		int j = 0, k = -1;
		while(j < plen) {
			while(k != -1 && p[j] != p[k]) k = nxt[k];
			nxt[++j] = ++k;
		}
	}

	void search(char *s, char *p) {
		int plen = strlen(p);
		int slen = strlen(s);
		int i = 0, j = 0;
		while(i < slen) {
			while(j != -1 && p[j] != s[i]) j = nxt[j];
			i++, j++;
 			if(j == plen) {
 				s[i - 1] = '.';
 				j = 0;	
 			}
		}
	}
}kmp;

char s[maxm], p[maxm], b[maxm];
char ans[maxm];

int main() {
#ifdef NEKO
	freopen("Nya.txt", "r", stdin);
#endif	
	int t; scanf("%d", &t);
	while(t--) {
		scanf("%s %s %s", s, p, b);
		kmp.getNext(p);	
		kmp.search(s, p);
		int sz = strlen(s);
		int sb = strlen(b);
		int sp = strlen(p);
		int j = 0;
		for(int i = sz - 1; ~i; i--) {
			if(s[i] != '.') ans[j++] = s[i];
			else {
				for(int k = sb - 1; ~k; k--)
					ans[j++] = b[k];
				i -= sp - 1;
			}
		}
		for(int i = j - 1; ~i; i--)
			putchar(ans[i]);
		putchar('\n');
	}
	return 0;
}
