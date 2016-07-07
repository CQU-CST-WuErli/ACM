#include <iostream>
#include <vector>
#include <cstring> 
using namespace std;
const int maxn = 5e2 + 4;
bool vis[maxn];
int n, m, in[maxn], out[maxn], u, v;
vector<int> G[maxn]; 
void dfs(int u){
	vis[u] = true;
	for (int i = 0; i < G[u].size(); ++i) if (!vis[G[u][i]]) dfs(G[u][i]);
	return;
}
int main(){
	ios::sync_with_stdio(false);
	int i, j, k, kase;
	cin >> kase;
	while(kase--){
		cin >> n >> m;
		memset(in, 0, sizeof in);
		memset(out, 0, sizeof out);
		memset(vis, false, sizeof vis);
		for (i = 1; i <= n; ++i) G[i].clear();
		for (i = 0; i < m; ++i){
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
			in[v]++;
			out[u]++;
		}
		dfs(1);
		for (i = 1; i <= n; ++i) if (!vis[i]) break;
		if (i != n+1){
			cout << "No No\n";
			continue;
		}
		bool flag1 = true, flag2 = true;
		bool a = false, b = false;
		int cnt = 0;
		for (i = 1; i <= n; ++i){
			if ((in[i] + out[i]) & 1) cnt++;
			if (in[i] - out[i] == 1){
				if (a) flag2 = false;
				else a = true;
			}
			else if (out[i] - in[i] == 1){
				if (b) flag2 = false;
				else b = true;
			}
			else if (in[i] != out[i]) flag2 = false; 
		} 
		if (cnt > 2) flag1 = false;
		if (a ^ b) flag2 = false;
		if (flag1) cout << "Yes";
		else cout << "No";
		cout << ' ';
		if (flag2) cout << "Yes";
		else cout << "No";
		cout << endl;
	}
	return 0; 
} 
