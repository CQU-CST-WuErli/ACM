#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <sstream>
#include <stack>
using namespace std;

#define cls(x) memset(x,0,sizeof x)
#define inf(x) memset(x,0x3f,sizeof x)
#define neg(x) memset(x,-1,sizeof x)
#define ninf(x) memset(x,0xc0,sizeof x)
#define st0(x) memset(x,false,sizeof x)
#define st1(x) memset(x,true,sizeof x)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define bug cout<<"here"<<endl;
//#define debug

const int maxn=10100;
int T;
int n,m;
vector<int> G[maxn];
int cnt=0;

int visit[maxn],low[maxn],dfn[maxn];
bool cut[maxn];

void dfs(int x,int father,int dep)
{
    visit[x]=-1;
    dfn[x]=dep;
    int child=0;
    for(int i=0;i<G[x].size();++i)
    {
        int t=G[x][i];
        if(t!=father&&visit[i]==-1)
            low[x]=min(low[x],dfn[t]);
        if(visit[t]==0)
        {
            dfs(t,x,dep+1);
            ++child;
            low[x]=min(low[x],low[t]);
            if((x==1&&child>1)||(x!=1&&low[t]>dfn[x]))
                cut[x]=1;
        }
    }
    visit[x]=1;
}

int main()
{
    #ifdef debug
        freopen("E:\\Documents\\code\\input.txt","r",stdin);
        freopen("E:\\Documents\\code\\output.txt","w",stdout);
    #endif
    scanf("%d",&T);
    int a,b;
    for(int l=1;l<=T;++l)
    {
        scanf("%d %d",&n,&m);
        for(int i=0;i<=n;++i)
            G[i].clear();
        cnt=0;
        cls(visit);
        inf(low);
        st0(cut);
        while(m--)
        {
            scanf("%d %d",&a,&b);
            if(find(G[a].begin(),G[a].end(),b)==G[a].end())
            {
                G[a].push_back(b);
                G[b].push_back(a);
            }
        }
        dfs(1,1,0);
        for(int i=1;i<=n;++i)
            if(cut[i])
                ++cnt;
        printf("Case %d: %d\n",l,cnt);
    }
    return 0;
}
