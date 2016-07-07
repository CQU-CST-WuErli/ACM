#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 1e3 + 4;
const int dmaxn = 2e3 + 4;
int n, A, B, dis[maxn][2], x[maxn], y[maxn], x1, s1, x2, s2, DD;
int hate[maxn][2], like[maxn][2], S[dmaxn], top;
bool beg[maxn][maxn], map[maxn], mark[dmaxn];
vector<int> G[dmaxn];
inline int getdis(int i, int a, int b){
	return abs(x[i] - a) + abs(y[i] - b);
}
bool dfs(int x){
	int y = (x % 2 == 0 ? x - 1 : x + 1) ; 
	if (mark[y]) return false;
	if (mark[x]) return true;
	S[top++] = x;
	mark[x] = true;
	for (int i = 0; i < G[x].size(); ++i)
		if (!dfs(G[x][i])) return false;
	return true;
}
bool check(int D){
	int i, j;
	for (i = 1; i <= 2*n; ++i) G[i].clear();
	for (i = 1; i <= A; ++i){
		int u = hate[i][0], v = hate[i][1];
		G[2*u-1].push_back(2*v);
		G[2*u].push_back(2*v-1);
		G[2*v-1].push_back(2*u);
		G[2*v].push_back(2*u-1);
	}
	for (i = 1; i <= B; ++i){
		int u = like[i][0], v = like[i][1];
		G[2*u-1].push_back(2*v-1);
		G[2*u].push_back(2*v);
		G[2*v-1].push_back(2*u-1);
		G[2*v].push_back(2*u);
	}
	for (i = 1; i <= n; ++i)
	for (j = 1; j <= n; ++j){
		if (i == j) continue;
		if (dis[i][0] + dis[j][0] > D) G[i*2-1].push_back(2*j);
		if (dis[i][1] + dis[j][1] > D) G[i*2].push_back(2*j-1);
		if (dis[i][0] + dis[j][1] + DD > D) G[i*2-1].push_back(2*j-1);
		if (dis[i][1] + dis[j][0] + DD > D) G[i*2].push_back(2*j);
	}
	memset(mark, false, sizeof mark);
	for (i = 1; i <= n; ++i){
		if (mark[i*2] || mark[i*2-1]) continue;
		top = 0;
		if (!dfs(i*2-1)){
			while(top) mark[S[--top]] = false;
			if (!dfs(i*2)) return false;
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	int i, j, k, kase;
	scanf("%d", &kase);
//	freopen("input.txt", "r", stdin);
	while(kase--){
		scanf("%d%d%d", &n, &A, &B);
		scanf("%d%d%d%d", &x1, &s1, &x2, &s2);
		DD = abs(x1 - x2) + abs(s1 - s2);
		for (i = 1; i <= n; ++i){
			scanf("%d%d", &x[i], &y[i]);
			dis[i][0] = getdis(i, x1, s1);
			dis[i][1] = getdis(i, x2, s2);
		}
		for (i = 1; i <= A; ++i) scanf("%d%d", &hate[i][0], &hate[i][1]);
		for (i = 1; i <= B; ++i) scanf("%d%d", &like[i][0], &like[i][1]);
		
		
		int lft = 0, rght = 16000000;
		if (!check(rght)){
			printf("%d\n", -1);
			continue; 
		}
		while(lft < rght){
			int mid = (lft + rght) / 2;
			if (check(mid)) rght = mid;
			else lft = mid + 1;
		}
//		cout << check(17) << endl;
		printf("%d\n", lft);
	} 
	return 0;
}
