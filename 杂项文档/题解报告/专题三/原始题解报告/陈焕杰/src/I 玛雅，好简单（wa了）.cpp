# include <iostream>
# include <algorithm>
# include <cstdio>
# include <cstring>
# include <queue>
# include <vector>
# include <cmath>
# include <map>
# include <set>
# define pi acos(-1)
# define LL long long
# define INF 0x3f3f3f3f
using namespace std;
const int N = 1e4 + 5;

int head[N], nxt[N], pnt[N], cnt;
int mp[N][N];
int n, m, ans;
int dfn[N], low[N], idex;

void add_edge(int u, int v)
{
	pnt[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt++;
}

void tarjan(int u, int fa)
{
	dfn[u] = low[u] = ++idex;
	for (int i = head[u]; ~i; i = nxt[i]){
		int v = pnt[i];
		if (!dfn[v]){
			tarjan(v, u);
			low[u] =  min(low[u], low[v]);
		}
		else if (v != fa)
			low[u] = min(low[u], dfn[v]);
		if (low[v] > dfn[u]) {
//			if (mp[u][v] > 1){
//				mp[u][v]--;
//				mp[v][u]--;
//			}
//			else if (mp[u][v] == 1)
				ans++;
		}
	}
}

int main(void)
{
	int tes, i, j, u, v;
	cin>>tes;
	for(i = 1; i <= tes; i++){
		memset(head, -1, sizeof(head));
		memset(mp, 0, sizeof(mp));
		cnt = ans = 0;
		scanf("%d %d", &n, &m);
		for (j = 1; j <= m; j++){
			scanf("%d %d", &u, &v);
			add_edge(u, v);
//			mp[u][v]++;
//			mp[v][u]++;
		}
		memset(dfn, 0, sizeof(dfn));
		memset(low, 0, sizeof(low));
		idex = 0;
		for (j = 1; j <= n; j++){
			if (!dfn[j]){
				tarjan(i, 0);
			}
		}
		printf("Case %d: %d\n", i, ans);
	} 
	return 0;
}

