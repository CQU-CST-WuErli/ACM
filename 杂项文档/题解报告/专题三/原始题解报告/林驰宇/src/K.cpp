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
using namespace std;
const int M =5005;
int V;
vector<int>G[M];
vector<int>rG[M];
vector<int>edge[M];
vector<int>vs;
int ans[M],sum[M];
bool used[M];
int cmp[M];
void add_edge(int from,int to){
    G[from].push_back(to);
    rG[to].push_back(from);
}
void dfs(int v){
    used[v]=true;
    for(int j=0;j<G[v].size();j++){
        if(!used[G[v][j]]) dfs(G[v][j]);
    }
    vs.push_back(v);
}
void rdfs(int v,int k){
    used[v]=true;
    cmp[v]=k;
    for(int j=0;j<rG[v].size();j++){
        if(!used[rG[v][j]]) rdfs(rG[v][j],k);
    }
}
int dfs1(int x){
    if(used[x]) return 0;
    used[x]=1;
    int res=sum[x];
    for(int j=0;j<edge[x].size();j++){
        int to=edge[x][j];
        res+=dfs1(to);
    }
    return res;
}
int match[M];
void add_edge(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
}
bool dfs(int v){
    used[v]=true;
    for(int j=0;j<G[v].size();j++){
        int u=G[v][j],w=match[u];
        if(w<0||!used[w]&&dfs(w)){
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
int bipartite_matching(){
    int res=0;
    memset(match,-1,sizeof(match));
    for(int v=0;v<V;v++){
        if(match[v]<0){
            memset(used,0,sizeof(used));
            if(dfs(v)) res++;
        }
    }
    return res;
}

int scc(){
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=0;v<V;v++){
        if(!used[v]) dfs(v);
    }
    memset(used,0,sizeof(used));
    int k=0;
    for(int j=vs.size()-1;j>=0;j--){
        //printf("vs = %d\n",vs[j]);
        if(!used[vs[j]]) rdfs(vs[j],k++);
    }
    return k;
}
int main(){
    int T,cas=1;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int j=0;j<n;j++) G[j].clear(),rG[j].clear(),edge[j].clear();
        memset(ans,0,sizeof(ans));
        for(int j=1;j<=m;j++){
            int a,b;
            scanf("%d%d",&a,&b);
            add_edge(a,b);
        }
        V=n;
        int scc_cnt=scc();
        for(int j=0;j<n;j++){
            for(int k=0;k<rG[j].size();k++){
                int to=rG[j][k];
                //printf("..j = %d k = %d\n",cmp[j],cmp[k]);
                if(cmp[j]!=cmp[to]){
                    //printf("j = %d k = %d\n",cmp[j],cmp[k]);
                    edge[cmp[j]].push_back(cmp[to]);
                }
            }
        }
        int maxx=0;
        memset(sum,0,sizeof(sum));
        for(int j=0;j<n;j++) sum[cmp[j]]++;
        //printf("scc_cnt = %d\n",scc_cnt);
        for(int j=0;j<scc_cnt;j++){
            memset(used,0,sizeof(used));
            ans[j]=dfs1(j)-1;
            //printf("ans[%d] = %d\n",j,ans[j]);
            maxx=max(maxx,ans[j]);
        }
        printf("Case %d: %d\n",cas++,maxx);
        vector<int>res;
        for(int j=0;j<n;j++){
            if(ans[cmp[j]]==maxx) res.push_back(j);
        }
        for(int j=0;j<res.size();j++) printf("%d%c",res[j]," \n"[j==res.size()-1]);
    }
    return 0;
}
