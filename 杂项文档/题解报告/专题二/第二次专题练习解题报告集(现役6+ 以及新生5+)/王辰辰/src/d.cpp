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
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f;
const int maxn = 2010;
struct Node {
    int a, b;
}node[maxn];

int dp[2][2][3100];

int main()
{
	#ifdef LOCAL
	freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
	#endif // LOCAL
	int t; scanf("%d", &t);
	while(t--) {
        int n; scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d %d", &node[i].a, &node[i].b);
        for(int i = 0; i < 2; i++)
            for(int j = 0; j <= 3000; j++)
                dp[0][i][j] = dp[1][i][j] = inf;
        for(int i = 0; i < 2; i++)
            dp[0][i][0] = 0;
        int now = 1, pre = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 2; j++) {
                int a, b;
                if(j == 0) {
                    a = node[i].a; b = node[i].b;
                }
                else {
                    a = node[i].b; b = node[i].a;
                }
                for(int k = 0; k <= 3000; k++) {
                    if(dp[pre][j][k] == inf) continue;
                    dp[now][j][a] = min(dp[now][j][a], dp[pre][j][k] + k);
                }
                for(int k = 0; k <= 3000; k++) {
                    if(dp[pre][j][k] == inf) continue;
                    if(k > b) dp[now][j][k - b] = min(dp[now][j][k - b], dp[pre][j][k] + b);
                    else if(k == b) {
                        dp[now][j][0] = min(dp[now][j][0], dp[pre][j][k] + k);
                        dp[now][1 - j][0] = min(dp[now][1 - j][0], dp[now][j][0]);
                    }
                    else dp[now][1 - j][b - k] = min(dp[now][1 - j][b - k], dp[pre][j][k] + k);
                }
            }
            swap(now, pre);
            for(int j = 0; j < 2; j++)
                for(int k = 0; k <= 3000; k++)
                    dp[now][j][k] = inf;
            //dp[now][0][0] = dp[now][1][0] = 0;
        }
        int ans = inf;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j <= 3000; j++)
                ans = min(ans, j + dp[pre][i][j]);
        printf("%d\n", ans);
	}
	return 0;
}
