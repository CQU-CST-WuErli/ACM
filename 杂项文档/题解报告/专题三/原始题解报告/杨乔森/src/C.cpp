// SOJ 寻找fly真迹.cpp : 定义控制台应用程序的入口点。
//

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<cstring>
using namespace std;
int t;
int n, m;
const int MAXN = 510;
const int MAXM = 500 * 500 + 10;
int map[MAXN][MAXN];
bool flag;
int vis[MAXN];//每个点的组别
int num;
int main()
{
	cin >> t;
	while (t--){
		cin >> n >> m;
		num = 0;
		memset(map, 0, sizeof map);
		while (m--){
			int u, v;
			cin >> u >> v;
			map[u][v] = 1;
			map[v][u] = 1;
		}
		flag = true;
		memset(vis, 0, sizeof vis);
		bool findd = false;
		for (int i = 1; i <= n&&!findd; ++i){
			for (int j = 1; j <= n&&!findd; ++j){
				if (i == j)continue;
				if (map[i][j] == 0){
					for (int k = 1; k <= n; ++k){
						if (i == k)continue;
						if (map[i][k] == 0){
							vis[k] = 1;
							++num;
							findd = true;
						}
					}
				}
			}
		}
		for (int i = 1; i <= n&&flag; ++i){
			if (vis[i] == 1){//不能同组相连
				for (int k = 1; k <= n; ++k){
					if (i == k)continue;
					if (map[i][k] == 0 && vis[k] == 1){
						flag = false;
						break;
					}
				}
			}
			else{//与1中所有点有连接或者无连接
				bool has = false;//是否有连接
				int tot = 0;//连接了多少1中点
				bool ff = true;//可行
				for (int j = 1; j <= n; ++j){
					if (i == j)continue;
					if (vis[j] == 1){
						if (map[i][j] == 0){
							++tot;
							has = true;
						}
						else{
							if (has){
								ff = false;
								break;
							}
						}
					}
					else{
						if (map[i][j] == 0){
							ff = false;
							break;
						}
					}
				}
				if (!ff || (has&&tot != num)){
					flag = false;
					break;
				}
			}
		}
		if (flag)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}

