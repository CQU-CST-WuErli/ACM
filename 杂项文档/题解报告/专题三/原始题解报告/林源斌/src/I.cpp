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
const int maxn = 1e4 + 4;
const int maxe = 1e5 + 4;
#define bug puts("bugbug")
int n, m, u, v, scc;
/*---------------------建图部分--------------------*/ 
//暂时写的vector邻接表存图 改成结构体版的链式前向星是很方便的 
//加一个int的head数组 一个ecnt  结构体加一个nxt的成员变量 两个函数稍作修改 
//虽然现在结构体里面就一个成员变量 显得比较lowbit
//但是写成结构体比较好加东西orz 
struct Edge{
	int to, nxt;
	Edge(){
	};
	Edge(int _to, int _nxt):to(_to), nxt(_nxt)
	{}
};

Edge E[maxe];
int head[maxn], ecnt;
void InitEdge(){
	ecnt = 0;
	memset(head, -1, sizeof head);
	return;
}

inline void addedge(int u, int v){
	E[ecnt++] = Edge(v, head[u]);
	head[u] = ecnt-1;
	return;
}
/*-------------------------------------------------*/ 
/*-------------------建新图部分--------------------*/ 
//由于暂时新图的边不需要储存什么特别的东西 直接set<int> 了
set<int> Si[maxn];
int tar[maxn], necnt, nhead[maxn], indegree[maxn];
Edge nE[maxe];
void NewInitEdge(){
	necnt = 0;
	memset(indegree, 0, sizeof indegree);
	for (int i = 0; i <= n; ++i) Si[i].clear();
	memset(nhead, -1, sizeof nhead);
	return;
}

inline void Newaddedge(int u, int v){
	nE[necnt++] = Edge(v, nhead[u]);
	nhead[u] = necnt-1;
	indegree[v]++;
	return;
}

void NewMap(){
	NewInitEdge();
	for (int i = 1; i <= n; ++i){
		int node = tar[i];
		for (int j = head[i]; ~j; j = E[j].nxt) {
			if (node == tar[E[j].to]) continue;
			Si[node].insert(tar[E[j].to]);
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
bool vis[maxn], in[maxn], used[maxe];
stack<int> sta;
int Ians;
void tarjan(int u){
	dfn[u] = low[u] = Dindex++;
	vis[u] = in[u] = true;
	sta.push(u);
	for (int i = head[u]; ~i; i = E[i].nxt){
		if (used[i]) continue;
		used[i] = used[i^1] = true;
		int to = E[i].to;
		if (!vis[to]){
			tarjan(to);
			if (low[to] == dfn[to] && !in[to]) Ians++;
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


void Solve(){
	Dindex = scc = 0;
	memset(dfn, -1, sizeof dfn);
	memset(in, false, sizeof in);
	memset(vis, false, sizeof vis);
	memset(used, false, sizeof used);
	while(sta.size()) sta.pop();
	for (int i = 1; i <= n; ++i)
		if (dfn[i] == -1) tarjan(i); 
	return;
}
/*-------------------------------------------------*/
bool Vis[maxn];
void dfs(int u){
	Vis[u] = true;
	for (int i = nhead[u]; ~i; i = nE[i].nxt){
		int to = nE[i].to;
		if (Vis[to]) continue;
		dfs(to);
	}
	return;
} 
int main(){
	ios::sync_with_stdio(false);
	int i, j, k, kase, ikase = 1;
	cin >> kase;
	while(kase--){
		cin >> n >> m;
		InitEdge();
		for (i = 0; i < m; ++i){
			cin >> u >> v;
			addedge(u, v);
			addedge(v, u);
		}
		Ians = 0;
		Solve();
		cout << "Case " << ikase++ << ": " << Ians << endl;
	}
	return 0;
}
