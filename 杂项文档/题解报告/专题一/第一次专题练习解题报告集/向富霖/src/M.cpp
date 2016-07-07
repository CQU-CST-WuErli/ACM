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

char s[maxn];

int main() {
#ifdef NEKO
	freopen("Nya.txt", "r", stdin);
#endif	
	int t, kase = 1; scanf("%d", &t);
	while(t--) {
		scanf("%s", s);
		int sz = strlen(s);
		char ch;
		for(int i = 0; i < sz; i++) {
			if(isdigit(s[i])) continue;
			else { ch = s[i + 1]; break; }
		}
		double ans;
		switch(ch) {
			case 'B':
				ans = 0;
				break;
			case 'K':
				ans = 2.34;
				break;
			case 'M':
				ans = 4.63;
				break;
			case 'G':
				ans = 6.87;
				break;
			case 'T':
				ans = 9.05;
				break;
			case 'P':
				ans = 11.18;
				break;				
			case 'E':
				ans = 13.26;
				break;
			case 'Z':
				ans = 15.30;
				break;		
			case 'Y':
				ans = 17.28;
				break;
		}
		printf("Case #%d: %.2f%%\n", kase++, ans);
	}
	return 0;
}
