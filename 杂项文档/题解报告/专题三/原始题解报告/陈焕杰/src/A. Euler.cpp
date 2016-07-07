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
const int N = 505;
int deg[N];
int in[N], out[N];
int vis[N];
vector<int>G[N];
//int ret[N], vis[N]; 


//int find(int a)
//{
//	if (a == ret[a])
//		return a;
//	return ret[a] = find(ret[a]);
//}
//void merge(int a, int b)
//{
//	int x = find(a);
//	int y = find(b);
//	if (x != y)
//		ret[y] = x;
//	vis[a] = vis[b] = 1;
//}
void dfs(int pos)
{
	vis[pos] = 1;
	for (int i = 0; i < G[pos].size(); i++){
		int nxt = G[pos][i];
		if (!vis[nxt])
			dfs(nxt);
	}
} 
int main(void)
{
	int tes, n, m, i, j, u, v, cnt, flag, cnt1, cnt2;
	scanf("%d", &tes);
	while(tes--)
	{
		scanf("%d %d", &n, &m);
		for (i = 1; i <= n; i++){
			vis[i] = deg[i] = 0;
			in[i] = out[i] = 0;
			G[i].clear();
//			ret[i] = i;
		} 
		for (i = 1; i <= m; i++){
			scanf("%d %d", &u, &v);
			deg[u]++; deg[v]++;
			out[u]++; in[v]++; 
			G[u].push_back(v);
			G[v].push_back(u);
//			merge(u, v); 
		}	
		dfs(1);
		flag = 0;
		for (i = 1; i <= n; i++)
			if (!vis[i]) flag = 1;
		if (flag){
			printf("No No\n");
			continue;
		}
//		cnt = 0;
//		for (i = 1; i <= n; i++){
//			if (vis[i] && i == ret[i])	
//				cnt++;
//		}
//		if (cnt != 1){
//			printf("No No\n");
//			continue;
//		}
		cnt = 0;
		for (i = 1; i <= n; i++){
			if (deg[i] % 2)
				cnt++;
		}
		if (cnt == 2 || cnt == 0)
			printf("Yes ");
		else printf("No ");
		cnt = cnt1 = cnt2 = flag = 0;
		for (i = 1; i <= n; i++){
			if (in[i] == out[i])	
				cnt++;
			else{
				if (in[i] - out[i] == 1)
					cnt1++;
				else if (out[i] - in[i] == 1)
					cnt2++;
				else{
					flag = 1;
					break;
				}
			}
		}
		if (!flag || cnt == n || (cnt==n-2 && cnt1==1 && cnt2==1)) 
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
