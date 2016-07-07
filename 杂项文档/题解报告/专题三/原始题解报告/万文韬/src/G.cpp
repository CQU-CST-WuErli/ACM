#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
const int maxn = 1000 + 50;
const int inf = 0x3f3f3f3f;
int n,m,head[maxn],d[maxn],vis[maxn],minl,ans,sign[maxn * maxn],cnt;


struct edge{
        int nxt,v,c;
}e[maxn * maxn];

void add(int u,int v,int c){
        e[cnt].v = v;
        e[cnt].nxt = head[u];
        e[cnt].c = c;
        head[u] = cnt++;
}

/*void dij(int u){
        memset(d,inf,sizeof d);
        memset(vis,0,sizeof vis);
        d[u] = 0;
        for(int i = head[u];~i;i = e[i].nxt) d[e[i].v] = e[i].c;
        vis[u] = 1;
        for(int i = 1;i <= n;i++){
                int tmp = inf;
                int v = u;
                for(int j = 1;j <= n;j++){
                        if(!vis[j] && d[j] < tmp){
                                v = j; tmp = d[j];
                        }
                        vis[v] = 1;
                        for(int j = head[v];~j;j = e[j].nxt){
                                int to = e[j].v;
                                if(!vis[to]){
                                        d[to] = min((d[v] + e[j].c),d[to]);
                                }
                        }
                }
        }
        return;
}
*/

void spfa(int s){
        queue <int> q;
        for(int i=1;i<=n;i++)
                d[i]=inf;
        memset(vis,false,sizeof(vis));
        q.push(s);
        d[s]=0;
        while(!q.empty())
        {
                int u=q.front();
                q.pop();
                vis[u]=false;
                for(int i=head[u];i!=-1;i=e[i].nxt)
                {
                        int v=e[i].v;
                        if(d[v]>d[u]+e[i].c){
                                d[v]=d[u]+e[i].c;
                                if(!vis[v]){
                                        vis[v]=true;
                                        q.push(v);
                                }
                        }
                }
        }
}

int dfs(int u,int v,int cur,int l){
        int flag = 0;
        if(cur == v && l == minl){\
                ans++;
                return 1;
        }
        for(int i = head[cur];~i;i = e[i].nxt){
                if(!sign[i] && (e[i].c + l) <= minl && (l + e[i].c) == d[e[i].v]){
                        sign[i] = 1;
                        if(!dfs(u,v,e[i].v,l + e[i].c))
                                sign[i] = 0;
                        else if(cur != u) return 1;
                }
        }
        return 0;
}
int main(){
        int t;
        scanf("%d",&t);
        while(t--){
                ans = cnt = 0;
                memset(head,-1,sizeof head);
                memset(sign,0,sizeof sign);
                scanf("%d%d",&n,&m);
                while(m--){
                        int u,v,c;scanf("%d%d%d",&u,&v,&c);
                        add(u,v,c);
                }
                int u,v;scanf("%d%d",&u,&v);
                spfa(u);
                minl = d[v];
                dfs(u,v,u,0);
                printf("%d\n",ans);
        }




}
