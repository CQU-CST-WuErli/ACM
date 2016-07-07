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
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 6e2 + 111;

int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int dis[MAXN][MAXN];
char mp[MAXN][MAXN];

struct P {
    int x, y, dis;
    P(int a, int b, int c):x(a), y(b), dis(c){}
};

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    int n, m, k;
    ++t;
    while (t --) {
        scanf("%d%d%d", &n, &m, &k);
        int ex, ey;
        queue<P> q;
        for (int i = 0; i < n; ++i) {
            scanf("%s", mp[i]);
            for (int j = 0; j < m; ++j) {
                dis[i][j] = INF;
                if (mp[i][j] == 'S') {
                    dis[i][j] = 0;
                    q.push(P(i, j, 0));
                }
            }
        }
        int ans = INF;
        while (q.size()) {
            P cur = q.front(); q.pop();
            if (dis[cur.x][cur.y] + 1 == k) continue;
            for (int i = 0; i < 4; ++i) {
                int nx = cur.x + dir[i][0], ny = cur.y + dir[i][1];
                if (0 <= nx && nx < n && 0 <= ny && ny < m && mp[nx][ny] != 'W') {
                    if (mp[nx][ny] == 'E') ans = min(ans, cur.dis + 1);
                    if (dis[cur.x][cur.y] + 1 < dis[nx][ny]) {
                        dis[nx][ny] = dis[cur.x][cur.y] + 1;
                        if (mp[nx][ny] == 'R') dis[nx][ny] = 0;
                        q.push(P(nx, ny, cur.dis + 1));
                    }
                }
            }
        }
        if (ans == INF) printf("Poor RunningPhoton!\n");
        else printf("%d\n", ans);
    }
    return 0;
}
