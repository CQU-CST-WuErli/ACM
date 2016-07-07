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
int val[7]={0,100,50,20,10,5,1};
int ta[7],tb[7],tc[7];
int dp[7][1005][1005];
int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    int t;cin>>t;
    while(t--){
        MEM(dp,inf);
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        ll tta = 0,ttb = 0,ttc = 0;
        for(int i=1;i<=6;i++)scanf("%d",&ta[i]),tta+=ta[i]*val[i];
        for(int i=1;i<=6;i++)scanf("%d",&tb[i]),ttb+=tb[i]*val[i];
        for(int i=1;i<=6;i++)scanf("%d",&tc[i]),ttc+=tc[i]*val[i];
        ll tot = tta+ttb+ttc;
        dp[0][tta][ttb] = 0;
       // cout << tta << ' '<<ttb<<' '<<ttc << endl;
        int cnt = 0,add;
        int give;
        int s,t;
        //cout << tot << endl;
        for(int i=1;i<=6;i++){
            for(int j=0;j<=tot;j++){
                for(int k=0;k<=tot-j;k++){
                    if(dp[i-1][j][k]==inf)continue;
                    //a,b
                    cnt = ta[i]+tb[i]+tc[i];
                    for(s = 0;s<=cnt;s++){
                        for(t=0;t<=cnt-s;t++){
                            add = 0;
                            add += max(0,s-ta[i]);
                            add += max(0,t-tb[i]);
                            add += max(0,cnt-s-t-tc[i]);
                            dp[i][j+(s-ta[i])*val[i]][k+(t-tb[i])*val[i]]=min(dp[i][j+(s-ta[i])*val[i]][k+(t-tb[i])*val[i]],
                                dp[i-1][j][k]+add);
                        }
                    }
                }
            }
        }
        tta -= a,ttb += a;
        ttb -= b,ttc += b;
        ttc -= c,tta += c;
        if(tta >= 0 && ttc >= 0 && ttb >= 0 && dp[6][tta][ttb]!=inf){
            printf("%d\n",dp[6][tta][ttb]);
        }
        else printf("impossible\n");
    }
	return 0;
}















