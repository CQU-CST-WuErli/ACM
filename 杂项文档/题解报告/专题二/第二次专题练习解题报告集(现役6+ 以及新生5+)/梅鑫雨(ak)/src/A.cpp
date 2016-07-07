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
ll dp[1005];
ll p[10005];
struct maxtri
{  
    ll a[4][4];
};
maxtri mul(maxtri a, maxtri b){
    maxtri c;MEM(c.a,0);
    for(int k=1;k<=3;k++){
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                c.a[i][j] = (c.a[i][j]+a.a[i][k]*b.a[k][j]%MOD)%MOD;
            }
        }
    }
    return c;
}
maxtri quickpow(maxtri a,ll x){
    maxtri b;MEM(b.a,0);b.a[1][1] = b.a[2][2] = b.a[3][3] = 1;
    while(x){
        if(x&1)b = mul(b,a);
        a = mul(a,a);
        x >>= 1;
    }
    return b;
}
maxtri get(){
    maxtri a;
    MEM(a.a,0);
    a.a[1][1] = 4,a.a[1][2] = 2,a.a[1][3] = 1;
    return a;
}
maxtri getbase(){
    maxtri a;
    MEM(a.a,0);
    a.a[1][1] = a.a[1][2] = a.a[2][1] = a.a[2][3] = a.a[3][1] = 1;
    return a;
}
ll lp[505][3];
ll rp[505][3];
ll dis[4]={1,1,2,4};
ll find(ll d){
    if(d<0)return 0;
    if(d<=3)return dis[d];
    else{
        maxtri a = get();
        maxtri b = getbase();
        b = quickpow(b,d-3);
        a = mul(a,b);
        return a.a[1][1];
    }
}

int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif
    int t;cin >> t;
    while(t--){
        MEM(lp,0);
        ll n,m;cin >> n >>m;
        for(int i=1;i<=m;i++)cin >> p[i];
        sort(p+1,p+1+m);
        if(!m){
            cout<<find(n) <<'\n';
            continue;
        }
        if(p[1]==0 || p[m]==n){
            cout<< 0 <<'\n';
            continue;
        }
        lp[1][1] = find(p[1]-1);
        lp[1][2] = find(p[1]-2);
        for(int i=2;i<=m;i++){
            if(p[i]==p[i-1]){
                continue;
            }
            else if(p[i]==p[i-1]+1){
                lp[i][2] = lp[i-1][1];
            }
            else{
                lp[i][1] =(lp[i][1]+ find(p[i]-1-p[i-1]-1)*((lp[i-1][1]+lp[i-1][2])%MOD))%MOD;
                lp[i][1] =(lp[i][1]+ find(p[i]-1-p[i-1]-2)*lp[i-1][1]%MOD)%MOD;
                lp[i][2] =(lp[i][2]+ find(p[i]-2-p[i-1]-1)*((lp[i-1][1]+lp[i-1][2])%MOD))%MOD;
                lp[i][2] =(lp[i][2]+ find(p[i]-2-p[i-1]-2)*lp[i-1][1]%MOD)%MOD;
            }
        }
        ll tot = 0;
        tot = (tot + find(n-p[m]-1)*((lp[m][1]+lp[m][2])%MOD))%MOD;
        tot = (tot + find(n-p[m]-2)*(lp[m][1])%MOD)%MOD;
        cout << tot << endl;

    }
	return 0;
}