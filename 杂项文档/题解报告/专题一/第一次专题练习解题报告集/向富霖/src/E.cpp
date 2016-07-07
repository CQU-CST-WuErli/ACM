#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
typedef pair<int, int> P;

char maze[666][666];
int sx, sy, tot, n, m, k, tx, ty;
int dis[205][205], vis[666][666];
const int dir[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
map<P, int> mp;

void bfs(P init, int s) {
	memset(dis[s], 0x3f, sizeof dis[s]);
	memset(vis, 0x3f, sizeof vis);
	queue<P> que; que.push(init);
	vis[init.first][init.second] = 0;
	dis[s][s] = 0;
	while(que.size()) {
		P p = que.front(); que.pop();
		int x = p.first, y = p.second;
		for(int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if(nx < 1 or ny < 1 or nx > n or ny > m or maze[nx][ny] == 'W')
				continue;
			if(vis[x][y] == k - 1 or vis[nx][ny] != inf) continue;	
			vis[nx][ny] = vis[x][y] + 1;
			if(mp.count(P(nx, ny))) {
				dis[s][mp[P(nx, ny)]] = vis[nx][ny];
				// cout << x << ' ' << y << "  " << nx << ' ' << ny << endl;	
				// cout << s << ' ' << mp[P(nx, ny)] << ' ' << vis[nx][ny] << endl;
			}
			que.push(P(nx, ny));
		}
	}
}

int dist[205], inq[205];

void SPFA(int s) {
	memset(inq, 0, sizeof inq);
	memset(dist, 0x3f, sizeof dist);
	queue<int> que; que.push(s);
	dist[s] = 0;
	while(que.size()) {
		int u = que.front(); que.pop(); inq[u] = 0;
		for(int v = 1; v <= tot; v++) {
			if(dis[u][v] == inf) continue;
			if(dist[v] > dist[u] + dis[u][v]) {
				dist[v] = dist[u] + dis[u][v];
				if(inq[v]) continue;
				inq[v] = 1; que.push(v);
			}
		}
	}
}

int main() {
#ifdef NEKO
	freopen("Nya.txt", "r", stdin);
#endif	
	int t; scanf("%d", &t);
	while(t--) {
		tot = 0; mp.clear();
		scanf("%d %d %d", &n, &m, &k);
		for(int i = 1; i <= n; i++) {
			scanf("%s", &maze[i][1]);
			for(int j = 1; j <= m; j++) {
				if(maze[i][j] == 'S') sx = i, sy = j;
				if(maze[i][j] == 'E') tx = i, ty = j;
				if(maze[i][j] != '.' and maze[i][j] != 'W')
					mp[P(i, j)] = ++tot;
			}
		}
		map<P, int>::iterator it;
		for(it = mp.begin(); it != mp.end(); ++it)
			bfs(it->first, it->second);
		SPFA(mp[P(sx, sy)]);
		if(dist[mp[P(tx, ty)]] == inf) puts("Poor RunningPhoton!");
		else printf("%d\n", dist[mp[P(tx, ty)]]);
	}
	return 0;
}
