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
double A[M],B[M],sum[M];
double dp[55][M];
int Q[M],t[M];
int L[M],R[M];
int n,m;
double f(int j,int k,int i){
    //printf("%f\n",sum[3]);
    //if(j==6&&k==3) printf("%f %f %f %f %f %d\n",dp[i-1][k],A[j],A[k],sum[k],(B[j]-B[k]));
    return dp[i-1][k]+A[j]-A[k]-sum[k]*(B[j]-B[k]);
}
double getup(int j,int k,int i){
    return dp[i-1][j]-dp[i-1][k]-A[j]+A[k]+B[j]*sum[j]-B[k]*sum[k];
}
double getdown(int j,int k){
    return sum[j]-sum[k];
}
int main(){
    //memset(dp,63,sizeof(dp));
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        memset(dp,0,sizeof(dp));
        memset(Q,0,sizeof(Q));
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));
        memset(sum,0,sizeof(sum));
        memset(L,0,sizeof(L));
        memset(R,0,sizeof(R));
        int j,k;
        for(j=1;j<=n;j++){
            scanf("%d",&t[j]);
            sum[j]=sum[j-1]+t[j];
            A[j]=A[j-1]+sum[j]/t[j];
            B[j]=B[j-1]+1.0/t[j];
        }
        //printf("%f\n",sum[3]);
        for(int j=1;j<=n;j++) dp[0][j]=A[j];
        for(int i=1;i<=m;i++){
            int l=0,r=0;
            for(j=1;j<=n;j++){
                while(r-l>=2&&f(j,Q[l],i)>=f(j,Q[l+1],i)) l++;
                //if(j==6&&i==1) printf("%d %d\n",l,r);
                dp[i][j]=f(j,Q[l],i);
                while(r-l>=2&&getup(j,Q[r-1],i)*getdown(Q[r-1],Q[r-2])<=getup(Q[r-1],Q[r-2],i)*getdown(j,Q[r-1])) r--;
                Q[r++]=j;
            }
        }
        //printf("%.4f %.4f\n",f(6,3,1),dp[0][3]);
        printf("%.4f\n",dp[m-1][n]);
    }
    return 0;
}
