#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 1e3 + 4;
const int inf = 0x3f3f3f3f;
//init();去检查有没有init(); 
struct Edge{
	int to, dis;
	bool used;
	Edge(int _to, int _dis):to(_to), dis(_dis){
		used = false;
	};
};
struct sta{
	int node, dis;
	sta(int _node, int _dis):node(_node), dis(_dis){
	}
	bool operator < (const sta &A) const{
		return dis > A.dis;
	}
};
priority_queue<sta> que;
vector<Edge> G[maxn], g[maxn];
int u, v, co, n, m, dis[maxn], di[maxn];//co为边权 
int S, T;//路径的起点与终点 
bool vis[maxn];
void dijkstra(){
	while(que.size()) que.pop();
	memset(dis, 0x3f, sizeof dis);
	memset(vis, false, sizeof vis);
	que.push(sta(S, 0));
	dis[S] = 0;
	while(que.size()){
		sta temp = que.top(); que.pop();
		int u = temp.node, d = temp.dis;//注意是d 
		if (d != dis[u]) continue;
		vis[u] = true;//大约是用来判断 哪些点可以到达的吧 
//		if (u == T) return; //不一定要有这句
		for (int i = 0; i < G[u].size(); ++i){
			int to = G[u][i].to;
			if (dis[to] > d + G[u][i].dis){
				dis[to] = d + G[u][i].dis;
				que.push(sta(to, dis[to])); 
			}
		} 
	}
	return;
}
void dijkstra2(){
	while(que.size()) que.pop();
	memset(di, 0x3f, sizeof di);
	que.push(sta(S, 0));
	di[S] = 0;
	while(que.size()){
		sta temp = que.top(); que.pop();
		int u = temp.node, d = temp.dis;//注意是d 
		if (d != di[u]) continue;
//		if (u == T) return; //不一定要有这句
		for (int i = 0; i < g[u].size(); ++i){
			int to = g[u][i].to;
			if (di[to] > d + g[u][i].dis){
				di[to] = d + g[u][i].dis;
				que.push(sta(to, di[to])); 
			}
		} 
	}
	return;
}
void init(){
	for (int i = 0; i <= n; ++i){
		G[i].clear();
		g[i].clear();
	}
	return;
}
int Beg[maxn];
bool dfs(int u){
//	cout << u << endl;
	if (u == T) return true;
	for (int i = Beg[u]; i < G[u].size(); ++i){
		int to = G[u][i].to;
		Beg[u]++;
		if (dis[to] != dis[u] + G[u][i].dis || di[to] + dis[to] != dis[T]) continue;
		if (dfs(to)) return true;
	}
	return false;
}
int Count(){
	memset(Beg, 0, sizeof Beg);
	int cnt = 0;
	for (int i = 0; i < G[S].size(); ++i){
		int to = G[S][i].to;
//		cout << "Edge: " << i << ' ' << dis[to] << ' ' << G[S][i].dis << endl;
		if (dis[to] == G[S][i].dis && dis[to] + di[to] == dis[T]) cnt += dfs(to);
	}
	return cnt;
}
int main(){
	ios::sync_with_stdio(false);
	int i, j, k, kase; 
	cin >> kase;
	while(kase--){
		cin >> n >> m;
		init();
		for (i = 0; i < m; ++i){
			cin >> u >> v >> co;
			G[u].push_back(Edge(v, co));
			g[v].push_back(Edge(u, co));
		}
		cin >> S >> T;
		dijkstra();
		swap(S, T);
		dijkstra2();
		swap(S, T);
//		cout << di[S] << ' ' << dis[T] << endl;
		if (dis[T] == inf){
			cout << 0 << endl;
//			cout << "here?\n";
			continue; 
		}
		cout << Count() << endl;
	} 
	return 0;
}
/*
10
6 8
1 2 1 
1 3 1 
1 4 1  
2 5 1 
3 5 1
4 5 1
5 6 1
4 6 2 
1 6 
*/
