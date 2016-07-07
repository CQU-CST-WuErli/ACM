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
vector<int>edge[505],edge1[505];
int in[505],out[505];
int fa[505];
int cnt=0;
bool mark[505];
int n,m;
void init(){
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    memset(mark,0,sizeof(mark));
    for(int j=1;j<=n;j++) edge[j].clear(),edge1[j].clear();
    for(int j=1;j<=n;j++) fa[j]=j;
}
int get(int x){
    if(fa[x]!=x) return fa[x]=get(fa[x]);
    return x;
}
void merge(int x,int y){
    //printf("fa = %d\n",fa[x]);
    int a=get(x),b=get(y);
    //printf("%d %d %d %d\n",x,y,a,b);
    fa[a]=b;
}
void dfs(int x){
    cnt++;
    mark[x]=1;
    for(int j=0;j<edge[x].size();j++){
        int to=edge[x][j];
        if(!mark[to]) dfs(to);
    }
}
void solve1(){
    int num=0;
    for(int j=1;j<=n;j++){
        if((in[j]+out[j])&1) num++;
    }
    cnt=0;
    dfs(1);
    //printf("%d\n",cnt);
    if((num!=2&&num!=0)||cnt!=n) printf("No");
    else printf("Yes");
}
void solve2(){
    int a=0,b=0;
    int ok=1;
    for(int j=1;j<=n;j++){
        if(in[j]-out[j]==1) a++;
        else if(out[j]-in[j]==1) b++;
        else if(out[j]!=in[j]) ok=0;
    }
    int sum=0;
    for(int j=1;j<=n;j++){
        //printf("j = %d get(j) = %d\n",j,get(j));
        if(get(j)==j) sum++;
    }
    //printf("sum = %d\n",sum);
    if(sum!=1) ok=0;
    if(!ok) printf(" No\n");
    else{
        if((a==1&&b==1)||(a==0&&b==0)) printf(" Yes\n");
        else printf(" No\n");
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        init();
        //printf("%d\n",fa[1]);
        for(int j=1;j<=m;j++){
            int a,b;
            scanf("%d%d",&a,&b);
            out[a]++;in[b]++;
            edge[a].push_back(b);
            edge[b].push_back(a);
            merge(a,b);
        }
        //for(int j=1;j<=n;j++) printf("%d %d\n",j,fa[j]);
        solve1();
        solve2();
    }
    return 0;
}
