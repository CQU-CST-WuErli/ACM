#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 5;
int n, a[101], m[101], k;
bool vis[maxn];
void onepack(int num){
	for (int i = k; i >= num; --i) vis[i] |= vis[i - num];
	return;
}
int main(){
	ios::sync_with_stdio(false);
	int i, j, kase;
	cin >> kase;
	while(kase--){
		cin >> n >> k;
		for (i = 1; i <= n; ++i) cin >> a[i];
		for (i = 1; i <= n; ++i){
			cin >> m[i];
			m[i] = min(k/a[i], m[i]);
		}
		memset(vis, false, sizeof vis);
		vis[0] = true;
		for (i = 1; i <= n; ++i){
			j = 1;
			while(j <= m[i]){
				m[i] -= j;
				onepack(j * a[i]);
				j *= 2;
			}
			onepack(m[i] * a[i]);
		}
		puts(vis[k] ? "yes" : "no");
	}
	
	return 0;
} 
