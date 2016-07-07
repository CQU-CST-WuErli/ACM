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
const int maxn = 100100;
int dp[maxn], a[105], m[105];
int main()
{
	#ifdef LOCAL
	freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
	#endif // LOCAL
	int t; scanf("%d", &t);
	while(t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++) scanf("%d", &m[i]);
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= k; j++) {
                if(dp[j] >= 0)
                    dp[j] = m[i];
                else if(j < a[i] || dp[j - a[i]] <= 0)
                    dp[j] = -1;
                else
                    dp[j] = dp[j - a[i]] - 1;
            }
        }
        if(dp[k] < 0)
            printf("no\n");
        else
            printf("yes\n");
	}
	return 0;
}
