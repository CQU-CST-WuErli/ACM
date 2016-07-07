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
const int M =1e4+5,INF=1e9;
struct node{
    int to,cap,dis;
};
vector<node>edge[M];
int dis[M];
bool mark[M];
int n,m,K;
bool spfa(int x){
    for(int j=1;j<=n;j++){
        dis[j]=INF;
        mark[j]=0;
    }
    queue<int>Q;
    Q.push(1);
    dis[1]=0;
    while(!Q.empty()){
        int now=Q.front();Q.pop();
        mark[now]=0;
        for(int j=0;j<edge[now].size();j++){
            node &t=edge[now][j];
            if(t.cap<x) continue;
            if(dis[t.to]>dis[now]+t.dis){
                dis[t.to]=dis[now]+t.dis;
                if(!mark[t.to]){
                    Q.push(t.to);
                    mark[t.to]=1;
                }
            }
        }
    }
    //printf("dis = %d\n",dis[n]);
    return dis[n]<=K;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&K);
        for(int j=1;j<=n;j++) edge[j].clear();
        for(int j=1;j<=m;j++){
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            edge[a].push_back((node){b,c,d});
            edge[b].push_back((node){a,c,d});
        }
        int l=0,r=2e9;
        int res=-1;
        //printf("%d\n",spfa(1));
        while(l<=r){
            int mid=(LL)l+r>>1LL;
            if(spfa(mid)){
                res=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        if(res==-1) printf("Poor RunningPhoton!\n");
        else printf("%d\n",res);
    }
    return 0;
}
