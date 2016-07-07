#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<list>
#define LL long long
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
using namespace std;
const int M = 605, INF = 0x3f3f3f3f;
char mp[M][M];
int id[M][M];
vector<pair<int, int> >edge[M];
int mark[M][M];
int dis[M];
bool _mark[M];
int n, m, K;
int rx[] = {1, 0, -1, 0};
int ry[] = {0, 1, 0, -1};
bool check(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && mp[x][y] != 'W';
}
void bfs(int x, int y, int z) {
    queue<pair<int, int> >Q;
    memset(mark, -1, sizeof(mark));
    mark[x][y] = K;
    Q.push(make_pair(x, y));
    while(!Q.empty()) {
        pair<int, int> now = Q.front(); Q.pop();
        int x = now.first, y = now.second;
        for(int j = 0; j < 4; j++) {
            int x1 = x + rx[j], y1 = y + ry[j];
            //printf("%d %d\n",x1,y1);
            if(!check(x1, y1) || mark[x1][y1] != -1 || mark[x][y] == 1) continue;
            //printf("%d %d\n",x1,y1);
            if(mp[x1][y1] == 'R'
                    || mp[x1][y1] == 'E') edge[z].push_back(make_pair(id[x1][y1],
                                K - mark[x][y] + 1));
            mark[x1][y1] = mark[x][y] - 1;
            Q.push(make_pair(x1, y1));
        }
    }
}
void spfa(int s, int t) {
    queue<int>Q;
    memset(dis, 63, sizeof(dis));
    memset(_mark, 0, sizeof(_mark));
    dis[s] = 0;
    Q.push(s);
    while(!Q.empty()) {
        int now = Q.front(); Q.pop();
        _mark[now] = 0;
        for(int j = 0; j < edge[now].size(); j++) {
            int to = edge[now][j].first, v = edge[now][j].second;
            if(dis[to] > dis[now] + v) {
                dis[to] = dis[now] + v;
                if(!_mark[to]) {
                    _mark[to] = 1;
                    Q.push(to);
                }
            }
        }
    }
}
int main() {
    int T;
    scanf("%d", &T);
    T++;
    while(T--) {
        scanf("%d%d%d", &n, &m, &K);
        int cnt = 1;
        for(int j = 0; j <= 151; j++) edge[j].clear();
        for(int j = 1; j <= n; j++) {
            scanf("%s", mp[j] + 1);
            for(int k = 1; k <= m; k++) {
                //printf("%d %d %c\n",j,k,mp[j][k]);
                if(mp[j][k] == 'R') id[j][k] = cnt++;
                if(mp[j][k] == 'S') id[j][k] = 0;
                if(mp[j][k] == 'E') id[j][k] = 151;
            }
            //printf("%s\n",mp[j]+1);
        }
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= m; k++) {
                if(mp[j][k] == 'R' || mp[j][k] == 'S') {
                    //printf("%d %d\n",j,k);
                    bfs(j, k, id[j][k]);
                }
            }
        }
        //printf("1\n");
        spfa(0, 151);
        if(dis[151] == INF) printf("Poor RunningPhoton!\n");
        else printf("%d\n", dis[151]);
    }
    return 0;
}
