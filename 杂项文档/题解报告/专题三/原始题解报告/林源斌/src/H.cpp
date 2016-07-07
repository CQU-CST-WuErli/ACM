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
	int node, usetime, maxv;
	Nsta(int _node, int _usetime, int _maxv):node(_node), usetime(_usetime), maxv(_maxv){
		
	}
	bool operator < (const Nsta &A) const{
		if (maxv == A.maxv) return usetime > A.usetime;
		return maxv < A.maxv;
	}
};
priority_queue<Nsta> q;
map<int, int> dp[maxn];
map<int, int>::iterator it;
void Solve(){
	for (int i = 1; i <= n; ++i) dp[i].clear();
	dp[1][0] = INF;
	q.push(Nsta(1, 0, INF));
	while(q.size()){
		Nsta temp = q.top(); q.pop();
		int u = temp.node, t = temp.usetime, ca = temp.maxv;
		if (dp[u][t] != ca) continue;
		for (int i = 0; i < G[u].size(); ++i){
			Edge E = G[u][i];
			int to = E.to;
			int nc = min(ca, E.cap);
			int nt = t + E.dis;
			if (nt + dis[to] > K) continue;
			it = dp[to].lower_bound(nt);
			if (it == dp[to].begin()){
//				cout << "from " <<  u << "   to " << to << ' ' << E.cap << endl;
 				if (it != dp[to].end() && it->first == nt && it->second >= nc) continue;
// 				cout << dp[to][nt] << endl;
				dp[to][nt] = nc;
//				cout << dp[to][nt] << endl;
				q.push(Nsta(to, nt, nc));
				it = dp[to].upper_bound(nt);
				while(it != dp[to].end() && it->second < nc){
					it->second = nc;
					++it;
				}
			}
			else{
				if ((--it)->second >= nc) continue;
				++it;
				if (it == dp[to].end() || it->first > nt){
					dp[to][nt] = nc;
					q.push(Nsta(to, nt, nc));
				}
				else if (it->first == nt){
					if (it->second >= nc) continue;
					dp[to][nt] = nc;
					q.push(Nsta(to, nt, nc));
				}
				it = dp[to].upper_bound(nt);
				while(it != dp[to].end() && it->second < nc){
					it->second = nc;
					++it;
				}
			}
		}
	}
	return;
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
		Solve();
//		cout << ans << endl;
		it = dp[n].end();
		--it;
		cout << it->second << endl; 
	}
	
	return 0;
}
















