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
int a[100005];
double dp[1000005];
int gcd(int a,int b){
    return a == 0 ? b : gcd(b%a,a);
}
int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    int t;cin >> t;
    while(t--){
        MEM(dp,0);
        int n;cin >> n;
        int zero = 0,nmax = -1;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),nmax = max(nmax,a[i]);
        int ok = 0;
        int com = 0;
        for(int i=1;i<=n;i++){
            if(a[i]==0)zero++;
            if(a[i] && !ok){
                ok = 1;
                com = a[i];
            }
            else if(a[i]){
                com = gcd(com,a[i]);
            }
        }
        int cnt = nmax/com;
        if(n==2 && zero){
            printf("%d\n",2);
        }
        else{
            int r = cnt;
            if(zero)cnt++;
            r = cnt;
            for(int i=1;i<=r;i++){
                dp[i] = dp[i-1] +1.0*r/(r-(i-1));
            }
            printf("%d\n",int(dp[r]+(r-n)));
        }
    }
	return 0;
}