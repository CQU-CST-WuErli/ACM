// SOJ RunningPhoton's Nightmare.cpp : 定义控制台应用程序的葋E诘恪?
//

#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<fstream>
using namespace std;
//Dijistra最短路---------------------------------------------------
const int INF = 0x3f3f3f3f;
const int MAXE = 1000010;
struct qnode {
	int v;
	int c;
	qnode(int _v = 0, int _c = 0) :v(_v), c(_c){}
	bool operator <(const qnode &r)const  {
		return c>r.c;
	}
};
struct Edge {
	int v, cost;
	Edge(int _v = 0, int _cost = 0) :v(_v), cost(_cost){}
};
vector<Edge>E[MAXE];
bool vis[MAXE];
int dist[MAXE];
void Dijkstra(int n, int start)//点的编号从1开始
{
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= n; i++)dist[i] = INF;
	priority_queue<qnode>que;
	while (!que.empty())que.pop();
	dist[start] = 0;
	que.push(qnode(start, 0));
	qnode tmp;
	while (!que.empty()){
		tmp = que.top();
		que.pop();
		int u = tmp.v;
		if (vis[u])continue;
		vis[u] = true;
		for (int i = 0; i<E[u].size(); i++){
			int v = E[tmp.v][i].v;
			int cost = E[u][i].cost;
			if (!vis[v] && dist[v]>dist[u] + cost) {
				dist[v] = dist[u] + cost;
				que.push(qnode(v, dist[v]));
			}
		}
	}
}
void addedge(int u, int v, int w){
	E[u].push_back(Edge(v, w));
}
void init(int i){
	for (int j = 0; j <= i; ++j){
		E[j].clear();
	}
}
//------------------------------------------------------------------
struct node
{
	int i, j;
	node(){};
	node(int ti, int tj) :i(ti), j(tj){};
	const node& operator=(const node& t){
		i = t.i;
		j = t.j;
		return *this;
	}
};
int t;
const int MAXN = 610;
node r[MAXN];
char map[MAXN][MAXN];
int dis[MAXN][MAXN];
int hashs[MAXN][MAXN];//坐标与点的映射
int n, m, k;
int tot;//点数//1点是E//2点是S
bool check(int i, int j){
	return (i >= 1) && (j >= 1) && (i <= n) && (j <= m) && (map[i][j] != 'W') && (dis[i][j] == -1);
}
void srh(int u){
	int rx[] = { 0, 0, 1, -1 };
	int ry[] = { -1, 1, 0, 0 };
	queue<node> q;
	memset(dis, -1, sizeof dis);
	q.push(r[u]);
	dis[r[u].i][r[u].j] = 0;
	while (!q.empty()){
		int x = q.front().i;
		int y = q.front().j;
		q.pop();
		int td = dis[x][y] + 1;
		if (td >= k)continue;
		for (int i = 0; i < 4; ++i){
			int tx = x + rx[i]; int ty = y + ry[i];
			if (!check(tx, ty))continue;
			dis[tx][ty] = td;
			char tc = map[tx][ty];
			if (tc == 'R' || tc == 'E'){
				addedge(u, hashs[tx][ty], td);
			}
			q.push(node(tx, ty));
		}
	}
}
int main(){
	cin >> t;
	while (t--){
		scanf("%d%d%d", &n, &m, &k);
		init(155);
		tot = 2;
		for (int i = 1; i <= n; ++i){
			scanf("%s", map[i]+1);
			for (int j = 1; j <= m; ++j){
				if (map[i][j] == 'R'){
					hashs[i][j] = ++tot;
					r[tot] = node(i, j);
				}
				else if (map[i][j] == 'S'){
					hashs[i][j] = 2;
					r[2] = node(i, j);
				}
				else if (map[i][j] == 'E'){
					hashs[i][j] = 1;
					r[1] = node(i, j);
				}
			}
		}
		for (int i = 2; i <= tot; ++i){
			srh(i);
		}
		Dijkstra(tot, 2);
		int ans = dist[1];
		if (ans == INF)
			printf("Poor RunningPhoton!\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}