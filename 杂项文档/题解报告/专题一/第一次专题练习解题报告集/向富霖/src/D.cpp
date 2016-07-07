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

// up: 0 right: 1 down: 2 left: 3
int block[55][4];
int used[55], n;
int ans[55][4];
int Hash[4][10];

struct B {
	int up, down, left, right;
	B(int up = 0, int down = 0, int left = 0, int right = 0) : 
		up(up), down(down), left(left), right(right) {}
	bool operator < (const B& rhs) const {
		if(up == rhs.up and down == rhs.down and left == rhs.left)
			return right < rhs.right;
		if(up == rhs.up and down == rhs.down)
			return left < rhs.left;
		if(up == rhs.up) return down < rhs.down;
		return up < rhs.up;
	}
};

bool dfs(int id) {
	if(id == n * n) return true;
	set<B> st;
	for(int i = 0; i < n * n; i++) {
		if(used[i]) continue;
		if(st.count( B(block[i][0], block[i][2], block[i][3], block[i][1]) ) )
			continue;
		memcpy(ans[id], block[i], sizeof ans[id]);
		if(id - n >= 0 and ans[id - n][2] != ans[id][0]) continue;
		if(id % n and ans[id - 1][1] != ans[id][3]) continue;
		for(int j = 0; j < 4; j++)
			Hash[j][ans[id][j]]--;
		used[i] = 1;
		if(dfs(id + 1)) return true;
		for(int j = 0; j < 4; j++)
			Hash[j][ans[id][j]]++;
		st.insert(B(block[i][0], block[i][2], block[i][3], block[i][1]));
		used[i] = 0;
	}
	return false;
}

int main() {
#ifdef NEKO
	freopen("Nya.txt", "r", stdin);
#endif	
	int t; scanf("%d", &t);
	while(t--) {
		int x; scanf("%d", &n);
		memset(Hash, 0, sizeof Hash);
		for(int i = 0; i < n * n; i++)
		for(int j = 0; j < 4; j++) {
			int x; scanf("%d", &x);
			block[i][j] = x;	
			Hash[j][x]++;
		}
		memset(used, 0, sizeof used);
		if(dfs(0)) puts("Possible");
		else puts("Impossible");
	}
	return 0;
}
