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

char *add = "ACGT";
char s[10][10];
int len[10], lens[10];
int n;

int check() {
    int ret = 0;
    for (int i = 0; i < 4; ++i) {
        int mx = 0;
        for (int j = 0; j < n; ++j) {
            int cnt = 0;
            for (int k = 0; k < len[j]; ++k) {
                if (s[j][k] == add[i]) ++cnt;
            }
            mx = max(mx, cnt);
        }
        ret += mx;
    }
    return ret;
}

void appd(int x) {
    for (int i = 0; i < n; ++i) {
        if (len[i] > 0 && s[i][len[i] - 1] == add[x]) --len[i];
    }
}

bool dfs(int up) {
    int judge = check();
    if (judge > up) return 0;
    if (judge == 0) return 1;
    int k[10];
    memcpy(k, len, sizeof len);
    for (int i = 0; i < 4; ++i) {
        memcpy(len, k, sizeof len);
        appd(i);
        if (dfs(up - 1)) return 1;
    }
    return 0;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        int dep = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%s", s[i]);
            lens[i] = strlen(s[i]);
            dep = max(dep, lens[i]);
        }
        for (int ans = dep; ; ++ans) {
            memcpy(len, lens, sizeof lens);
            if (dfs(ans)) {
                printf("%d\n", ans);
                //pr(imp)
                break;
            }
        }
    }
    return 0;
}
