// SOJ 投票.cpp : 定义控制台应用程序的入口点。
//

#include<map>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<iostream>
#include<set>
using namespace std;
int t;
int n, m;
const int MAXN = 5e3 + 10;
const int MAXM = 3e4 + 10;

struct Edge{
	int to, next;
}edge[MAXM];
int head[MAXN];
int tot;
int low[MAXN];
int dfn[MAXN];
int Stack[MAXN];
int belong[MAXN];
int Index;
int top;
int cnt_scc;
bool Instack[MAXN];
int num[MAXN];
void addedge(int u, int v){
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}
void tarjan(int u){
	int v;
	low[u] = dfn[u] = ++Index;
	Stack[top++] = u;
	Instack[u] = true;
	for (int i = head[u]; i != -1; i = edge[i].next){
		v = edge[i].to;
		if (!dfn[v]){
			tarjan(v);
			if (low[u] > low[v])low[u] = low[v];
		}
		else if (Instack[v] && low[u] > dfn[v]){
			low[u] = dfn[v];
		}
	}
	if (low[u] == dfn[u]){
		cnt_scc++;
		do{
			v = Stack[--top];
			Instack[v] = false;
			belong[v] = cnt_scc;
			num[cnt_scc]++;
		} while (v != u);
	}
}
int nop[MAXN];//每个scc有多少人
int ind[MAXN];//入度
set<pair<int, int > >mappp;
vector<int> maps[MAXN];
void solve(int N){
	memset(dfn, 0, sizeof dfn);
	memset(Instack, false, sizeof Instack);
	memset(num, 0, sizeof num);
	Index = cnt_scc = top = 0;
	for (int i = 1; i <= N; ++i){
		if (!dfn[i]){
			tarjan(i);
		}
	}
	for (int i = 1; i <= n; ++i){
		++nop[belong[i]];
		for (int j = head[i]; j != -1; j = edge[j].next){
			int v = edge[j].to;
			if (belong[v] == belong[i])continue;
			if (mappp.find(make_pair(belong[v], belong[i])) == mappp.end()){
				mappp.insert(make_pair(belong[v], belong[i]));
				maps[belong[v]].push_back(belong[i]);
				ind[belong[i]]++;
			}
		}
	}
}
int numo[MAXN];
void init(){
	tot = 0;
	mappp.clear();
	memset(nop, 0, sizeof nop);
	memset(ind, 0, sizeof ind);
	memset(numo, 0, sizeof numo);
	memset(head, -1, sizeof head);
	for (int i = 1; i <= n; ++i){
		maps[i].clear();
	}
}
int vis[MAXN];
vector<int> ip;
int ans;
int dfs(int u){
	vis[u] = 1;
	int res = 0;
	for (int i = 0; i < maps[u].size(); ++i){
		int v = maps[u][i];
		if (vis[v])continue;
		res += dfs(v);
	}
	numo[u] = res + nop[u] - 1;
	return numo[u] + 1;
}
int main()
{
	scanf("%d", &t);
	int kase = 0;
	while (t--){
		++kase;
		scanf("%d%d", &n, &m);
		init();
		while (m--){
			int u, v;
			scanf("%d%d", &u, &v);
			++u; ++v;
			addedge(u, v);
		}
		solve(n);
		for (int i = 1; i <= cnt_scc; ++i){
			memset(vis, 0, sizeof vis);
			if (ind[i] == 0)dfs(i);
		}
		ans = -1;
		for (int i = 1; i <= n; ++i){
			if (ind[belong[i]] != 0)continue;
			if (numo[belong[i]] > ans){
				ans = numo[belong[i]];
				ip.clear();
				ip.push_back(i);
			}
			else if (numo[belong[i]] == ans){
				ip.push_back(i);
			}
		}
		cout << "Case " << kase << ": " << ans << endl;
		for (int i = 0; i < ip.size(); ++i){
			if (i != 0)cout << " ";
			cout << ip[i] - 1;
		}
		cout << endl;
	}
	return 0;
}

