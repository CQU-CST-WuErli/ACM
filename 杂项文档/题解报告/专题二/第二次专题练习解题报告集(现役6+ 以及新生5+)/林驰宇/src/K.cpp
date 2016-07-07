#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<climits>
#define LL long long
using namespace std;
const int M = 3e5 + 10;
const int N = 279935;
int dp[2][M][7];
pair<int, int> A[M][6];
int C[10][10];
char B[105];
int pow6[15], cnt[M][7];
vector<int>D;
void check(int n) {
    for(int j = 0; j < 6; j++) {
        int now = n % pow6[j + 1] / pow6[j];
        printf("%d ", now);
    }
    printf("\n");
}
bool _check(int x) {
    int pre = -1;
    for(int j = 0; j < 6; j++) {
        int now = x % pow6[j + 1] / pow6[j];
        if(now == pre && now) return 0;
        pre = now;
    }
    return 1;
}
void init() {
    pow6[0] = 1;
    for(int j = 1; j <= 6; j++) pow6[j] = pow6[j - 1] * 6;
    for(int j = 0; j < 6; j++) {
        for(int k = 0; k < 6; k++) {
            if(j) C[j][k] = C[j - 1][k] * 6 + k;
            else C[j][k] = k;
        }
    }
    memset(dp, -1, sizeof(dp));
    for(int j = 0; j <= N; j++) {
        if(_check(j)) {
            D.push_back(j);
        }
    }
    for(int j=0;j<D.size();j++){
        int k=D[j];
        int pre = -1;
        for(int i = 0; i < 6; i++) {
            int now = k % pow6[i + 1] / pow6[i];
            if(now) {
                if(now == pre) cnt[j][i] = cnt[j][i - 1] + 1;
                else pre = now, cnt[j][i] = 1;
            } else cnt[j][i] = 0;
        }
    }
}
void get_pre(int i, int &nxts, int &score, int now, int k,int *cnt) {
    int st = i - cnt[i - 1];
    int _now = k % pow6[i + 1] / pow6[i];
    if(_now) k -= _now * pow6[i];
    nxts = k - C[i - 1][now] + (st ? C[st - 1][now] : 0);
    nxts += now < 5 ? pow6[i] * (now + 1) : 0;
    score += (cnt[i - 1] + 1) * (1 << now);
}
void get_nxt(int i, int &nxts, int &score, int now, int k,int *cnt) {
    int ed = i + cnt[i + 1];
    int _now = k % pow6[i + 1] / pow6[i];
    if(_now) k -= _now * pow6[i];
    nxts = k - C[ed][now] + C[i][now] + (now < 5 ? pow6[i] * (now + 1) : 0);
    score += (cnt[i + 1] + 1) * (1 << now);
}
void _set(int t, int n, int k, int a, int b, int c1, int c2,int *cnt) {
    int _cnt = 1, pre = -1;
    for(int i = n - 1; i >= 0; i--) {
        int now = k % pow6[i + 1] / pow6[i];
        if(now) {
            if(now == pre) _cnt = _cnt + 1;
            else pre = now, _cnt = 1;
            continue;
        }
        now = t;
        int score = 0, nxts = 0;
        if(i > 0 && i < n - 1) {
            int nxt = k % pow6[i + 2] / pow6[i + 1];
            int _pre = k % pow6[i] / pow6[i - 1];
            if(now == _pre) {
                if(nxt != _pre) {
                    get_pre(i, nxts, score, now, k,cnt);
                    if(nxt == now + 1) {
                        get_nxt(i, nxts, score, nxt, nxts,cnt);
                    }
                } else {
                    int st = i - cnt[i - 1];
                    int ed = i + cnt[i + 1];
                    nxts = k - C[ed][now] + (st ? C[st - 1][now] : 0);
                    nxts += now * pow6[i];
                    if(now < 5) nxts += (now + 1) * pow6[i];
                    score = (ed - st + 1) * (1 << now);
                }
            } else if(now == nxt) {
                get_nxt(i, nxts, score, nxt, k,cnt);
                if(_pre == now + 1) {
                    get_pre(i, nxts, score, _pre, nxts,cnt);
                }
            } else nxts = k + now * pow6[i];
        } else if(i == n - 1) {
            int _pre = k % pow6[i] / pow6[i - 1];
            if(now == _pre) get_pre(i, nxts, score, now, k,cnt);
            else nxts = k + now * pow6[i];
        } else if(i == 0) {
            int nxt = k % pow6[i + 2] / pow6[i + 1];
            if(now == nxt) get_nxt(i, nxts, score, now, k,cnt);
            else nxts = k + now * pow6[i];
        }
        dp[b][nxts][c2] = max(dp[b][nxts][c2], dp[a][k][c1] + score);
        pre = -1; _cnt = 0;
    }
}
int main() {
    init();
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(dp, -1, sizeof(dp));
        int n, m;
        scanf("%d%d", &n, &m);
        scanf("%s", B + 1);
        int a = 0, b = 1;
        dp[0][0][0] = 0;
        int ans = 0;
        for(int j = 1; j <= m; j++) {
            int t = B[j] - '0';
            memset(dp[b], -1, sizeof(dp[b]));
            for(int q = 0; q < D.size(); q++) {
                int k = D[q];
                if(k >= pow6[n]) break;
                for(int c = 0; c <= 5; c++) {
                    if(dp[a][k][c] == -1) continue;
                    if(c == 0) dp[b][k][t] = max(dp[b][k][t], dp[a][k][c]);
                    _set(t, n, k, a, b, c, c,cnt[q]);
                    if(c) _set(c, n, k, a, b, c, t,cnt[q]);
                }
            }
            if(j==m){
                for(int q = 0; q < D.size(); q++) {
                    int k = D[q];
                    if(k >= pow6[n]) break;
                    for(int c = 1; c <= 5; c++) {
                        if(dp[b][k][c] == -1) continue;
                        _set(c, n, k, b, b, c, 0,cnt[q]);
                    }
                }
            }
            for(int q = 0; q < D.size(); q++) {
                int k = D[q];
                if(k >= pow6[n]) break;
                for(int c = 0; c <= 5; c++) {
                    ans=max(ans,dp[b][k][c]);
                }
            }
            swap(a, b);
        }
        for(int j = 0; j <= N; j++)
            for(int k = 0; k <= 5; k++)
                ans = max(ans, dp[a][j][k]);
        printf("%d\n", ans);
    }
    return 0;
}
