#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<utility>
#include<sstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f;
const int maxn = 1005;

int p[505], kind[505], num[505];
bool leap[505][505];
bool vis[505];

void init(int n) {
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        kind[i] = 1;
        num[i] = 1;
    }
}

int find(int x) {
    if(x == p[x]) return x;
    int fx = find(p[x]);
    if(kind[x] == kind[p[x]]) kind[x] = 1;
    else kind[x] = 0;
    p[x] = fx;
    return p[x];
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
    freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
    #endif // LOCAL
    int t; scanf("%d", &t);
    while(t--) {
        memset(leap, false, sizeof(leap));
        int n, m; scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; i++) {
            int u, v; scanf("%d%d", &u, &v);
            leap[u][v] = leap[v][u] = true;
        }
        init(n);
        bool ok = true;
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                if(leap[i][j]) continue;
                int x = find(i);
                int y = find(j);
                //cout<<i<<" "<<j<<endl;
                //cout<<i<<" "<<x<<" "<<kind[i]<<endl;
                //cout<<j<<" "<<y<<" "<<kind[j]<<endl;
                if(x == y) {
                    if(kind[i] == kind[j]) ok = false;
                }
                else {
                    p[x] = y;
                    num[y] += num[x];
                    kind[x] = ((0 + kind[j]) % 2 - kind[i] + 2) % 2;
                }
            }
        }
        if(ok) {
            int ans = 0;
            memset(vis, false, sizeof(vis));
            for(int i = 1; i <= n; i++) {
                int x = find(i);
                if(vis[x]) continue;
                vis[x] = true;
                if(num[x] > 1) ans++;
            }
            if(ans >= 2) ok = false;
            for(int i = 1; i <= n; i++) {
                for(int j = i + 1; j <= n; j++) {
                    if(leap[i][j]) {
                        int x = find(i);
                        int y = find(j);
                        if(x == y && kind[i] != kind[j]) ok = false;
                    }
                }
            }
            if(ok)
                printf("Yes\n");
            else
                printf("No\n");
        }
        else
            printf("No\n");
    }
    return 0;
}
