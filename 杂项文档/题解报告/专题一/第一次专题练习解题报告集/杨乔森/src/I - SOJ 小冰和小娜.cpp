// SOJ 小冰和小娜.cpp : 定义控制台应用程序的入口点。
//
#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;
int t;
int m, n;
const int INF = -1;
const int MAXN = 60;
char maps[MAXN][MAXN];
int dis[MAXN][MAXN][5][4];
//0绿1黑2红3蓝4白
inline int nxtc(int c){
	return (c + 1 > 4) ? 0 : (c + 1);
}
inline int lw(int w){
	return (w - 1 < 0) ? 3 : (w - 1);
}
inline int rw(int w){
	return (w + 1 > 3) ? 0 : (w + 1);
}
struct node{
	int i, j;
	int c;//颜色
	int w;//方向
	node(int ti, int tj, int tc, int tw) :c(tc), w(tw), i(ti), j(tj){};
};
int ans = 0;
queue<node> q;
int main()
{
	cin >> t;
	while (t--){
		while (!q.empty())q.pop();
		//scanf("%d%d", &m, &n);
		cin >> m >> n;
		memset(dis, INF, sizeof dis);
		for (int i = 1; i <= m; ++i){
			for (int j = 1; j <= n; ++j){
				cin >> maps[i][j];
				//scanf("%c", &maps[i][j]);
				if (maps[i][j] == 'S'){
					q.push(node(i, j, 0, 0));
					dis[i][j][0][0] = 0;
				}
			}
		}
		ans = -1;
		while (!q.empty()){
			node t1 = q.front();
			q.pop();
			int tdis = dis[t1.i][t1.j][t1.c][t1.w] + 1;
			//左
			if (dis[t1.i][t1.j][t1.c][lw(t1.w)] == INF){
				dis[t1.i][t1.j][t1.c][lw(t1.w)] = tdis;
				q.push(node(t1.i, t1.j, t1.c, lw(t1.w)));
				if (maps[t1.i][t1.j] == 'T'&&t1.c == 0){
					ans = tdis;
					break;
				}
			}
			//右
			if (dis[t1.i][t1.j][t1.c][rw(t1.w)] == INF){
				dis[t1.i][t1.j][t1.c][rw(t1.w)] = tdis;
				q.push(node(t1.i, t1.j, t1.c, rw(t1.w)));
				if (maps[t1.i][t1.j] == 'T'&&t1.c == 0){
					ans = tdis;
					break;
				}
			}
			//前进
			bool f = true;
			switch (t1.w)
			{
			case 0:
				--t1.i;
				if (t1.i < 1)f = false;
				break;
			case 1:
				++t1.j;
				if (t1.j > n)f = false;
				break;
			case 2:
				++t1.i;
				if (t1.i > m)f = false;
				break;
			case 3:
				--t1.j;
				if (t1.j < 1)f = false;
				break;
			default:
				break;
			}
			t1.c = nxtc(t1.c);
			if (f&&dis[t1.i][t1.j][t1.c][t1.w] == INF&&maps[t1.i][t1.j] != '#'){
				dis[t1.i][t1.j][t1.c][t1.w] = tdis;
				q.push(t1);
				if (maps[t1.i][t1.j] == 'T'&&t1.c == 0){
					ans = tdis;
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

