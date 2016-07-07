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

char maze[55][55], sx, sy, tx, ty;

int vis[10][10][55][55];

// left 0 up 1 right 2 down 3 +1 right turn +3 left turn
// green 0 black 1 red 2 
struct Sta {
	int dir, color, x, y;
	Sta(int dir = 0, int color = 0, int x = 0, int y = 0):dir(dir), color(color), x(x), y(y) {}
};

int dir[4][2] = { 0, -1, -1, 0, 0, 1, 1, 0};

int main() {
#ifdef NEKO
	freopen("Nya.txt", "r", stdin);
#endif	
	int t; scanf("%d", &t);
	while(t--) {
		int n, m; scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i++) {
			scanf("%s", &maze[i][1]);
			for(int j = 1; j <= m; j++) {
				if(maze[i][j] == 'S')
					sx = i, sy = j;
				else if(maze[i][j] == 'T')
					tx = i, ty = j;
			}
		}
		memset(vis, -1, sizeof vis);
		vis[1][0][sx][sy] = 0;
		queue<Sta> que; que.push(Sta(1, 0, sx, sy));
		while(que.size()) {
			Sta u = que.front(); que.pop();
			Sta v = u; v.dir = (v.dir + 1) % 4;
			int old = vis[u.dir][u.color][u.x][u.y]; 
			if(vis[v.dir][v.color][v.x][v.y] == -1) {
				vis[v.dir][v.color][v.x][v.y] = old + 1;
				que.push(v);
			}
			v = u; v.dir = (v.dir + 3) % 4;
			if(vis[v.dir][v.color][v.x][v.y] == -1) {
				vis[v.dir][v.color][v.x][v.y] = old + 1;
				que.push(v);
			}
			v = u; v.x += dir[v.dir][0], v.y += dir[v.dir][1]; v.color = (v.color + 1) % 5;
			if(v.x >= 1 && v.x <= n && v.y >= 1 && v.y <= m && maze[v.x][v.y] != '#') {
				if(vis[v.dir][v.color][v.x][v.y] == -1) {
					vis[v.dir][v.color][v.x][v.y] = old + 1;
					que.push(v);
				}		
			}
		}
		int ans = inf;
		for(int i = 0; i < 4; i++) {
			if(vis[i][0][tx][ty] != -1)
				ans = min(ans, vis[i][0][tx][ty]);
		}
		printf("%d\n", ans == inf ? -1 : ans);
	}
	return 0;
}
