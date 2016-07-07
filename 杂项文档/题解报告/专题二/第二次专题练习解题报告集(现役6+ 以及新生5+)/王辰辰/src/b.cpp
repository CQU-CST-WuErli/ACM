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
const int maxn = 200100;
ll dp[maxn], x[maxn];
int deq[maxn];
int up(int a, int b) {
    int ans1 = dp[b] + x[b + 1] * x[b + 1];
    int ans2 = dp[a] + x[a + 1] * x[a + 1];
    return ans1 - ans2;
}

int down(int a, int b) {
    return 2*(x[b + 1] - x[a + 1]);
}
int main()
{
	#ifdef LOCAL
	freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
	#endif // LOCAL
	int t; scanf("%d", &t);
	while(t--) {
        int n, w;
        scanf("%d %d", &n, &w);
        x[0] = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d", &x[i]);
        sort(x + 1, x + 1 + n);
        int head, tail;
        head = tail = 0;
        deq[tail++] = 0;
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            while(head < tail - 1 && up(deq[head], deq[head + 1]) <=
                                     down(deq[head], deq[head + 1]) * x[i])
                head++;
            int k = deq[head];
            dp[i] = dp[k] + w + (x[i] - x[k + 1]) * (x[i] - x[k + 1]);
            //dp[i] = min(dp[i], w + (x[i] - x[1]) * (x[i] - x[1]));
            //cout << i << " " << k << " " << dp[i] << endl;
            while(head < tail - 1 && up(deq[tail - 2], deq[tail - 1]) * down(deq[tail - 2], i) >=
                                     up(deq[tail - 2], i) * down(deq[tail - 2], deq[tail - 1]))
                tail--;
            deq[tail++] = i;
        }
        printf("%lld\n", dp[n]);
	}
	return 0;
}
