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
#define LL long long
using namespace std;
const int M =1e3+5,INF=0x3f3f3f3f;
struct node{
    int to,v;
};
struct flow{
    struct edge{
        int to,rev;
        LL cap;
        edge(int to,LL cap,int rev): to(to),cap(cap),rev(rev){}
    };
    vector<edge>G[M];
    int level[M];
    int iter[M];
    void init(int n){
        for(int j=1;j<=n;j++) G[j].clear();
    }
    void add_edge(int from,int to,int cap){
        G[from].push_back(edge(to,cap,G[to].size()));
        G[to].push_back(edge(from,0,G[from].size()-1));
    }
    void bfs(int s){
        memset(level,-1,sizeof(level));
        queue<int>Q;
        level[s]=0;
        Q.push(s);
        while(!Q.empty()){
            int v=Q.front();Q.pop();
            for(int j=0;j<G[v].size();j++){
                edge &e=G[v][j];
                if(e.cap>0&&level[e.to]<0){
                    level[e.to]=level[v]+1;
                    Q.push(e.to);
                }
            }
        }
    }
    LL dfs(int v,int t,LL f){
        if(v==t) return f;
        for(int &j=iter[v];j<G[v].size();j++){
            edge &e=G[v][j];
            if(e.cap>0&&level[v]<level[e.to]){
                LL d=dfs(e.to,t,min(f,e.cap));
                if(d>0){
                    e.cap-=d;
                    G[e.to][e.rev].cap+=d;
                    return d;
                }
            }
        }
        return 0;
    }
    LL max_flow(int s,int t){
        LL flow=0;
        for(;;){
            bfs(s);
            if(level[t]<0) return flow;
            memset(iter,0,sizeof(iter));
            LL f;
            while((f=dfs(s,t,INF))>0) flow+=f;
        }
    }
}A;
vector<node>edge[M];
int dis[M];
bool mark[M];
void spfa(int s){
    memset(dis,63,sizeof(dis));
    memset(mark,0,sizeof(mark));
    queue<int>Q;
    Q.push(s);
    dis[s]=0;
    while(!Q.empty()){
        int now=Q.front();Q.pop();
        mark[now]=0;
        for(int j=0;j<edge[now].size();j++){
            int to=edge[now][j].to,v=edge[now][j].v;
            if(dis[to]>dis[now]+v){
                dis[to]=dis[now]+v;
                if(!mark[to]){
                    Q.push(to);
                    mark[to]=1;
                }
            }
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int j=1;j<=n;j++) edge[j].clear();
        for(int j=1;j<=m;j++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            edge[a].push_back((node){b,c});
        }
        int s,t;
        scanf("%d%d",&s,&t);
        spfa(s);
        A.init(n);
        for(int j=1;j<=n;j++){
            for(int k=0;k<edge[j].size();k++){
                int to=edge[j][k].to,v=edge[j][k].v;
                if(dis[to]==dis[j]+v){
                    A.add_edge(j,to,1);
                }
            }
        }
        printf("%lld\n",A.max_flow(s,t));
    }
}
