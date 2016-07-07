#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
const int M = 1e4+5;
map<pair<int,int>,int>mp;
int low[M],pre[M];
bool iscut[M];
int p[M];
vector<int>G[M];
int dfs_clock;
int ans;
int tarjan(int u, int fa) {
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;
    for(int j = 0; j < G[u].size(); j++) {
        int v = G[u][j];
        if(!pre[v]) {
            child++;
            int lowv = tarjan(v, u);
            lowu = min(lowu, lowv);
            if(lowv >= pre[u]) iscut[u] = true;
            int a=min(u,v),b=max(u,v);
            if(lowv>pre[u]&&mp[make_pair(a,b)]==1) ans++;
        } else if(pre[v] < pre[u] && v != fa) lowu = min(lowu, pre[v]);
    }
    if(fa < 0 && child == 1) iscut[u] = 0;
    low[u] = lowu;
    return lowu;
}
int main(){
    int T,cas=1;
    scanf("%d",&T);
    while(T--){
        mp.clear();
        memset(low,0,sizeof(low));
        memset(pre,0,sizeof(pre));
        memset(iscut,0,sizeof(iscut));
        int n,m;
        scanf("%d%d",&n,&m);
        for(int j=1;j<=n;j++) G[j].clear();
        for(int j=1;j<=m;j++){
            int a,b;
            scanf("%d%d",&a,&b);
            if(a>b) swap(a,b);
            G[a].push_back(b);
            G[b].push_back(a);
            mp[make_pair(a,b)]++;
        }
        dfs_clock=0;
        ans=0;
        for(int j=1;j<=n;j++){
            if(!pre[j]) tarjan(j,-1);
        }
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}
