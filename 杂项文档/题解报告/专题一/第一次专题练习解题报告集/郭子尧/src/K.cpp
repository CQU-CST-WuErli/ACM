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

int num[MAXN];

int MM(int len) {
    int i = 0, j = 1;
    while (i < len && j < len) {
        int k = 0;
        while (k < len && num[i + k] == num[j + k]) ++k;
        if (k == len) return min(i, j);
        if (num[i + k] > num[j + k]) i = max(i + k + 1, j + 1);
        else j = max(j + k + 1, i + 1);
    }
    return min(i, j);
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\apple\\Desktop\\in.txt", "r", stdin);
    #endif
    int n, t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &num[i]);
            num[i + n] = num[i];
        }
        int pos = MM(n);
        for (int i = pos; i < pos + n; ++i) {
            printf("%d", num[i]);
            if (i != pos + n - 1) putchar(' ');
            else putchar('\n');
        }
    }
    return 0;
}
