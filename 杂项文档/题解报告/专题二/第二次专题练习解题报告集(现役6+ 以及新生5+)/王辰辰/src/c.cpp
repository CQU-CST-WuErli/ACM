#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<utility>
#include<sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int inf = 0x3f3f3f3f;
const int maxn = 1005;
int A[400], n, m;
int num[6];
int dp[42][42][42][42];
int to[42][42][42][42];

int dfs(int a, int b, int c, int d) {
    if(dp[a][b][c][d] != -1) return dp[a][b][c][d];
    if(a == 0 && b == 0 && c == 0 && d == 0) return dp[a][b][c][d] = 0;
    int& ans = dp[a][b][c][d];
    if(a)
        ans = max(ans, dfs(a - 1, b, c, d) + A[n - to[a - 1][b][c][d]]);
    if(b)
        ans = max(ans, dfs(a, b - 1, c, d) + A[n - to[a][b - 1][c][d]]);
    if(c)
        ans = max(ans, dfs(a, b, c - 1, d) + A[n - to[a][b][c - 1][d]]);
    if(d)
        ans = max(ans, dfs(a, b, c, d - 1) + A[n - to[a][b][c][d - 1]]);
    return ans;
}

void init() {
    for(int i = 0; i <= 40; i++) {
        for(int j = 0; j <= 40; j++) {
            for(int ii = 0; ii <= 40; ii++) {
                for(int jj = 0; jj <= 40; jj++)
                    to[i][j][ii][jj] = i + 2*j + 3*ii + 4*jj;
            }
        }
    }
}
int main()
{
	#ifdef LOCAL
	freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
	#endif // LOCAL
	int t; scanf("%d", &t);
	init();
	while(t--) {
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
        memset(num, 0, sizeof(num));
        for(int i = 1; i <= m; i++) {
            int x; scanf("%d", &x); num[x]++;
        }
        memset(dp, -1, sizeof(dp));
        printf("%d\n", dfs(num[1], num[2], num[3], num[4]) + A[1]);
	}
	return 0;
}
