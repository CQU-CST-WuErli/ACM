#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<list>
#include<iomanip>
#define LL long long
#define double long double
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
using namespace std;
const int M = 5e5 + 5;
int dp[2][M];
int A[55];
int main() {
    int T;
    scanf("%d",&T);
    while(T--){
        memset(dp,-1,sizeof(dp));
        int n;
        scanf("%d",&n);
        int sum=0;
        for(int j=1;j<=n;j++){
            scanf("%d",&A[j]);
            sum+=A[j];
        }
        int a=0,b=1;
//        printf("1\n");
        dp[0][0]=0;
        for(int j=1;j<=n;j++){
            for(int k=0;k<=sum;k++){
                if(dp[a][k]==-1) continue;
                dp[b][k]=max(dp[b][k],dp[a][k]);
                //printf("%d %d %d\n",k+A[j],k-A[j],A[j]-k);
                if(k+A[j]<=sum) dp[b][k+A[j]]=max(dp[b][k+A[j]],dp[a][k]);
                if(k>=A[j]){
                    //printf("%d\n",k-A[j]);
                    dp[b][k-A[j]]=max(dp[b][k-A[j]],dp[a][k]+A[j]);
                }
                else{
                    //printf("%d\n",A[j]-k);
                    dp[b][A[j]-k]=max(dp[b][A[j]-k],dp[a][k]+k);
                }
            }
            swap(a,b);
        }
        if(dp[a][0]) printf("%d\n",dp[a][0]);
        else printf("GG\n");
    }
    return 0;
}
