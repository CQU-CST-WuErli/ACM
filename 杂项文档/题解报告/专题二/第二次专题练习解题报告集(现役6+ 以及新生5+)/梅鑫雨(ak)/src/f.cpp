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
ll ai[10005],bi[10005],ci[10005];
ll dp[2][150005];
struct node
{
    ll val;
    int pos;
};
node q[150005];
int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    int t;cin >>t;
    while(t--){
        int n,m,d;scanf("%d%d%d",&n,&m,&d);
        ll tot = 0;
        for(int i=1;i<=m;i++){
            scanf("%lld%lld%lld",&ai[i],&bi[i],&ci[i]);
            tot += bi[i];
        }
        for(int i=1;i<=n;i++){
            dp[1][i] = fabs(ai[1]-i);
        }
        int tail,head;
        for(int i=2;i<=m;i++){
            ll dis = 1ll*d*(ci[i]-ci[i-1]);
            dis = min(dis,(ll)n);
            tail = head = 0;
            for(int j=1;j<=dis;j++){
                while(head < tail && dp[(i-1)%2][j]<q[tail-1].val)tail--;
                q[tail].val = dp[(i-1)%2][j],q[tail++].pos = j; 
            }
            for(int j=1;j<=n;j++){
                int l,r;
                l = j-dis;
                r = j+dis;
                l = max(1,l);
                while(head < tail && q[head].pos < l)head++;
                if(r<=n){
                    while(head < tail && dp[(i-1)%2][r]<q[tail-1].val)tail--;
                    q[tail].val = dp[(i-1)%2][r],q[tail++].pos = r;
                }
                dp[i%2][j]=q[head].val+fabs(ai[i]-j);
            }
        }
        ll nmax = -inf;
        for(int i=1;i<=n;i++) nmax = max(tot-dp[m%2][i],nmax);
        cout << nmax << endl;
    }
	return 0;
}















