/*  ^^ ====== ^^ 
ID: meixiuxiu
PROG: test
LANG: C++11
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cctype>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int ,int> pii;
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a);
#define pi acos(-1.0)
#define maxn 40000
#define maxv 100005
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
//#define LOCAL
int offset = 3000;
int dp[2][6001];
int ta[2005],tb[2005];
int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    int t;cin>>t;
    while(t--){
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d%d",&ta[i],&tb[i]);
        MEM(dp,inf);
        dp[0][0+offset] = 0;
        for(int i=1;i<=n;i++){
            for(int t=-offset;t<=offset;t++){
                if(dp[(i-1)%2][t+offset]==inf)continue;
                if(t<0){
                    dp[i%2][-tb[i]+offset] = min(dp[i%2][-tb[i]+offset],
                        dp[(i-1)%2][t+offset]+tb[i]);
                    dp[i%2][t+ta[i]+offset] = min(dp[i%2][t+ta[i]+offset],
                        dp[(i-1)%2][t+offset]+max(0,ta[i]+t));
                }
                else{
                    dp[i%2][offset+ta[i]]=min(dp[i%2][offset+ta[i]],
                       dp[(i-1)%2][t+offset]+ta[i]);
                    dp[i%2][t-tb[i]+offset]=min(dp[i%2][t-tb[i]+offset],
                       dp[(i-1)%2][t+offset]+max(0,tb[i]-t));
                }
            }
            MEM(dp[(i-1)%2],inf);
        }
        int nmin =inf;
        for(int i=-offset;i<=offset;i++){
            nmin = min(nmin,dp[n%2][i+offset]);
        }
        printf("%d\n",nmin);
    }
	return 0;
}







