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
const int MAXN = 5e6 + 111;

char s[MAXN], a[MAXN], b[MAXN];
int nxt[MAXN];

void getNext(int len) {
    nxt[0] = -1;
    int k = -1;
    for (int i = 0; i < len;) {
        while (k != -1 && a[i] != a[k]) k = nxt[k];
        ++i;
        ++k;
        if (a[i] != a[k]) nxt[i] = k;
        else nxt[i] = nxt[k];
    }
}

void kmp() {
    int i = 0, j = 0;
    int lens = strlen(s), lena = strlen(a);
    getNext(lena);
    int pos = 0;
    while (i < lens) {
        while (j != -1 && s[i] != a[j]) j = nxt[j];
        ++i;
        ++j;
        if (j == lena) {
            for (int k = pos; k < i - lena; ++k) putchar(s[k]);
            printf("%s", b);
            j = 0;
            pos = i;
        }
    }
    for (int k = pos; k < lens; ++k) putchar(s[k]);
    putchar('\n');
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int t; scanf("%d", &t);
    while (t --) {
        scanf("%s%s%s", s, a, b);
        kmp();
    }
    return 0;
}
