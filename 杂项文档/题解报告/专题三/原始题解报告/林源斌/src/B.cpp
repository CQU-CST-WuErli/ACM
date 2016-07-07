#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int a[5][5], in[12];
bool E[12][12];
priority_queue<int, vector<int>, greater<int> > que;
int main(){
	ios::sync_with_stdio(false);
	int i, j, k, kase;
	cin >> kase;
	while(kase--){
		for (i = 1; i <= 4; ++i)
			for (j = 1; j <= 4; ++j) cin >> a[i][j];
		memset(E, false, sizeof E);
		memset(in, 0, sizeof in);
		for (i = 1; i <= 9; ++i){
			int x = (i - 1) / 3 + 1, y = (i - 1) % 3 + 1;
			for (j = 0; j < 2; ++j)
			for (k = 0; k < 2; ++k){
				if (a[x+j][y+k] != i){
					E[a[x+j][y+k]][i] = true;
				}
			}
		}
		for (i = 1; i <= 9; ++i) for (j = 1; j <= 9; ++j) if (E[i][j]) in[j]++;
		while(que.size()) que.pop();
		for (i = 1; i <= 9; ++i) if (in[i] == 0) que.push(i);
		while(que.size()){
			int u = que.top(); que.pop();
			for (i = 1; i <= 9; ++i) if (E[u][i] && 0 == --in[i]) que.push(i);
		}
		bool f = false;
		for (i = 1; i <= 9; ++i) if (in[i]){
//			cout << i;
			f = true;
		}
		if (f) cout << "BOOM!\n";
		else cout << "Lucky dog!\n";
	} 
	return 0;
}
