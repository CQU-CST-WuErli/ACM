// SOJ NightMare2.cpp : 定义控制台应用程序的入口点。
//

#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;
int t;
int n, m, k;
const int MAXN = 1e4 + 10;
const int MAXM = 10e4 + 10;
const int MAXK = 5e5 + 10;
const ll INF = 0x3f3f3f3f3f3f3f3f;
struct qnode {
	int v;
	ll c;
	qnode(int _v = 0, ll _c = 0) :v(_v), c(_c){}
	bool operator <(const qnode &r)const  {
		return c>r.c;
	}
};
struct Edge {
	ll cap;
	int v, cost;
	Edge(int _v = 0, int _cost = 0, ll _cap = 0) :cap(_cap), v(_v), cost(_cost){}
};
vector<Edge>E[MAXN];
bool vis[MAXN];
ll dist[MAXN];
ll fazhi;
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
			if (E[u][i].cap < fazhi)continue;
			int v = E[tmp.v][i].v;
			int cost = E[u][i].cost;
			if (!vis[v] && dist[v]>dist[u] + cost) {
				dist[v] = dist[u] + cost;
				que.push(qnode(v, dist[v]));
			}
		}
	}
}
void addedge(int u, int v, int w, ll cap){
	E[u].push_back(Edge(v, w, cap));
	E[v].push_back(Edge(u, w, cap));
}
ll maxCap;
bool able(ll i){
	fazhi = i;
	Dijkstra(n, 1);
	if (dist[n] <= k)return true;
	else return false;
}
ll solve(){
	ll l = 0;
	ll r = maxCap;
	ll mid = (l + r) / 2;
	while (true){
		if (l == r){
			return l;
		}
		else if (l + 1 == r){
			if (able(r))return r;
			else return l;
		}
		if (able(mid))l = mid;
		else r = mid;
		mid = (l + r) / 2;
	}
	return 0;
}
int main()
{
	cin >> t;
	while (t--){
		cin >> n >> m >> k;
		for (int i = 1; i <= n; ++i){
			E[i].clear();
		}
		maxCap = 0;
		while (m--){
			int u, v, diss;
			ll cap;
			cin >> u >> v >> cap >> diss;
			addedge(u, v, diss, cap);
			maxCap = max(maxCap, cap);
		}
		ll ans = solve();
		if (ans <= 0)cout << "Poor RunningPhoton!" << endl;
		else cout << ans << endl;
	}
	return 0;
}

