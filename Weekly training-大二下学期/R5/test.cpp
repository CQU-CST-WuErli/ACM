#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define N 60
#define INF 2000000
using namespace std;
struct edge{
    int v,w;
    edge *nxt;
}E[2009],*Adj[N],*cur;
int n,m,K,nn;
int s[N],in[N][1<<10];
int d[N][1<<10],dp[1<<10];
queue<int> Q;
void addedge(int u,int v,int w){cur->v=v,cur->w=w,cur->nxt=Adj[u],Adj[u]=cur++;}
bool check(int x){
    int r=0;
    for(int i=0;x;i++,x>>=1)
        r+=(x&1)*(i<K?1:-1);
    return r==0;
}
inline bool update(int x,int y,int w){
    if(w<d[x][y]) return d[x][y]=w,true;
    return false;
}
void spfa(){
    while(!Q.empty()){
        int x=Q.front()/10000,y=Q.front()%10000;
        in[x][y]=0;
        Q.pop();
        for(edge *i=Adj[x];i;i=i->nxt)
            if(update(i->v,y|s[i->v],d[x][y]+i->w)&&y==(y|s[i->v])&&!in[i->v][y])
                in[i->v][y]=1,Q.push(i->v*10000+y);

    }
}
void init(){
    cur=E;
    memset(Adj,0,sizeof(Adj));
    memset(s,0,sizeof(s));
    scanf("%d%d%d",&n,&m,&K);
    nn=1<<(2*K);
    for(int i=1;i<=n;i++)
        for(int j=0;j<nn;j++)
            d[i][j]=INF;
    while(m--){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
        addedge(v,u,w);
    }
    for(int i=1;i<=K;i++){
        s[i]=1<<(i-1),d[i][s[i]]=0;
        s[n-i+1]=1<<(K+i-1),d[n-i+1][s[n-i+1]]=0;
    }
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int T;
    scanf("%d",&T);
    while(T--){
        init();
        for(int y=0;y<nn;y++){
            for(int x=1;x<=n;x++){
                for(int i=(y-1)&y;i;i=(i-1)&y)
                    d[x][y]=min(d[x][y],d[x][i|s[x]]+d[x][(y-i)|s[x]]);
                if(d[x][y]<INF) Q.push(x*10000+y),in[x][y]=1;
            }
            spfa();
        }
        for(int j=0;j<nn;j++){
            dp[j]=INF;
            for(int i=1;i<=n;i++) dp[j]=min(dp[j],d[i][j]);
            cout << dp[j] << endl;
        }
        for(int i=1;i<nn;i++)
            if(check(i))
                for(int j=i&(i-1);j;j=(j-1)&i)
                    if(check(j))
                        dp[i]=min(dp[i],dp[j]+dp[i-j]);
        if(dp[nn-1]>=INF) puts("No solution");
        else printf("%d\n",dp[nn-1]);
    }
}