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
int dp[41][41][41][41];
int a[10000];
int b[10000];
int cnt[5];
int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    int t;cin >> t;
    while(t--){
        MEM(cnt,0);
        MEM(dp,0);
        int n,m;cin >> n >> m;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=m;i++)scanf("%d",&b[i]),cnt[b[i]]++;
        int pos;
        int nmax = 0;
        dp[0][0][0][0] = a[1];
        for(int i=0;i<=cnt[1];i++){
            for(int j=0;j<=cnt[2];j++){
                for(int k=0;k<=cnt[3];k++){
                    for(int t=0;t<=cnt[4];t++){
                        pos = i+j*2+k*3+t*4+1;
                        if(i)dp[i][j][k][t]=max(dp[i][j][k][t],dp[i-1][j][k][t]+a[pos]);
                        if(j)dp[i][j][k][t]=max(dp[i][j][k][t],dp[i][j-1][k][t]+a[pos]);
                        if(k)dp[i][j][k][t]=max(dp[i][j][k][t],dp[i][j][k-1][t]+a[pos]);
                        if(t)dp[i][j][k][t]=max(dp[i][j][k][t],dp[i][j][k][t-1]+a[pos]);
                        nmax = max(nmax,dp[i][j][k][t]);
                    }
                }
            }
        }
        cout << nmax << '\n';
    }
	return 0;
}














