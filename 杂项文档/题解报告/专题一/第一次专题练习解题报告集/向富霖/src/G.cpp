#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, c, m;
int a[25], Hash[5005];

struct Sta {
	int state;
	string password;
}ans;

char encode(int x) {
	if(x >= 10) return 'A' + x - 10;
	return '0' + x;
}

bool bfs() {
	queue<Sta> que;
	memset(Hash, 0, sizeof Hash);
	for(int i = 1; i <= m; i++) {
		if(!a[i]) continue;
		Sta u; u.state = a[i] % n;
		u.password.push_back(encode(a[i]));
		if(!u.state) { ans = u; return true; }
		if(Hash[u.state]) continue;
		Hash[u.state] = 1;
		que.push(u);
	}

	while(que.size()) {
		Sta u = que.front(); que.pop();
		if(u.password.size() > 500) continue;
		for(int i = 1; i <= m; i++) {
			Sta v = u;
			v.password.push_back(encode(a[i]));
			v.state = (v.state * c + a[i]) % n;
			if(!v.state) {
				ans = v;
				return true;
			}
			if(!Hash[v.state]) {
				Hash[v.state] = 1;
				que.push(v);
			}
		}
	}
	return false;
}

int main() {
#ifdef NEKO
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w+", stdout);
#endif	
	int t; scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d", &n, &c, &m);
		for(int i = 1; i <= m; i++) {
			char s[5]; scanf("%s", s);
			a[i] = isdigit(s[0]) ? s[0] - '0' : s[0] - 'A' + 10;
		}
		sort(a + 1, a + 1 + m);
		if(!n) {
			if(!a[1]) puts("0");
			else puts("BOMB!!!");
		}
		else {
			if(bfs()) cout << ans.password << endl;
			else puts("BOMB!!!");
		}
	}
	return 0;
}
