//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
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
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for(int flag=start;flag>=end;flag--)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n,m;
struct Edge
{
    int u,v,dis;
    Edge(){}
    Edge(int u,int v,int dis):u(u),v(v),dis(dis){}
};
vector<Edge> es;

int pre[1010],id[1010],vis[1010],in[1010];
int index;

int DirectedMST(int root,int n,int m) {
    int ret=0;
    for (;;) {
        for (int i=0;i<=n;i++) in[i]=INF_INT;
        for (int i=0;i<es.size();i++) {
            int u=es[i].u,v=es[i].v;
            if (es[i].dis<in[v] && u!=v) {
                pre[v]=u;
                in[v]=es[i].dis;
                if (u==root) index=i;
            }
        }
        for (int i=0;i<=n;i++)
            if (i!=root && in[i]==INF_INT) return -1;
        int cntnode=0;
        memset(vis,-1,sizeof vis);
        memset(id,-1,sizeof id);
        in[root]=0;
        for (int i=0;i<=n;i++) {
            ret+=in[i];
            int v=i;
            while(id[v]==-1 && v!=root && vis[v]!=i) {
                vis[v]=i;v=pre[v];
            }
            if (v!=root && id[v]==-1) {
                for (int u=pre[v];u!=v;u=pre[u])
                    id[u]=cntnode;
                id[v]=cntnode++;
            }
        }
        if (cntnode==0) break;
        for (int i=0;i<=n;i++)
            if (id[i]==-1) id[i]=cntnode++;
        for (int i=0;i<es.size();i++) {
            int v=es[i].v;
            es[i].u=id[es[i].u];
            es[i].v=id[es[i].v];
            if (es[i].u!=es[i].v)
                es[i].dis-=in[v];
        }
        n=cntnode-1;			// attention
        root=id[root];
    }
    return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SII(n,m)==2) {
        es.clear();
        int sum=1;
        rep(i,1,m) {
            int u,v,dis;
            SIII(u,v,dis);
            sum+=dis;
            // cout << u << ' ' << v << ' ' << dis << endl;
            es.push_back(Edge(u,v,dis));
        }
        // lookln(sum);
        rep(i,0,n-1) es.push_back(Edge(n,i,sum));
         // lookln(es.size());
        ll ans=DirectedMST(n,n,m);
        // lookln(ans);
        if (ans==-1LL || ans-sum>=sum) puts("impossible");
        else cout << ans-sum <<' ' <<  index-m << endl;
        puts("");
    }
    return 0;
}