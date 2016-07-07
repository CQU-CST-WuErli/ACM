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
#define mod 1000000000
#define INF 1061109567
#define LL long long
#define M 500005
using namespace std;
LL A[M];
LL dp[M],X[M];
int Q[M];
int n,m;
LL f(int j,int k){
    return dp[k]+(X[j]-X[k+1])*(X[j]-X[k+1])+m;
}
LL getup(int j,int k){
    return dp[j]-dp[k]+X[j+1]*X[j+1]-X[k+1]*X[k+1];
}
LL getdown(int j,int k){
    return 2*(X[j+1]-X[k+1]);
}
int main(){
    //memset(dp,63,sizeof(dp));
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        memset(dp,0,sizeof(dp));
        memset(Q,0,sizeof(Q));
        int j,k;
        for(j=1;j<=n;j++){
            scanf("%lld",&X[j]);
        }
        int l=0,r=0;
        for(j=1;j<=n;j++){
            while(r-l>=2&&f(j,Q[l])>=f(j,Q[l+1])) l++;
            dp[j]=min(f(j,0),f(j,Q[l]));
            while(r-l>=2&&getup(j,Q[r-1])*getdown(Q[r-1],Q[r-2])<=getup(Q[r-1],Q[r-2])*getdown(j,Q[r-1])) r--;
            Q[r++]=j;
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
