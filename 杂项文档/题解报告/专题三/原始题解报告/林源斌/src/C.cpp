#include <iostream>
#include <cstring>
#include <cstdio> 
using namespace std; 
const int maxn = 5e2 + 4;
int n, m, degree[maxn], u, v;
bool vis[maxn][maxn];
char s[maxn];
int main(){
	ios::sync_with_stdio(false);
	int i, j, k, kase;
	cin >> kase;
	while(kase--){
		cin >> n >> m;
		memset(degree, 0, sizeof degree);
		memset(vis, false, sizeof vis);
		memset(s, 0, sizeof s);
		while(m--){
			cin >> u >> v;
			vis[u][v] = vis[v][u] = true;
			degree[u]++;
			++degree[v];
		}
		s[n+1] = '\0';
//		for (i = 1; i <= n; ++i) cout << degree[i] << ' '; cout << endl;
		for (i = 1; i <= n; ++i) if (n - 1 == degree[i]) s[i] = 'b';
//		for (i = 1; i <= n; ++i) cout << s[i]; cout << endl;
		for (i = 1; i <= n; ++i) if (s[i] != 'b') break;
		if (n + 1 == i){
			cout << "Yes\n";
			continue;
		}
		s[i] = 'a';
		
		for (j = 1; j <= n; ++j) 
			if (s[j] != 'b' && i != j){
				if (vis[i][j]) s[j] = 'a';
				else s[j] = 'c';
			}
		bool flag = true;
		for (i = 1; i <= n && flag; ++i){
			for (j = 1; j <= n && flag; ++j){
				if (i == j) continue;
				if (s[i] == 'a'){
					if (s[j] == 'a' && !vis[i][j]) flag = false;
					else if (s[j] =='c' && vis[i][j]) flag = false;
				}
				else if (s[i] == 'c'){
					if (s[j] == 'c' && !vis[i][j]) flag = false;
					else if (s[j] =='a' && vis[i][j]) flag = false;
				}
			}
		}
//		cout << s+1 << endl;
//		puts(flag ? "Yes" : "No");
		if (flag) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
