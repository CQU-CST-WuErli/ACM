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
ll x[200005];
ll dp[200005];
int q[200005];
ll up(int p,int p1){
    ll a = dp[p]+x[p+1]*x[p+1];
    ll b = dp[p1]+x[p1+1]*x[p1+1];
    return a - b;
}
double down(int p,int p1){
    return 2*x[p+1]-2*x[p1+1];
}
int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        ll w;cin >> w;
        int cnt = 0;
        for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
        int head,tail;
        head = tail = dp[0] = q[0] = 0;
        for(int i=1;i<=n;i++){
            while(head < tail && up(q[head+1],q[head])<=down(q[head+1],q[head])*x[i])head++;
            dp[i] = dp[q[head]] + w + (x[i]-x[q[hdead]+1])*(x[i]-x[q[head]+1]);
            while(head < tail && up(q[tail],q[tail-1])*down(i,q[tail])>=up(i,q[tail])*down(q[tail],q[tail-1]))tail--;
            q[++tail] = i;
        }
        printf("%lld\n",dp[n]);
    }
	return 0;
}









