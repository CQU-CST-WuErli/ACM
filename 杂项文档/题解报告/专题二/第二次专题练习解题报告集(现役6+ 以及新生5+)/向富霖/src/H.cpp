#include <set>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 15;
const int maxm = 1e6 + 15;
const int inf = 0x3f3f3f3f;
typedef long long ll;

int dp[maxn];
int pl[maxn], head, tail;
int a[105], m[105], n, k;

int main () {
#ifdef NEKO
    freopen("Nya.txt", "r", stdin);
#endif   
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; i++)
            scanf("%d", a + i);

        for(int i = 1; i <= n; i++)
            scanf("%d", m + i);

        memset(dp, 0, sizeof dp);
        dp[0] = 1;

        for(int i = 1; i <= n; i++) {
            ll maxx = (ll)a[i] * m[i];
            if(m[i] == 1) {
                for(int j = k; j >= a[i]; j--)
                    dp[j] |= dp[j - a[i]];
            }
            else if(maxx < k) {

                for(int j = 0; j < a[i]; j++) {
                    // clear dequeue
                    head = tail = 0;
                    for(int l = j; l <= k; l += a[i]) {
                        if(tail != head) { if (l - pl[head] > maxx) head++; }
                        if(dp[l]) { pl[tail] = l; tail++; }
                        else if(tail != head) dp[l] = 1;
                    }
                }
            }
            else {
                for(int j = a[i]; j <= k; j++)
                    dp[j] = max(dp[j], dp[j - a[i]]);
            }
        }
        if(dp[k]) puts("yes");
        else puts("no");
    }
    return 0;
}