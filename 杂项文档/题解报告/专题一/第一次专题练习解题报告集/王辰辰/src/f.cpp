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
#include<time.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int inf = 0x3f3f3f3f;
const int maxn = 1005;
int dp[2050];
int tot,st;
int vt[2500];
bool leap[2500];
int work(int st){
    int ans = 0;
    while(st < 1000){
        st = st*2;
        ans++;
    }
    return ans;
}
void dfs(int st,int dep){
    if(work(st) + dep > 13)return;
    for(int i = 0;i < tot;i++){
        int now = st + vt[i];
        if(now > 1024 || leap[now])continue;
        dp[now] = min(dp[now],dep + 1);
        leap[now] = true;
        vt[tot++] = now;
        dfs(now,dep + 1);
        tot--;
        leap[now] = false;
    }
    for(int i = 0;i < tot;i++){
        int now = abs(st - vt[i]);
        if(now == 0 || now > 1024)continue;
        if(leap[now])continue;
        leap[now] = true;
        dp[now] = min(dp[now],dep + 1);
        vt[tot++] = now;
        dfs(now,dep + 1);
        tot--;
        leap[now] = false;
    }
    return;
}
int main()
{
	#ifdef LOCAL
	//freopen("C:\\Users\\巍巍\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\巍巍\\Desktop\\out.txt","w",stdout);
	#endif // LOCAL
    st = clock();
	for(int i = 0;i <= 1024;i++)
	    dp[i] = inf;
    memset(leap,false,sizeof(leap));
    leap[1] = true;
    vt[0] = 1;tot = 1;
    dp[1] = 0;
    dfs(1,0);
    dp[0] = 1;
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
	return 0;
}
