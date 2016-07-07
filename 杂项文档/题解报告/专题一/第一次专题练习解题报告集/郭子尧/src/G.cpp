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

int num[20];
bool vis[6000];
struct P {
    int mod, cnt;
    int ans[511];
};

int parse(char *s) {
    if ('0' <= s[0] && s[0] <= '9') return s[0] - '0';
    else return s[0] - 'A' + 10;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, c, m; scanf("%d", &t);
    P st;
    while (t --) {
        scanf("%d%d%d", &n, &c, &m);
        memset(vis, 0, sizeof vis);
        queue<P> q;
        bool zero = 0;
        char s[2];
        for (int i = 0; i < m; ++i) {
            scanf("%s", s);
            num[i] = parse(s);
        }
        sort(num, num + m);
        for (int i = 0; i < m; ++i) {
            if (num[i] == 0) {
                zero = 1;
                continue;
            }
            st.mod = num[i] % n;
            vis[st.mod] = 1;
            st.cnt = 1;
            st.ans[0] = num[i];
            q.push(st);
        }
        if (zero && n == 0) {
            printf("0\n");
            continue;
        }

        bool flag = 0;
        while (q.size()) {
            P cur = q.front(); q.pop();
            if (cur.mod == 0) {
                flag = 1;
                for (int i = 0; i < cur.cnt; ++i) {
                    if (cur.ans[i] > 9) printf("%c", cur.ans[i] - 10 + 'A');
                    else printf("%d", cur.ans[i]);
                }
                break;
            }
            int mod = cur.mod;
            if (++cur.cnt > 500) continue;
            for (int i = 0; i < m; ++i) {
                cur.mod = (cur.mod * c + num[i]) % n;
                if (!vis[cur.mod]) {
                    vis[cur.mod] = 1;
                    cur.ans[cur.cnt - 1] = num[i];
                    q.push(cur);
                }
                cur.mod = mod;
            }
        }
        if (!flag) printf("BOMB!!!");
        putchar('\n');
    }
    return 0;
}
