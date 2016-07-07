#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<utility>
#include<sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 500;
int mod = 10007;
int n,m;
int dp[105][6100];
char s[105][105];
struct Automate{
	int nxt[maxn][27], fail[maxn], root, sz, cnt[maxn];
	int newnode()
	{
		cnt[sz] = 0;
		memset(nxt[sz],-1,sizeof(nxt[sz]));
		return sz++;
	}
	void init() {
		sz = 0;
		root = newnode();
	}
	void insert(char s[]) {
		int n = strlen(s);
		int u = root;
		for(int i = 0; i < n; ++i) {
			int &v = nxt[u][s[i]-'A'];
			if(v==-1) 	v = newnode();
			u = v;
		}
		cnt[u]++;
	}
	void build() {
		queue<int> q;
		fail[root] = root;
		for(int i = 0; i < 26; ++i) {
			int &v = nxt[root][i];
			if(~v) {
				fail[v] = root;
				q.push(v);
			} else v = root;
		}
		while(q.size()) {
			int u = q.front(); q.pop();
			if(cnt[fail[u]]) cnt[u] = 1;
			for(int i = 0; i < 26; ++i) {
				int &v = nxt[u][i];
				if(~v) {
					fail[v] = nxt[fail[u]][i];
					q.push(v);
				} else v = nxt[fail[u]][i];
			}
		}
	}
	int query(char *s) {
		int n = strlen(s);
		int u = root, ret = 0;
		for(int i = 0; i < n; ++i) {
			u = nxt[u][s[i]-'a'];
			for(int v = u; v != root; v = fail[v]) {
				ret += cnt[v];
				cnt[v] = 0;
			}
		}
		return ret;
	}

}ac;
int main()
{
	#ifdef LOCAL
	freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
	#endif // LOCAL
	int t;
	scanf("%d",&t);
	while(t--){
        ac.init();
        scanf("%d%d",&n,&m);
        for(int i = 0;i < n;i++){
            scanf("%s",s[i]);
        }
        for(int i = 0;i < n;i++)
            ac.insert(s[i]);
        ac.build();
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < ac.sz;j++){
                if(dp[i][j] == 0)continue;
                if(ac.cnt[j])continue;
                for(int k = 0;k < 26;k++){
                    int temp = ac.nxt[j][k];
                    if(ac.cnt[temp])continue;
                    dp[i + 1][temp] = (dp[i + 1][temp] + dp[i][j])%mod;
                }
            }
        }
        int ans = 0;
        for(int i = 0;i < ac.sz;i++){
            if(ac.cnt[i])continue;
            ans = (ans + dp[m][i])%mod;
        }
        ll rans = 1;
        for(int i = 1;i <= m;i++)
            rans = (rans*26)%mod;
        rans = (rans - ans + mod)%mod;
        printf("%lld\n",rans);
	}
	return 0;
}
