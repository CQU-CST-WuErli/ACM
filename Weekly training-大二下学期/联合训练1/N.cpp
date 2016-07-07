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
const int MOD = 10007;
//#define LOCAL
int n,m,f[110][6001];
char s[100];
int i,ch[6001][30],fail[6001],siz,flag[6001],l[6001];
void init(){
    siz=1;
    MEM(flag,0);
    MEM(ch,0);
    MEM(f,0);
    for(int i=0;i<26;i++) ch[0][i]=1;
}
void insert(){
    scanf("%s",s);
    int now=1,len=strlen(s);
    for(int i=0;i<len;++i){
        if(!ch[now][s[i]-'A']) ch[now][s[i]-'A']=++siz;
        now=ch[now][s[i]-'A'];
    }
    flag[now]=1;
}
void getfail(){
    int h,t,u,v;
    h=t=1;l[h]=1;fail[1]=0;
    while(h<=t){
        u=l[h];
        for(int i=0;i<26;++i)
            if(ch[u][i]){
                v=ch[u][i];
                int k=fail[u];
                while(!ch[k][i]) k=fail[k];
                if(flag[ch[k][i]]) flag[v]=1;
                fail[v]=ch[k][i];
                l[++t]=v;
            }
        h+=1;
    }
}

void solve() {
    f[0][1] =1;
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=siz;j++) {
            if(!flag[j] && f[i-1][j]) {
                for(int k=0;k<26;k++) {
                    int now = j;
    				while(ch[now][k] == 0) now = fail[now];
					f[i][ch[now][k]] = (f[i][ch[now][k]]+f[i-1][j])%MOD;
					//cout << f[i][ch[now][k]] << endl;
                }
            }
        }
    }
    int ans = 1;
    for(int i=1;i<=m;i++) ans = (ans*26)%MOD;
    for(int i=1;i<=siz;i++)
        if(!flag[i]) ans = (ans+MOD-f[m][i])%MOD;
    printf("%d\n",ans);
}
int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    int t;cin >> t;
    while(t--){
        scanf("%d%d",&n,&m);
        init();
        for(int i=1;i<=n;i++)insert();
        getfail();
        solve();
    }
	return 0;
}
