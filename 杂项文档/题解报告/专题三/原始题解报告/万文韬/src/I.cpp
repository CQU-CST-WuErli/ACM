#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int maxn = 10000 * 2;           //开10000 + 50 都会 re，不是很懂
int n,m,pre[maxn],low[maxn],dfsclock;
int head[maxn],cnt,bridge;

struct map{
        int nxt;
        int v;
        int flag;
}G[maxn * 2];


void add(int u,int v){
        int i;
        for(i = head[u];~i;i = G[i].nxt){
                if(G[i].v == v) break;
        }
        if(~i){
                G[i].flag = 1;
                G[i ^ 1].flag = 1;
                return;
        }
        G[cnt].v = v;
        G[cnt].nxt = head[u];
        G[cnt].flag = 0;
        head[u] = cnt++;
        return;
}

void init(){
        cnt = 0;
        dfsclock = 0;
        memset(pre,0,sizeof pre);
        memset(low,0,sizeof low);
        bridge = 0;
        memset(head,-1,sizeof head);
        return;
}

void dfs(int u,int fa){
        low[u] = pre[u] = ++dfsclock;
        for(int i = head[u];i != -1 ;i = G[i].nxt){
                int v = G[i].v;
                if(!pre[v]){
                        dfs(v,u);
                        low[u] = min(low[u],low[v]);
                        if(low[v] > pre[u] && !G[i].flag){
                                bridge++;
                        }
                }
                else if(v != fa && low[u] > pre[v]){
                        low[u] = pre[v];
                }
        }
        //if(fa < 0 && child == 1) bridge[i] = 0;
}

int main(){
        int t;
        scanf("%d",&t);
        for(int i  =1;i <= t;i++){
                init();
                scanf("%d%d",&n,&m);
                while(m--){
                        int u,v;scanf("%d%d",&u,&v);
                        add(u,v);
                        add(v,u);
                }
                for(int j = 1;j <= n;j++){
                        if(!pre[j])
                                dfs(j,-1);
                }
                /*
                for(int j = 0;j < cnt;j++){
                        if(G[i].cut){
                                ans++;
                                printf("%d %d\n",G[j].v,j);
                                if(G[j ^ 1].cut) j++;
                        }
                }*/
                printf("Case %d: %d\n",i,bridge);
        }
        return 0;
}
