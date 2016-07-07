// SOJ ���·.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdio>
#include<cmath>
using namespace std;
int t;
int n, m;
const int MAXN = 1e3 + 10;
const int MAXM = 1e5 + 10;
/*
* ʹ�����ȶ����Ż�Dijkstra�㷨
* ���Ӷ�O(ElogE)
* ע���vector<Edge>E[MAXN]���г�ʼ����ӱ�
*/
const int INF = 0x3f3f3f3f;
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
vector<Edge>E[MAXN];
bool vis[MAXN];
int dist[MAXN];
void Dijkstra(int n, int start)//��ı�Ŵ�1��ʼ
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
int mindis;
int st, ed;
bool dfs(int u, int cc){//�������е�
	if (cc > mindis)return false;
	if (u == ed)return true;
	for (int i = 0; i < E[u].size(); ++i){
		int v = E[u][i].v;
		int c = E[u][i].cost;
		if (dfs(v, cc + c)){
			E[u].erase(E[u].begin() + i);
			return true;
		}
	}
	return false;
}
int main()
{
	cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i = 1; i <= n; ++i){
			E[i].clear();
		}
		while (m--){
			int u, v, c;
			cin >> u >> v >> c;
			addedge(u, v, c);
		}
		cin >> st >> ed;
		Dijkstra(n, st);
		mindis = dist[ed];
		int ans = 0;
		while (dfs(st, 0))++ans;
		cout << ans << endl;
	}
	return 0;
}

