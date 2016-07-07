#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#define M 105
#define ULL unsigned long long
#define LL long long
using namespace std;
const int mod = 10007;
struct aho_corasick {
    int next[M*60][26], fail[M*60];
    int dp[105][M*60];
    bool mark[M*60];
    int root, L;
    int newnode() {
        for(int j = 0; j < 26; j++) next[L][j] = -1;
        return L++;
    }
    void init() {
        L = 0;
        memset(mark, 0, sizeof(mark));
        root = newnode();
    }
    void insert(char buf[]) {
        int len = strlen(buf);
        int now = root;
        for(int j = 0; j < len; j++) {
            if(next[now][buf[j] - 'A'] == -1) next[now][buf[j] - 'A'] = newnode();
            now = next[now][buf[j] - 'A'];
        }
        mark[now] = 1;
    }
    void build() {
        queue<int>Q;
        fail[root] = root;
        for(int j = 0; j < 26; j++) {
            if(next[root][j] == -1) next[root][j] = root;
            else {
                fail[next[root][j]] = root;
                Q.push(next[root][j]);
            }
        }
        while(!Q.empty()) {
            int now = Q.front();
            //printf("%d\n",now);
            if(mark[fail[now]]) mark[now] = 1;
            Q.pop();
            for(int j = 0; j < 26; j++) {
                if(next[now][j] == -1) next[now][j] = next[fail[now]][j];
                else {
                    fail[next[now][j]] = next[fail[now]][j];
                    Q.push(next[now][j]);
                }
            }
        }
    }
    int DP(int len){
        memset(dp,0,sizeof(dp));
        dp[0][root]=1;
        for(int j=0;j<len;j++){
            for(int k=0;k<L;k++){
                if(!dp[j][k]) continue;
                for(int i=0;i<26;i++){
                    int now=next[k][i];
                    int t=now;
                    int ok=1;
                    //if(j==0&&k==0) printf("%d %d\n",i,t);
                    while(t!=root){
                        if(mark[t]){
                            ok=0;
                            break;
                        }
                        t=fail[t];
                    }
                    if(!ok) continue;
                    dp[j+1][now]=(dp[j+1][now]+dp[j][k])%mod;
                }
            }
        }
        //printf("%d\n",dp[1][root]);
        int ans=0;
        for(int j=0;j<L;j++) ans=(ans+dp[len][j])%mod;
        return ans;
    }
};
char s[M];
aho_corasick ac;
int fast(int x,int y){
    int res=1;
    while(y){
        if(y&1) res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        ac.init();
        int j, k;
        for(j = 1; j <= n; j++) {
            scanf("%s", s);
            ac.insert(s);
        }
        ac.build();
        //printf("%d\n",ac.next[0][0]);
        int ans=(fast(26,m)-ac.DP(m)+mod)%mod;
        printf("%d\n",ans);
    }
    //system("pause");
    return 0;
}
