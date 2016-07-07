/* tarjan求scc */ 
/* 
该代码中使用的变量名有
n, m, u, v, G, dfn, low, scc, index, in, vis, sta, to, Si

类名有:
Edge

函数名有:
InitEdge() addedge() solve() tarjan() 
*/ 

#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <set> 
using namespace std; 
const int maxn = 1e4+4;
#define bug puts("bugbug")
int n, m, u, v, scc;
/*---------------------建图部分--------------------*/ 
//暂时写的vector邻接表存图 改成结构体版的链式前向星是很方便的 
//加一个int的head数组 一个ecnt  结构体加一个nxt的成员变量 两个函数稍作修改 
//虽然现在结构体里面就一个成员变量 显得比较lowbit
//但是写成结构体比较好加东西orz 
struct Edge{
	int to;
	Edge(int _to):to(_to)
	{}
};

vector<Edge> G[maxn];

void InitEdge(){
	for (int i = 0; i <= n; ++i) G[i].clear(); 
	return;
}

inline void addedge(int u, int v){
	G[u].push_back(Edge(v));
	return;
}
/*-------------------------------------------------*/ 
/*-------------------建新图部分--------------------*/ 
//由于暂时新图的边不需要储存什么特别的东西 直接set<int> 了
set<int> Si[maxn];
int tar[maxn];
vector<Edge> g[maxn];
void NewInitEdge(){
	for (int i = 0; i <= n; ++i){
		g[i].clear();
		Si[i].clear(); 
	}
	return;
}

inline void Newaddedge(int u, int v){
	g[u].push_back(Edge(v));
	return;
}

void NewMap(){
	NewInitEdge();
	for (int i = 1; i <= n; ++i){
		int node = tar[i];
		for (int j = 0; j < G[i].size(); ++j) {
			if (node == tar[G[i][j].to]) continue;
			Si[node].insert(tar[G[i][j].to]);
		}
	}
	for (int i = 1; i <= scc; ++i)
		for (set<int>::iterator it = Si[i].begin(); it != Si[i].end(); ++it) Newaddedge(i, *it);
	return;
}
/*-------------------------------------------------*/ 
/*-------------------tarjan部分--------------------*/ 
//solve当中要特别注意点的起始下标是0还是1
 
int dfn[maxn], low[maxn], Dindex;//tar表示将第i个点 缩到第tar[i]个强连通分量中去了 
bool vis[maxn], in[maxn];
stack<int> sta;
void tarjan(int u){
	dfn[u] = low[u] = Dindex++;
	vis[u] = in[u] = true;
	sta.push(u);
	for (int i = 0; i < G[u].size(); ++i){
		int to = G[u][i].to;
		if (!vis[to]){
			tarjan(to);
			low[u] = min(low[u], low[to]);
		}
		else if (in[to]) low[u] = min(dfn[to], low[u]);
	}
	if (dfn[u] == low[u]){
		scc++; 
		while(sta.top() != u){
			in[sta.top()] = false;
			tar[sta.top()] = scc; 
			sta.pop();
		}
		tar[sta.top()] = scc;
		in[sta.top()] = false;
		sta.pop();
	}
	return; 
}


void solve(){
	Dindex = scc = 0;
	memset(dfn, -1, sizeof dfn);
	memset(in, false, sizeof in);
	memset(vis, false, sizeof vis);
	while(sta.size()) sta.pop();
	for (int i = 1; i <= n; ++i)
		if (dfn[i] == -1) tarjan(i); 
	return;
}
/*-------------------------------------------------*/
int match[maxn];
bool vist[maxn];
bool find(int u){
	for (int i = 0; i < g[u].size(); ++i){
		int to = g[u][i].to;
		if (vist[to]) continue;
		vist[to] = true;
		if (match[to] == -1 || find(match[to])){
			match[to] = u;
			return true;
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	int i, j, k, kase;
	cin >> kase;
	while(kase--){
		cin >> n >> m;
		InitEdge();
		for (i = 0; i < m; ++i){
			cin >> u >> v;
			addedge(u, v);
		}
		solve();
		NewMap();
		memset(match, -1, sizeof match);
		int ans = 0;
		for (i = 1; i <= scc; ++i){
			memset(vist, false, sizeof vist);
			if (find(i)) ans++;
		}
		cout << scc - ans<< endl;
	}
	return 0;
}
