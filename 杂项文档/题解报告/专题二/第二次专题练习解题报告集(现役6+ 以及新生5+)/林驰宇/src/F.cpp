#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
const long long INF = -1e18;
struct node {
    long long a, b, t;
} A[305];
long long dp[2][150005];
node Q[150005];
//long long mymax(long long a,long long b){
int main() {
    int T;
    scanf("%d",&T);
    while(T--){
        memset(dp, 0, sizeof(dp));
        int n, m, d;
        scanf("%d%d%d", &n, &m, &d);
        int j, k;
        for(j = 1; j <= m; j++) scanf("%d %d %d", &A[j].a, &A[j].b, &A[j].t);
        for(j = 0; j < 2; j++) {
            for(k = 1; k <= n; k++) {
                dp[j][k] = INF;
            }
        }
        for(j = 1; j <= n; j++) {
            dp[0][j] = A[1].b - abs(A[1].a - j);
            //printf("%d\n",dp[0][j]);
        }
        int a = 0, b = 1;
        for(j = 2; j <= m; j++) {
            a = !a; b = !b;
            //printf("%d %d\n",a,b);
            for(k = 1; k <= n; k++) dp[a][k] = 1LL * INF;
            memset(Q, 0, sizeof(Q));
            int L = 1, R = 0;
            //printf("%d\n",dp[j][1]);
            for(k = 1; k <= n; k++) {
                while(L <= R && k - Q[L].a > d * (A[j].t - A[j - 1].t)) L++;
                if(L <= R) dp[a][k] = max(dp[a][k], Q[L].b + (A[j].b - abs(A[j].a - k)));
                //if(j==2) printf("%d %d %d\n",L,R,Q[L].b);
                while(L <= R && dp[b][k] > Q[R].b) R--;
                Q[++R].a = k;
                Q[R].b = dp[b][k];
            }
            memset(Q, 0, sizeof(Q));
            L = 1; R = 0;
            for(k = n; k >= 1; k--) {
                while(L <= R && Q[L].a - k > d * (A[j].t - A[j - 1].t)) L++;
                if(L <= R) dp[a][k] = max(dp[a][k], Q[L].b + (A[j].b - abs(A[j].a - k)));
                while(L <= R && dp[b][k] > Q[R].b) R--;
                Q[++R].a = k;
                Q[R].b = dp[b][k];
            }
            for(k = 1; k <= n;
                    k++) dp[a][k] = max(dp[b][k] + (A[j].b - abs(A[j].a - k)), dp[a][k]);
            //for(k=1;k<=n;k++) printf("%d\n",dp[a][k]);
            //printf("\n");
        }
        long long maxx = INF;
        for(j = 1; j <= n; j++) if(dp[a][j] > maxx) maxx = dp[a][j];
        cout << maxx << endl;
    }
    return 0;
}
