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
int dp[2][1000005];
int a[100];
int sum[1000];
int offset = 0;
int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    int t;cin >> t;
    while(t--){
        int n,m;scanf("%d",&n);
        int nmin = -1;
        offset = 0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),offset += a[i];
        for(int i=0;i<=1;i++){
            for(int j=-offset;j<=offset;j++){
                dp[i%2][j+offset] = -1;
            }
        }
        dp[0][offset] = 0;
        for(int i=1;i<=n;i++){
            for(int j=-offset;j<=offset;j++){
                if(dp[(i-1)%2][j+offset]!=-1){
                    if(j<0){
                        dp[i%2][j+offset+a[i]] = max(dp[i%2][j+offset+a[i]],dp[(i-1)%2][j+offset]+min((int)fabs(j),a[i]));
                        dp[i%2][j+offset] = max(dp[i%2][j+offset],dp[(i-1)%2][j+offset]);
                        dp[i%2][j+offset-a[i]] = max(dp[i%2][j+offset-a[i]],dp[(i-1)%2][j+offset]);
                    }
                    else{
                        dp[i%2][j+offset+a[i]] = max(dp[i%2][j+offset+a[i]],dp[(i-1)%2][j+offset]);
                        dp[i%2][j+offset] = max(dp[i%2][j+offset],dp[(i-1)%2][j+offset]);
                        dp[i%2][j+offset-a[i]] = max(dp[i%2][j+offset-a[i]],dp[(i-1)%2][j+offset]+min(j,a[i]));
                    }
                }
            }
            for(int j=-offset;j<=offset;j++){
                dp[(i-1)%2][j+offset]=-1;
            }
        }
        nmin = max(nmin,dp[n%2][offset]);
        if(nmin <= 0){
            printf("GG\n");
        }
        else{
            printf("%d\n",nmin);
        }
    }
	return 0;
}









