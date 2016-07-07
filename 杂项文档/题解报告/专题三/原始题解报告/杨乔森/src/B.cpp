// SOJ -0你电脑炸啦.cpp : 定义控制台应用程序的入口点。
//

#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int t;
const int MAXN = 10;
int map[MAXN][MAXN];
int vis[MAXN];
int num[MAXN];
int cnt;
bool able(int t){
	if (num[t] == 0)return false;
	for (int i = 1; i <= 3; ++i){
		for (int j = 1; j <= 3; ++j){
			int tt = (map[i][j] != 0) + (map[i + 1][j] != 0) + (map[i][j + 1] != 0) + (map[i + 1][j + 1] != 0);
			if (map[i + 1][j] != t && map[i + 1][j] != 0)continue;
			if (map[i + 1][j + 1] != t && map[i + 1][j + 1] != 0)continue;
			if (map[i][j + 1] != t && map[i][j + 1] != 0)continue;
			if (map[i][j] != t && map[i][j] != 0)continue;
			if (tt != num[t])continue;
			map[i][j] = map[i + 1][j + 1] = map[i + 1][j] = map[i][j + 1] = 0;
			num[t] = 0;
			cnt -= tt;
			return true;
		}
	}
	return false;
}
int main()
{
	cin >> t;
	while (t--){
		memset(vis, 0, sizeof vis);
		memset(num, 0, sizeof num);
		cnt = 16;
		for (int i = 1; i <= 4; ++i){
			for (int j = 1; j <= 4; ++j){
				cin >> map[i][j];
				num[map[i][j]]++;
			}
		}
		bool flag = true;
		while (cnt&&flag){
			flag = false;
			for (int i = 1; i <= 9; ++i){
				flag = flag || able(i);
			}
		}
		if (!flag)cout << "BOOM!" << endl;
		else cout << "Lucky dog!" << endl;
	}
	return 0;
}

