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
const int MAXN = 2e5 + 111;

int mp[MAXN];
char s[MAXN], ma[MAXN];
int pos = 0;
struct Trie {
    int nxt[2];
    int val;
    Trie() {
        nxt[0] = nxt[1] = -1;
        val = 0;
    }
}trie[MAXN * 20];

int manacher(int len) {
    int l = 0;
    ma[l++] = '$';
    ma[l++] = '#';
    for (int i = 0; i < len; ++i) {
        ma[l++] = s[i];
        ma[l++] = '#';
    }
    ma[l] = 0;

    int mx = 0, id = 0, ret = 0;

    for (int i = 0; i < l; ++i) {
        mp[i] = mx > i ? min(mx - i, mp[2 * id - i]) : 1;
        while (ma[i - mp[i]] == ma[i + mp[i]]) ++mp[i];
        if (i + mp[i] > mx) {
            mx = mp[i] + i;
            id = i;
        }
        ret = max(ret, mp[i] - 1);
    }
    return ret;
}

ll quick_pow(ll x, ll p, int mod) {
    ll ret = 1;
    while (p) {
        if (p & 1) {
            ret = (ret * x) % mod;
        }
        x = (x * x) % mod;
        p /= 2;
    }
    return ret;
}

int add() {
    ++pos;
    trie[pos] = Trie();
    return pos;
}

int query(int x) {
    int rt = 0;
    for (int i = 18; i >= 0; --i) {
        bool flag = (x & (1 << i));
        if (trie[rt].nxt[1 - flag] != -1) rt = trie[rt].nxt[1 - flag];
        else rt = trie[rt].nxt[flag];
    }
    return x ^ trie[rt].val;
}

void inser(int x) {
    int rt = 0;
    for (int i = 18; i >= 0; --i) {
        bool flag = (x & (1 << i));
        if (trie[rt].nxt[flag] == -1) {
            trie[rt].nxt[flag] = add();
        }
        rt = trie[rt].nxt[flag];
    }
    trie[rt].val = x;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    while (t --) {
        scanf("%s", s);
        ll len = strlen(s);
        ll pp = len * len * len;
        ll mz = manacher(len);
        mz = quick_pow(mz, pp, mz/3*5+1) + mz*4/5;
        int ans = 0, sum = 0;
        pos = 0;
        trie[0] = Trie();
        inser(0);
        for (int i = 0; i < len; ++i) {
            sum ^= (mp[(i + 1) * 2] - 1);
            ans = max(ans, query(sum));
            inser(sum);
        }
        //pr(ans);
        if (mz > ans) printf("liujc\n");
        else printf("luoxinchen\n");
    }
    return 0;
}
