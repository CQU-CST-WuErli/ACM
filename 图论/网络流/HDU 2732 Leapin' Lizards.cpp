//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015 CQU_CST_WuErli. All rights reserved.
//
// #include<bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;
// 把所有的L点都视作源点，超级源点与该点的容量为1
// 并将所有的能够脱离的有柱子的点视作汇点，与超级汇点的容量为弧尾柱子的数目
// 将所有的能够相连的柱子都相连，容量为弧尾的柱子数

#define RE(x) ((x)^1)
#define CP(x) ((x)+500)

int N, M, MM, dis[1000], head[1000], idx;

const int source=980,sink=981;

char G[25][25], S[25][25];

struct Edge{
    int v,cap,next;
}e[20000];

void init(){ 
    idx=-1;
    memset(head, 0xff, sizeof (head));
}

int ID(int x, int y){
    return x*M+y;
}

bool out(int x, int y){
    int u=x+1,d=N-x,l=y+1,r=M-y;
    int dist=min(u,min(d,min(l,r)));
    return dist<=MM;
}

bool judge(int x, int y){
    if (x < 0 || x >= N || y < 0 || y >= M) {
        return false;
    }
    else if (!G[x][y]) {
        return false;
    }
    return true;
}

void add_edge(int a, int b, int c){
    ++idx;
    e[idx].v=b,e[idx].cap=c;
    e[idx].next=head[a],head[a]=idx;
}

void build(int x, int y){
    int xx, yy;
    if (G[x][y]) {
        add_edge(ID(x,y),CP(ID(x,y)),G[x][y]);
        add_edge(CP(ID(x,y)),ID(x,y),G[x][y]);
        if (out(x,y)) {
            add_edge(CP(ID(x,y)),sink,INF_INT);
            add_edge(sink,CP(ID(x,y)),0);
        }
        else {
            for (int i=-MM;i<=MM;++i) {
                for (int j=-(MM-abs(i));j<=(MM-abs(i));++j) {
                    xx=x+i,yy=y+j;
                    if (judge(xx,yy) && !(x==xx && y==yy)) {
                        add_edge(CP(ID(x,y)),ID(xx,yy),G[x][y]);
                        add_edge(ID(xx,yy),CP(ID(x,y)),0);
                    }
                }
            }
        }
    }
}

bool bfs(int u){
    queue<int>q;
    memset(dis,0xff,sizeof(dis));
    dis[u]=0;
    q.push(u);
    while (!q.empty()) {
        u=q.front();
        q.pop();
        for (int i=head[u];i!=-1;i=e[i].next) {
            if (dis[e[i].v]==-1 && e[i].cap>0) {
                dis[e[i].v]=dis[u]+1;
                q.push(e[i].v);
            }
        }
    }
    return dis[sink]!=-1;
}

int dfs(int u, int flow){
    if (u==sink) {
        return flow;
    }
    int tf=0,sf;
    for (int i=head[u];i!=-1;i=e[i].next) {
        if (dis[u]+1==dis[e[i].v] && e[i].cap>0 && (sf=dfs(e[i].v,min(flow-tf,e[i].cap)))) {
            e[i].cap-=sf,e[RE(i)].cap+=sf;
            tf+=sf;
            if (tf==flow) {
                return flow;
            }
        }
    }
    if (!tf) {
        dis[u]=-1;
    }
    return tf;
}

int Dinic(){
    int ans=0;
    while (bfs(source)) {
        ans+=dfs(source,INF_INT);
    }
    return ans;
}

int main(){
    int T,ca=0,ans;
    scanf("%d", &T);
    while (T--) {
        init();
        ans=0;
        scanf("%d %d",&N,&MM); // M为最长的步长
        for (int i=0;i<N;++i) {
            scanf("%s",G[i]);
        }
        M=strlen(G[0]);
        for (int i=0;i<N;++i) {
            for (int j=0;j<M;++j) {
                G[i][j]-='0';
                build(i,j);
            }
        }
        for (int i=0;i<N;++i) {
            scanf("%s",S[i]);
            for (int j=0;j<M;++j) {
                if (S[i][j]=='L') {
                    ++ans;
                    add_edge(source,ID(i,j),1);
                    add_edge(ID(i,j),source,0);
                }
            }
        }
        ans-=Dinic();
        printf("Case #%d: ", ++ca);
        if (ans==0) {
            puts("no lizard was left behind.");
        }
        else if (ans==1){
            printf("%d lizard was left behind.\n",ans);
        }
        else {
            printf("%d lizards were left behind.\n",ans);
        }
    }
    return 0;
}
