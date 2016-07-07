#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;
const int maxn = 1e4 + 4;
const int INF = 2e9;
//init();去检查有没有init(); 
struct Edge{
	int to, cap, dis;
	Edge(int _to, int _cap, int _dis):to(_to), dis(_dis), cap(_cap){
	};
	bool operator < (const Edge &A) const{
		return cap > A.cap;
	}
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
vector<Edge> G[maxn];
int u, v, co, cap, n, m, dis[maxn], K;//co为边权 
int S, T;//路径的起点与终点 
bool vis[maxn];
void dijkstra(){
	while(que.size()) que.pop();
	memset(dis, 0x3f, sizeof dis);
	que.push(sta(S, 0));
	dis[S] = 0;
	while(que.size()){
		sta temp = que.top(); que.pop();
		int u = temp.node, d = temp.dis;//注意是d 
		if (d != dis[u]) continue;
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
void init(){
	for (int i = 0; i <= n; ++i) G[i].clear();
	return;
}
struct Nsta{
	int node, usetime;
	Nsta(int _node, int _usetime):node(_node), usetime(_usetime){
		
	}
	bool operator < (const Nsta &A) const{
		return usetime > A.usetime;
	}
};
priority_queue<Nsta> q;
int been[maxn];
bool Check(int num){
	while(q.size()) q.pop();
	memset(been, 0x3f, sizeof been);
	been[1] = 0;
	q.push(Nsta(1, 0));
	while(q.size()){
		Nsta temp = q.top(); q.pop();
		int u = temp.node, t = temp.usetime;
		if (u == n) return true;
		if (been[u] != t) continue;
		for (int i = 0; i < G[u].size(); ++i){
			int to = G[u][i].to;
//			cout << to << endl;
			if (G[u][i].cap < num) continue;
			if (t + G[u][i].dis + dis[to] > K) continue;
			if (been[to] > t + G[u][i].dis){
				been[to] = t + G[u][i].dis;
				q.push(Nsta(to, been[to])); 
			}
		} 
	}
	return false;
}
int Solve(){
	int l = 1, rght = INF;
	while(l < rght){
		int mid = int((1LL * l + rght) / 2) + 1;
//		cout << l << ' ' << rght << endl;
		if (Check(mid)) l = mid;
		else rght = mid - 1;
//		getchar(); getchar();
	}
	return l;
}
int main(){
	ios::sync_with_stdio(false);
	int i, j, k, kase; 
//	cout << INF << endl;
	cin >> kase;
	while(kase--){
		cin >> n >> m >> K;
		init();
		for (i = 0; i < m; ++i){
			cin >> u >> v >> cap >> co;
			G[u].push_back(Edge(v, cap, co));
			G[v].push_back(Edge(u, cap, co));
		}
//		for (i = 1; i <= n; ++i) sort(G[i].begin(), G[i].end());
		S = n, T = 1;
		dijkstra();
		if (dis[T] > K){
			cout << "Poor RunningPhoton!\n";
			continue;
		}
		cout << Solve() << endl; 
	}
	
	return 0;
}
















