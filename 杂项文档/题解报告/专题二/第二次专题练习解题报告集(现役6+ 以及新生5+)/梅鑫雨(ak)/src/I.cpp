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
int a[1000000];
double dp[51][500005];
double r[500005];
double q[500005];
double s[500005];
double up(int p,int p1,int i){
    double a = dp[i][p]-s[p]+q[p]*r[p];
    double b = dp[i][p1]-s[p1]+q[p1]*r[p1];
    return a-b;
}
double down(int p,int p1){
    double a = r[p];
    double b = r[p1];
    return a-b;
}
int que[1000005];
int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    int t;cin >> t;
    while(t--){
        int n,m;scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        r[0] = 0,q[0] = 0,s[0] = 0;
        for(int i=1;i<=n;i++){
            r[i] = r[i-1]+a[i];
            q[i] = q[i-1]+1.0/a[i];
            s[i] = s[i-1]+r[i]/a[i];
        }
        int head,tail;
        for(int i=1;i<=n;i++){
            dp[1][i] = s[i];
        }
        for(int i=2;i<=m;i++){
            head = tail = 0;
            que[0] = i-1;
            for(int j=i;j<=n;j++){
                while(head < tail && up(que[head+1],que[head],i-1)<=down(que[head+1],que[head])*q[j])
                    head++;
                dp[i][j] = dp[i-1][que[head]]+s[j]-s[que[head]]-(q[j]-q[que[head]])*r[que[head]];
                while(head < tail && up(que[tail],que[tail-1],i-1)*down(j,que[tail-1])>=up(j,que[tail-1],i-1)*down(que[tail],que[tail-1]))
                    tail--;
                que[++tail] = j;
            }
        }
        printf("%.4f\n",dp[m][n]);
    }
	return 0;
}