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
typedef pair<int,ll> P;
const int inf = 0x3f3f3f3f;
const int maxn = 1005;
struct Node{
    int a,b;
    ll t;
}node[400];
bool cmp(Node a,Node b){
    return a.t < b.t;
}
ll dp[2][150100];
P deq[150100];
int main()
{
	#ifdef LOCAL
	freopen("C:\\Users\\¦±¦±\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\¦±¦±\\Desktop\\out.txt","w",stdout);
	#endif // LOCAL
	int t; scanf("%d",&t);
	while(t--){
	    int n,m,d;
	    scanf("%d%d%d",&n,&m,&d);
	    for(int i = 1;i <= m;i++)
	        scanf("%d%d%lld",&node[i].a,&node[i].b,&node[i].t);
        //sort(node + 1,node + 1 + m,cmp);

        /*for(int i = 1;i <= m;i++)
            cout<<node[i].a<<" "<<node[i].b<<" "<<node[i].t<<endl;*/

        memset(dp,0,sizeof(dp));
        int now = 1,pre = 0;
        for(int i = 0;i <= n;i++)
            dp[0][i] = dp[1][i] = -inf;
        for(int i = 1;i <= n;i++)
            dp[0][i] = node[1].b - abs(node[1].a - i);
        int head,tail;
        for(int i = 2;i <= m;i++){
            ll len = (node[i].t - node[i - 1].t)*d;
            head = tail = 0;
            for(int j = 1;j <= n;j++){
                while(head < tail && deq[tail - 1].second < dp[pre][j])tail--;
                deq[tail++] = P(j,dp[pre][j]);
                while(head < tail && deq[head].first < j - len)head++;
                dp[now][j] = deq[head].second + node[i].b - abs(node[i].a - j);
            }
            head = tail = 0;
            for(int j = n;j >= 1;j--){
                while(head < tail && deq[tail - 1].second < dp[pre][j])tail--;
                deq[tail++] = P(j,dp[pre][j]);
                while(head < tail && deq[head].first > j + len)head++;
                dp[now][j] = max(dp[now][j],deq[head].second + node[i].b - abs(node[i].a - j));
            }
            swap(now,pre);
        }
        ll ans = -inf;
        for(int i = 1;i <= n;i++)
            ans = max(ans,dp[pre][i]);
        printf("%lld\n",ans);
	}
	return 0;
}
