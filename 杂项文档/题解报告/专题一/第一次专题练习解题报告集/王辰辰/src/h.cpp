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
int ans,n;
int len[20];
int dp[2000000],pre[2000000];
char ss[20][20];
char dir[4] = {'A','C','G','T'};
int dfs(int s){
    if(dp[s] != -1)return dp[s];
    if(s == 0)return dp[s] = 0;
    int num[20],e[20];
    int temp = s;
    dp[s] = inf;
    for(int i = n - 1;i >= 0;i--){
        num[i] = temp%6;
        temp = temp/6;
    }
    for(int i = 0;i < 4;i++){
        bool ok = false;
        for(int j = 0;j < n;j++){
            if(num[j] && ss[j][len[j] - num[j]] == dir[i]){
                ok = true;
                e[j] = num[j] - 1;
            }
            else{
                e[j] = num[j];continue;
            }
        }
        if(!ok)continue;
        int now = 0;
        for(int j = 0;j < n;j++)
            now = now*6 + e[j];
        if(dp[s] > dfs(now) + 1){
            dp[s] = dfs(now) + 1;
            pre[s] = now;
        }
    }
    return dp[s];
}
int main()
{
	#ifdef LOCAL
	freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
	#endif // LOCAL
	int t;
	scanf("%d",&t);
	while(t--){
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
            scanf("%s",ss + i);
        ans = 0;
        int s = 0;
        for(int i = 0;i < n;i++){
            len[i] = strlen(ss[i]);
            s = s*6 + len[i];
            ans = ans + len[i];
        }
        memset(dp,-1,sizeof(dp));
        dfs(s);
        printf("%d\n",dp[s]);
	}
	return 0;
}
