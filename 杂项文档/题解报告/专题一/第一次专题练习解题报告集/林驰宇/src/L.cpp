#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<list>
#define LL long long
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
using namespace std;
const int MAX_SAM = 1e6 + 5, MAX_SAM_CH = 26;
struct SAM {
    int last, cnt;
    LL ans;
    int mx[MAX_SAM], fa[MAX_SAM], num[MAX_SAM], a[MAX_SAM][MAX_SAM_CH];
    bool mark[MAX_SAM];
    vector<int>edge[MAX_SAM];
    void init() {
        memset(mx, 0, sizeof(mx));
        memset(fa, 0, sizeof(fa));
        memset(num, 0, sizeof(num));
        memset(a, 0, sizeof(a));
        memset(mark,0,sizeof(mark));
        last = cnt = 0;
        last = ++cnt;
        ans=0;
    }
    void extend(int c) {
        int p = last, np = last = ++cnt; mx[np] = mx[p] + 1;
        num[np] = 1;
        while(p && !a[p][c])a[p][c] = np, p = fa[p];
        if(!p)fa[np] = 1;
        else {
            int q = a[p][c];
            if(mx[q] == mx[p] + 1)fa[np] = q;
            else {
                int nq = ++cnt; mx[nq] = mx[p] + 1;
                memcpy(a[nq], a[q], sizeof(a[q]));
                fa[nq] = fa[q];
                fa[np] = fa[q] = nq;
                while(a[p][c] == q)a[p][c] = nq, p = fa[p];
            }
        }
        //printf("%d %d\n",p,np);
        mark[np]=1;

    }
    void build(){
        char s[MAX_SAM];
        scanf("%s",s);
        int n=strlen(s);
        reverse(s,s+n);
        for(int j=0;j<n;j++) extend(s[j]-'a');
        for(int j=0;j<n;j++){
            ans+=1LL*j*(j+1)/2+1LL*(j+1)*j;
        }
    }
    void build_tree(){
        for(int j=1;j<=cnt;j++) edge[j].clear();
        for(int j=2;j<=cnt;j++){
            int a=fa[j],b=j;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
    }
    int dfs(int x,int y){
        int now=mark[x];
        for(int j=0;j<edge[x].size();j++){
            int to=edge[x][j];
            if(to==y) continue;
            int t=dfs(to,x);
            ans-=1LL*now*t*mx[x]*2;
            now+=t;
        }
        return now;
    }
}sam;
int main(){
    //freopen("data.in","r",stdin);
    //freopen("L.out","w",stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        sam.init();
        sam.build();
        sam.build_tree();
        sam.dfs(1,0);
        printf("%lld\n",sam.ans);
    }
    return 0;
}
