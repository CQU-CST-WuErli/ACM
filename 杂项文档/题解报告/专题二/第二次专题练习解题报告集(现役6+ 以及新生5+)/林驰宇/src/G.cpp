#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<list>
#include<iomanip>
#define LL long long
#define double long double
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
using namespace std;
const int INF = 0x3f3f3f3f;
int dp[15][1 << 15];
vector<int>A;
int n, leaf;
bool check() {
    memset(dp, 63, sizeof(dp));
    for(int j = 0; j < n; j++) {
        if(A[j] >= 3) dp[1][1 << j] = A[j];
    }
    for(int j = 0; j < (1 << n); j++) {
        //printf("%d\n",j);
        for(int k = 0; k < n; k++) {
            for(int i = j & (j - 1); i; i = (i - 1)&j) {
                if(dp[k][i] == INF || dp[1][j ^ i] == INF)continue;
                dp[k + 1][j] = min(dp[k + 1][j], dp[k][i] + dp[1][j ^ i]);
            }
            if(!((1 << k)&j)) {
                for(int i = 0; i < n; i++) {
                    if(A[k] - 1 < dp[i][j]) continue;
                    if(A[k] - 1 - dp[i][j] + i < 2) continue;
                    dp[1][j | 1 << k] = A[k];
                }
            }
        }
    }
    //printf("%d\n",n);
    //printf("%d\n", dp[1][(1 << n) - 1]);
    return dp[1][(1 << n) - 1] != INF;
}
int main() {
//    int T;
//    scanf("%d", &T);
//    while(T--) {
        scanf("%d", &n);
        leaf = 0;
        A.clear();
        for(int j = 0; j < n; j++) {
            int a;
            scanf("%d", &a);
            if(a == 1) leaf++;
            else A.push_back(a);
        }
        sort(A.begin(), A .end()); n = A.size();
        if(n + leaf == 1) printf("%s\n", leaf == 1 ? "YES" : "NO");
        else if (n==0) printf("NO\n");
        else if(n >= 15) {
            printf("NO\n");
        } else printf("%s\n", (check() && A[n - 1] == n + leaf) ? "YES" : "NO");
//    }
    return 0;
}
