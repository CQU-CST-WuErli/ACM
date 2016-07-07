#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<climits>
#define LL long long
using namespace std;
const int M =505;
int mp[M][M];
int ok;
int mark[M];
bool mark1[M];
int n,m;
void dfs(int x){
    //printf("%d\n",x);
    if(!ok) return;
    for(int j=1;j<=n;j++){
        if(x==j) continue;
        if(mp[x][j]){
            if(mark[j]==-1){
                mark[j]=mark[x]^1;
                dfs(j);
            }
            else{
                if(!(mark[x]^mark[j])) ok=0;
            }
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(mp,0,sizeof(mp));
        memset(mark,-1,sizeof(mark));
        memset(mark1,0,sizeof(mark1));
        scanf("%d%d",&n,&m);
        for(int j=1;j<=m;j++){
            int a,b;
            scanf("%d%d",&a,&b);
            mp[a][b]=1;
            mp[b][a]=1;
        }
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(j==k) continue;
                mp[j][k]^=1;
                if(mp[j][k]==1) mark1[j]=1,mark1[k]=1;
                //printf("%d %d %d\n",j,k,mp[j][k]);
            }
        }
        ok=1;
        for(int j=1;j<=n;j++){
            if(mark[j]==-1&&mark1[j]) mark[j]=0,dfs(j);
        }
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(j==k) continue;
                if(mark[j]==-1||mark[k]==-1) continue;
                if((mark[j]^mark[k])&&!mp[j][k]) ok=0;
            }
        }
        if(ok){
            printf("Yes\n");
        }
        else printf("No\n");
    }
    return 0;
}
