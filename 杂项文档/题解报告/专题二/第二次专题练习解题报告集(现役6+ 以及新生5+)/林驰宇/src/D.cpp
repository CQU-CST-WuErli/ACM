#include<stdio.h>
#include<string.h>
#define M 2005
int dp[M][6005], A[M], B[M];
void check(int &a, int b) {
    if(a == -1 || a > b)a = b;
}
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int cas, n, i, j, k,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
            scanf("%d %d", &A[i], &B[i]);
        memset(dp, -1, sizeof(dp));
        dp[0][3000] = 0;
        for(i = 1; i <= n; i++) {
            for(j = 0; j <= 6000; j++) {
                if(dp[i - 1][j] == -1)continue;
                int now = dp[i - 1][j];
                if(j <= 3000) {
                    int lessA = 3000 - j;
                    if(lessA >= A[i])check(dp[i][j + A[i]], dp[i - 1][j]);
                    else check(dp[i][j + A[i]], dp[i - 1][j] + A[i] - lessA);
                } else {
                    check(dp[i][3000 + A[i]], dp[i - 1][j] + A[i]);
                }
                if(j >= 3000) {
                    int lessB = j - 3000;
                    if(lessB >= B[i])check(dp[i][j - B[i]], dp[i - 1][j]);
                    else check(dp[i][j - B[i]], dp[i - 1][j] + B[i] - lessB);
                } else {
                    check(dp[i][3000 - B[i]], dp[i - 1][j] + B[i]);
                }
            }
        }
        int ans = -1;
        for(i = 0; i <= 6000; i++) {
            if(dp[n][i] == -1)continue;
            check(ans, dp[n][i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
