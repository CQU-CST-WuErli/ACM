#include <iostream>
#include <algorithm>
using namespace std;
const int maxe = 2e6 + 4;
const int maxn = 5e5 + 4;
int n, m, father[maxn], ecnt;
struct Edge{
	int u, v, dis;
	Edge(){
	}
	bool operator < (const Edge &A) const{
		return dis < A.dis;
	}
}E[maxe];
int find(int a){
	if (father[a] == a) return a;
	return father[a] = find(father[a]);
}
int kruskal(){
	for (int i = 0; i < ecnt; ++i){
		int tempa = find(E[i].u), tempb = find(E[i].v);
		if (tempa == tempb) return E[i].dis;
		father[tempa] = tempb; 
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(false);
	int i, j, k, kase;
	cin >> kase;
	while(kase--){
		cin >> n >> m;
		ecnt = 0;
		for (i = 1; i <= n; ++i) father[i] = i;
		for (i = 1; i <= m; ++i){
			cin >> E[ecnt].u >> E[ecnt].v >> E[ecnt].dis;
			ecnt++;
		}
		sort(E, E+ecnt);
		int ans = kruskal();
		if (ans == -1) cout << "No solution!\n";
		else cout << ans << endl;
	}
	return 0;
} 
