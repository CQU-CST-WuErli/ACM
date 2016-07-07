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
int dp[500005];
int a[500005];
int c[500005];
int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    int t;cin >> t;
    while(t--){
        int n,k;cin >> n >> k;
        MEM(dp,-1);
        dp[0] = 0;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)scanf("%d",&c[i]);
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                if(dp[j]>=0)dp[j]=c[i];
                else if(j<a[i] || dp[j-a[i]]<=0)dp[j] = -1;
                else dp[j] = dp[j-a[i]]-1;
            }
        }
        if(dp[k]>=0)printf("yes\n");
        else printf("no\n");
    }
	return 0;
}