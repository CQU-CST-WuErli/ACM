//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d", &a)
#define SII(a,b) scanf("%d%d", &a, &b)
#define SIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n, m;
int dir[8][2] = {1,2,-1,2,2,1,2,-1,1,-2,-1,-2,-2,1,-2,-1};
char mp[110][110];

struct P
{
	int x,y;
}st, ed;
struct sta
{
	int x, y, step;
	sta(int x,int y):x(x),y(y){}
};
int vis[110][110];
int dis[110][110];

int bfs() {

	CLR(vis);
	CLR(dis);
	queue<sta> q;
	q.push(sta(st.x,st.y));
	vis[st.x][st.y] = 1;
	dis[st.x][st.y] = 0;
	while(q.size()) {
	    sta now = q.front(); q.pop();
	    // vis[now.x][now.y] = 0;
	    // cout << now.x << ' ' << now.y << endl;
	    if (now.x == ed.x && now.y == ed.y) return dis[now.x][now.y];
	    for (int i = 0; i < 8; i++) {
	    	int tx = now.x + dir[i][0], ty = now.y + dir[i][1];
	    	if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
	    	if (vis[tx][ty]) continue;
	    	if (mp[tx][ty] == '#') continue;
	    	if ((i == 0 || i == 1) && mp[now.x][now.y + 1] == '#') continue;
	    	if ((i == 2 || i == 3) && mp[now.x + 1][now.y] == '#') continue;
	    	if ((i == 4 || i == 5) && mp[now.x][now.y - 1] == '#') continue;
	    	if ((i == 6 || i == 7) && mp[now.x - 1][now.y] == '#') continue;
	    	// if (dis[tx][ty] > dis[now.x][now.y] + 1) {
	    	// 	dis[tx][ty] = dis[now.x][now.y] + 1;
	    	// 	if (!vis[tx][ty]) {
	    	// 		q.push(sta(tx,ty));
	    	// 		vis[tx][ty] = 1;
	    	// 	}
	    	// }
			dis[tx][ty] = dis[now.x][now.y] + 1;
			vis[tx][ty] = 1;
			q.push(sta(tx,ty));
	    }
	}
	return INF_INT;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SII(n, m)==2) {
    	CLR(mp);
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= m; j++) {
    			cin >> mp[i][j];
    			if (mp[i][j] == 's') {
    				st.x = i, st.y = j;
    			}
    			if (mp[i][j] == 'e') {
    				ed.x = i, ed.y = j;
    			}
    		}
    	}
    	int ans = bfs();
    	if (ans >= INF_INT) puts("-1");
    	else cout << ans << endl;
    }
	return 0;
}