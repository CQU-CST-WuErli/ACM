#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 10000;
int head[maxn],n,m,sccno[maxn],pre[maxn],low[maxn],dfsn,sccn,gn[maxn],gsum[maxn],cnt;
struct edge{
        int nxt,v;
}e[60 * maxn];

vector<int > g[maxn];
stack<int > s;

void add(int u,int v){
        e[cnt].v = v;
        e[cnt].nxt = head[u];
        head[u] = cnt++;
        return;
}

void scc(int u){
        pre[u] = low[u] = ++dfsn;
        s.push(u);
        for(int i = head[u];~i;i = e[i].nxt){
                int v = e[i].v;
                if(!pre[i]){
                        scc(v);
                        low[u] = min(low[u],low[v]);
                }
                else if(low[u] > low[v] && !sccno[v]) low[u] = low[v];
        }
        if(pre[u] == low[u]){
                int x;
                sccn++;
                for(;;){
                        x = s.top(); s.pop();
                        sccno[x] = sccn;
                        //printf("%d %d\n",x,sccn);
                        if(x == u) break;
                }
        }
        return;
}

int dfs(int u){
        int len = g[u].size();
        gsum[u] = gn[u];
        for(int i = 0;i < len;i++){
                gsum[u]+=dfs(g[u][i]) + 1;
        }
        return gsum[u];
}

void init(){
        memset(pre,0,sizeof pre);
        memset(low,0,sizeof low);
        memset(sccno,0,sizeof sccno);
        memset(gsum,0,sizeof gsum);
        memset(head,-1,sizeof head);
        memset(gn,0,sizeof gn);
        dfsn = cnt = sccn = 0;
}
int main(){
        int t;scanf("%d",&t);
        for(int k = 1;k <= t;k++){
                init();
                int u,v;
                scanf("%d%d",&n,&m);
                while(m--){
                        scanf("%d%d",&u,&v);
                        add(u,v);
                }
                for(int i = 0;i < n;i++){
                        if(!pre[i]) scc(i);
                }
                for(int i = 1;i <= sccn;i++){
                        g[i].clear();
                        //gn[i] = 0;
                }
                for(int i = 0;i < n;i++){
                        for(int j = head[i];~j;j = e[j].nxt){
                                int v = e[j].v;
                                //printf("%d %d %d %d\n",i,sccno[i],v,sccno[v]);
                                if(sccno[i] != sccno[v]){
                                        g[sccno[v]].push_back(sccno[i]);
                                }
                                else{
                                        //printf("%d\n",sccno[i]);
                                        gn[sccno[i]]++;
                                }
                        }
                }
                for(int i = 1;i <= sccn;i++) if(gn[i] > 0) gn[i]--;
                int maxa = 0;
                for(int i = 1;i <= sccn;i++) if(!gsum[i]) dfs(i);
                for(int i = 1;i <= sccn;i++){
                        if(gsum[i] > maxa)
                                maxa = gsum[i];
                }
                printf("Case %d: %d\n",k,maxa);
                for(int i = 0;i < n;i++){
                        if(gsum[sccno[i]] == maxa){
                                printf("%d ",i);
                        }
                }
                puts("");
        }


        return 0;
}
