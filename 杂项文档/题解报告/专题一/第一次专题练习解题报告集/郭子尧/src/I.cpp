#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#define ll long long
#define pii pair<int, int>
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 111;

struct P {
    int x, y, c, dir;
    P(int a, int b, int _c, int d):x(a), y(b), c(_c), dir(d){}
};
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int dis[MAXN][MAXN][5][4];
char mp[MAXN][MAXN];

int getadd(int a, int b) {
    if (a == b) return 1;
    else if ((a + 2) % 4 == b) return 3;
    else return 2;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    while (t --) {
        int n, m, ex, ey;
        scanf("%d%d", &n, &m);
        queue<P> q;
        memset(dis, 0x3f, sizeof dis);
        for (int i = 0; i < n; ++i) {
            scanf("%s", mp[i]);
            for (int j = 0; j < m; ++j) {
                if (mp[i][j] == 'S') {
                    q.push(P(i, j, 0, 0));
                    dis[i][j][0][0] = 0;
                }
                if (mp[i][j] == 'T') {
                    ex = i, ey = j;
                }
            }
        }
        while (q.size()) {
            P u = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = u.x + dir[i][0], ny = u.y + dir[i][1];
                int add = getadd(u.dir, i);
                if (0 <= nx && nx < n && 0 <= ny && ny < m && mp[nx][ny] != '#') {
                    if (dis[nx][ny][(u.c + 1) % 5][i] > dis[u.x][u.y][u.c][u.dir] + add) {
                        dis[nx][ny][(u.c + 1) % 5][i] = dis[u.x][u.y][u.c][u.dir] + add;
                        q.push(P(nx, ny, (u.c + 1) % 5, i));
                    }
                }
            }
        }
        int ans = INF;
        for (int i = 0; i < 4; ++i) ans = min(ans, dis[ex][ey][0][i]);
        if (ans == INF) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}
