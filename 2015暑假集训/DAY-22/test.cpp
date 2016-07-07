#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 2000000000
const int maxn = 1005;
int n,x,add[maxn],cost[maxn],posi[maxn];
double sum[maxn],v;
struct node{
int x,y,z;
bool operator < (const node& rhs) const{
return x < rhs.x;
}
}a[maxn];
double Sum(int i,int j){
return sum[j] - sum[i-1];
}
double d[maxn][maxn][2];
bool vis[maxn][maxn][2];
double dp(int i,int j,int p){
if(vis[i][j][p]) return d[i][j][p];
vis[i][j][p] = true;
if(i==1 && j==n) return d[i][j][p] = 0;
double& ans = d[i][j][p];
bool flag =false;
if(i > 1) { flag=true;
   double t = (posi[p==0 ? i:j] - posi[i-1])*1.0/v;
   ans =dp(i-1,j,0)+(Sum(1,i-1)+Sum(j+1,n))*t+cost[i-1];
}
if(j < n) {
   double t = (posi[j+1] - posi[p==0 ? i:j])*1.0/v;
   if(flag) ans = min(ans,dp(i,j+1,1)+(Sum(1,i-1)+Sum(j+1,n))*t+cost[j+1]);
   else ans =dp(i,j+1,1)+(Sum(1,i-1)+Sum(j+1,n))*t+cost[j+1];
}
return ans;
}
int c;
int main()
{
    while(scanf("%d %lf %d",&n,&v,&x)==3){
        if(!n&&!v&&!x) break;
        for(int i=1;i<=n;i++) {
             scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
        }
        sort(a+1,a+n+1);
        sum[0] = 0; c=0;
        for(int i=1;i<=n;i++){
            posi[i] = a[i].x; cost[i] = a[i].y; add[i] = a[i].z;
            sum[i] = sum[i-1] + add[i];
        }
        memset(vis,false,sizeof(vis));
        double res  = INF;
        for(int i=1;i<=n;i++) {
              double t =(posi[i] - x)*1.0/v;
              if(posi[i] > x){ res = min(res,dp(i,i,0)+Sum(1,n)*t+cost[i]);
              break;
              }
        }
        for(int i=n;i>=1;i--) {
              double t =(x - posi[i])*1.0/v;
                if(posi[i] < x){ res = min(res,dp(i,i,0)+Sum(1,n)*t+cost[i]);
                break;
                }
        }
        printf("%d\n",(int)(res));
    }
    return 0;
}

