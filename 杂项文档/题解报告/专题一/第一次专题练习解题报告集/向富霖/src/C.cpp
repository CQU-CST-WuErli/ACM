#include <string>
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

int Hash[555], n;

struct Sta {
	int state;
	string bit; 
}ans;

void bfs() {
	queue<Sta> que;
	Sta tmp; tmp.state = 1;
	tmp.bit.push_back('1');
	if(tmp.state % n == 0) {
		ans = tmp;
		return;
	}
	Hash[tmp.state % n] = 1;
	que.push(tmp);
	while(que.size()) {
		Sta u = que.front(); que.pop();
		if(u.state % n == 0) {
			ans = u;
			return;
		}
		for(int i = 0; i <= 1; i++) {
			Sta v = u; v.state = (v.state * 10 + i) % n; 
			v.bit.push_back('0' + i);
			if(Hash[v.state]) continue;
			Hash[v.state] = 1;
			que.push(v);
		}
	}
}

int main() {
#ifdef NEKO
	freopen("Nya.txt", "r", stdin);
#endif	
	int t; scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		memset(Hash, 0, sizeof Hash);
		bfs();
		cout << ans.bit << endl;
	}
	return 0;
}
