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
const int MAXN = 1e6 + 111;

struct Node {
    int nxt[2];
    int val;
    Node() {
        nxt[0] = nxt[1] = -1;
        val = 0;
    }
}trie[MAXN * 4];

int a, b, pos;

int extend() {
    ++pos;
    trie[pos] = Node();
    return pos;
}

void build(int x) {
    int p = 0;
    for (int i = 30; i >= 0; --i) {
        bool flag = x & (1 << i);
        if (trie[p].nxt[flag] == -1) {
            trie[p].nxt[flag] = extend();
        }
        p = trie[p].nxt[flag];
    }
    trie[p].val = x;
}

int query(int x) {
    int p = 0;
    for (int i = 30; i >= 0; --i) {
        bool flag = x & (1 << i);
        if (trie[p].nxt[1 - flag] != -1) p = trie[p].nxt[1 - flag];
        else p = trie[p].nxt[flag];
    }
    return x ^ trie[p].val;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t, n, m; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        pos = -1;
        extend();
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            build(a);
        }
        int ans = 0;
        for (int j = 0; j < m; ++j) {
            scanf("%d", &b);
            ans = max(ans, query(b));
        }
        printf("%d\n", ans);
    }
    return 0;
}
