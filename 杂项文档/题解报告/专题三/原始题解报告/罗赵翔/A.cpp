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

const int maxn=5050;
int n,m;
vector<int> G[maxn];
vector<int> G1[maxn];
int indegree[maxn],outdegree[maxn],degree[maxn];
bool visit[maxn];

int beg;

void init()
{
    beg=-1;
    for(int i=0;i<=n;++i)
    {
        G[i].clear();
        G1[i].clear();
    }
    cls(indegree);
    cls(outdegree);
    cls(degree);
    return;
}

void DFS(int x)
{
    if(visit[x])
        return;
    visit[x]=1;
    for(int i=0;i<G[x].size();++i)
        if(!visit[G[x][i]])
            DFS(G[x][i]);
    return;
}

void DFS1(int x)
{
    if(visit[x])
        return;
    visit[x]=1;
    for(int i=0;i<G1[x].size();++i)
        if(!visit[G1[x][i]])
            DFS(G1[x][i]);
    return;
}

bool chk()
{
    st0(visit);
    for(int i=1;i<=n;++i)
        DFS(i);
    for(int i=1;i<=n;++i)
        if(visit[i]==0&&degree[i]!=0)
            return false;
    return true;
}

bool chk1()
{
    if(beg==-1)
        return true;
    st0(visit);
    DFS1(beg);
    for(int i=1;i<=n;++i)
        if(visit[i]==0&&degree[i]!=0)
            return false;
    return true;
}

bool ind()
{
    int odd=0;
    for(int i=1;i<=n;++i)
    {
        if(degree[i]%2!=0)
            ++odd;
        if(odd>2)
            return false;
    }
    if(odd==1)
        return false;
    return true;
}

bool dir()
{
    int more=0,les=0;
    for(int i=1;i<=n;++i)
    {
        if(indegree[i]==outdegree[i])
            continue;
        else if(indegree[i]+1==outdegree[i])
        {
            beg=i;
            ++more;
        }
        else if(indegree[i]==outdegree[i]+1)
            ++les;
        else
            return false;
        if(more>1||les>1)
            return false;
    }
    if(more!=les)
        return false;
    return true;
}

int main()
{
    #ifdef debug
        freopen("E:\\Documents\\code\\input.txt","r",stdin);
        freopen("E:\\Documents\\code\\output.txt","w",stdout);
    #endif
    int T=0;
    int a,b;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        if(m==0&&n!=1)
        {
            printf("No No\n");
            continue;
        }
        init();
        while(m--)
        {
            scanf("%d %d",&a,&b);
            G1[a].push_back(b);
            G[a].push_back(b);
            G[b].push_back(a);
            ++indegree[b];++outdegree[a];++degree[a];++degree[b];
        }
        bool cont=chk();
        bool a1=cont&&ind();
        bool a2=cont&&dir()&&chk1();
        if(a1)
            printf("Yes ");
        else
            printf("No ");
        if(a2)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
