#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;
const int maxn = 5000 + 50;
const int inf = 0x3f3f3f;
struct node{
        int to,nxt;
}e[100000 + 50];
int n,m,linker[maxn],used[maxn],head[maxn],cnt;
int pre[maxn],sccno[maxn],lowlink[maxn],dfsclock,scccnt;
int min(int a,int b){
        return a > b ? b : a;
}

stack<int> s;
vector<int> g[maxn];

void scc(int u){
        pre[u] = lowlink[u] = ++dfsclock;
        s.push(u);
        for(int i = head[u];~i;i = e[i].nxt){
                int v = e[i].to;
                if(!pre[v]){
                    scc(v);
                    lowlink[u] = min(lowlink[u],lowlink[v]);
                }
                else if(!sccno[v]){
                        lowlink[u] = min(pre[v],lowlink[u]);
                }
        }
        if(lowlink[u] == pre[u]){
                scccnt++;
                for(; ; ){
                        int x = s.top();s.pop();
                        sccno[x] = scccnt;
                        if(x==u) break;
                }
        }
        return;
}

void findscc(){
        memset(pre,0,sizeof pre);
        //memset(lowlink,inf,sizeof lowlink);
        memset(sccno,0,sizeof sccno);
        scccnt = dfsclock = 0;
        for(int i = 1;i <= n;i++){
                if(!pre[i]) scc(i);
        }
        return;
}

void add(int u,int v){
        e[cnt].to = v;
        e[cnt].nxt = head[u];
        head[u] = cnt++;
}

int dfs(int u){
        int len = g[u].size();
        for(int i = 0;i < len;i++){
                int v = g[u][i];
                if(!used[v]){
                        used[v] = 1;
                        if(linker[v] == -1 || dfs(linker[v])){
                                linker[v] = u;
                                return 1;
                        }
                }
        }
        return 0;
}

int hungary(){
        memset(linker,-1,sizeof linker);
        int res = 0;
        for(int i = 1;i <= scccnt;i++){
                memset(used,0,sizeof used);
                if(dfs(i)) res++;
        }
        return res;
}

int main(){
        int T;scanf("%d",&T);
        while(T--){
                int u,v;
                cnt = 0;
                memset(head,-1,sizeof head);
                scanf("%d%d",&n,&m);
                while(m--){
                        scanf("%d%d",&u,&v);
                        add(u,v);
                }
                findscc();
                for(int i = 1;i <= scccnt;i++) g[i].clear();
                for(int i = 1;i <= n;i++){
                        for(int j = head[i];~j;j = e[j].nxt){
                                int v = e[j].to;
                                if(sccno[i] != sccno[v]){
                                        g[sccno[i]].push_back(sccno[v]);
                                }
                        }
                }

                printf("%d\n",scccnt - hungary());
        }
        return 0;
}
