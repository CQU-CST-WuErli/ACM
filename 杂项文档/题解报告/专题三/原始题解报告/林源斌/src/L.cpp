#include <iostream>
#include <cstring>
#include <vector> 
using namespace std;
const int maxn = 1e3 + 4;
const int maxe = 1e4 + 4;
struct Edge{
	int to, nxt;
}E[maxe];




int u, v, n, m, ecnt, head[maxn];
bool used[maxe], vis[maxn];
vector<int> Set[2];
inline void addedge(int u, int v){
	E[ecnt].to = v; E[ecnt].nxt = head[u]; head[u] = ecnt++;
	return;
}

void dfs(int u, int t){
//	cout << "reach "  << u << ' ' << t << endl;
	Set[t].push_back(u);
	vis[u] = true;
	for (int i = head[u]; ~i; i = E[i].nxt){
		int to = E[i].to;
		if (!vis[to]) dfs(to, t^1);
	}
	return;
}
bool check(int a, int b){
	for (int i = 0; i < Set[a].size(); ++i){
		int u = Set[a][i];
		for (int j = head[u]; ~j; j = E[j].nxt)
			used[j] = used[j^1] = true;
	}
	for (int i = 0; i < Set[b].size(); ++i){
		int u = Set[b][i];
		for (int j = head[u]; ~j; j = E[j].nxt)
			if (!used[j]) return false;
	}
	return true;
}
int ans;
void Solve(){
	ans = 0;
	for (int i = 1; i <= n; ++i)
		if (!vis[i]){
			Set[0].clear(); Set[1].clear();
			dfs(i, 0);
			if (Set[0].size() < Set[1].size()){
				if (check(0, 1)) ans += Set[0].size();
				else ans += Set[1].size();
			}
			else{
				if (check(1, 0)) ans += Set[1].size();
				else ans += Set[0].size();
			}
			if (ans > 10){
				ans = -1;
				return;
			}
		}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	int i, j, k, kase;
	cin >> kase;
	while(kase--){
		cin >> n >> m;
		ecnt = 0;
		memset(head, -1, sizeof head);
		memset(used, false, sizeof used);
		memset(vis, false, sizeof vis);
		for (i = 0; i < m; ++i){
			cin >> u >> v;
			addedge(u, v);
			addedge(v, u);
		}
		Solve();
		if (ans > 10) cout << "Poor lcy\n";
		else cout << ans << endl;
	}
	return 0;
}
