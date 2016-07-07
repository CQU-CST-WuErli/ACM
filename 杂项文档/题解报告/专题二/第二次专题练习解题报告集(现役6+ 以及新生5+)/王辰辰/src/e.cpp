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
const int maxn = 500100;
int a[maxn];
int dp[2][maxn];
int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
    #endif // LOCAL
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int sum = 0;
        for(int i = 1;i <= n;i++){
            scanf("%d",&a[i]);
            sum = sum + a[i];
        }
        sum = sum/2;
        memset(dp,-1,sizeof(dp));
        dp[0][0] = 0;
        int now = 1,pre = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 0;j <= sum;j++){
                if(dp[pre][j] == -1)continue;
                dp[now][j] = max(dp[now][j],dp[pre][j]);
                int temp = j + a[i];
                if(temp <= sum)
                    dp[now][temp] = max(dp[now][temp],dp[pre][j] + a[i]);
                if(j >= a[i])
                    dp[now][j - a[i]] = max(dp[now][j - a[i]],dp[pre][j] + a[i]);
                else
                    dp[now][a[i] - j] = max(dp[now][a[i] - j],dp[pre][j] + a[i]);
            }
            swap(now,pre);
            //memset(dp[now],0,sizeof(dp[now]));
        }
        if(dp[pre][0] == 0)
            printf("GG\n");
        else
            printf("%d\n",dp[pre][0]/2);
    }
    return 0;
}
