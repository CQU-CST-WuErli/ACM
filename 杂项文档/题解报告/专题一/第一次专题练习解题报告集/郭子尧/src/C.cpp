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
#define lowbit(x) (x & (-x))
#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';
using namespace std;

struct P {
    char ans[111];
    int cnt;
    int mod;
};
bool vis[500];

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    freopen("C:\\Users\\apple\\Desktop\\out.txt", "w", stdout);
    #endif
    int n;
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        queue<P> q;
        memset(vis, 0, sizeof vis);
        P st;
        st.cnt = 1;
        st.ans[0] = '1';
        st.mod = 1 % n;
        q.push(st);

        while (q.size()) {
            P cur = q.front(); q.pop();
            if (cur.mod == 0) {
                for (int i = 0; i < cur.cnt; ++i) printf("%c", cur.ans[i]);
                putchar('\n');
                break;
            }
            vis[cur.mod] = 1;

            cur.cnt = cur.cnt + 1;
            cur.ans[cur.cnt - 1] = '0';
            cur.mod = (cur.mod * 10) % n;
            if (!vis[cur.mod])
                q.push(cur);
            cur.ans[cur.cnt - 1] = '1';
            cur.mod = (cur.mod + 1) % n;
            if (!vis[cur.mod])
                q.push(cur);
        }
    }
    return 0;
}
