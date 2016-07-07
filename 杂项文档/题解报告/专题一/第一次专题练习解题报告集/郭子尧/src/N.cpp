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

const int INF = 0x7f7f7f7f;
const int MAXN = 111;
const int mod = 10007;

int dp[MAXN][MAXN * 60];

struct Trie
{
    int next[8000][30],fail[8000],end[8000];
    bool isend[8000];
    int root,L;
    int newnode()
    {
        for(int i = 0;i < 26;i++)
            next[L][i] = -1;
        isend[L] = 0;
        end[L++] = 0;
        return L-1;
    }

    void init()
    {
        L = 0;
        root = newnode();
    }

    void insert(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][buf[i] - 'A'] == -1)
                next[now][buf[i] - 'A'] = newnode();
            now = next[now][buf[i] - 'A'];
        }
        isend[now] = 1;
        end[now]++;
    }

    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < 26;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while( !Q.empty() )
        {
            int now = Q.front();
            if (isend[fail[now]]) isend[now] = 1;
            Q.pop();
            for(int i = 0;i < 26;i++) {
                if(next[now][i] == -1) {
                    next[now][i] = next[fail[now]][i];
                }
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];

                    Q.push(next[now][i]);
                }
            }
        }
    }

    int query(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        int res = 0;
        for(int i = 0;i < len;i++)
        {
            now = next[now][buf[i] - 'A'];
            int temp = now;
            while( temp != root )
            {
                res += end[temp];
                temp = fail[temp];
            }
        }
        return res;
    }
    void debug()
    {
        for(int i = 0;i < L;i++)
        {
            printf("id = %3d,fail = %3d,end = %3d,chi = [",i,fail[i],end[i]);
            for(int j = 0;j < 26;j++)
                printf("%2d",next[i][j]);
            printf("]\n");
        }
    }
};

char buf[200];
Trie ac;

ll quickpow(ll x, ll p) {
    ll ret = 1;
    while (p) {
        if (p & 1) ret *= x, ret %= mod;
        x *= x;
        x %= mod;
        p >>= 1;
    }
    return ret;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, m, t; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        ac.init();
        while (n --) {
            scanf("%s", buf);
            ac.insert(buf);
        }
        ac.build();
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < ac.L; ++j) {
                for (int k = 0; k < 26; ++k) {
                    if (ac.isend[j]) continue;
                    int nx = ac.next[j][k];
                    if (ac.isend[nx]) continue;
                    dp[i + 1][nx] += dp[i][j];
                    dp[i + 1][nx] %= mod;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < ac.L; ++i) {
            if (!ac.isend[i]) {
                ans += dp[m][i];
                ans %= mod;
            }
        }
        ans = ((quickpow(26, m) - ans) % mod + mod) % mod;
        printf("%d\n", ans);
    }
    return 0;
}
