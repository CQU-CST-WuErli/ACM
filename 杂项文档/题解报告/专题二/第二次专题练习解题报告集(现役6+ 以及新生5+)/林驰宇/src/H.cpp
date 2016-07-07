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
const int N = 105, M = 1e5 + 10;
int dp[M];
int A[N],B[N];
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int j=1;j<=n;j++) scanf("%d",&A[j]);
        for(int j=1;j<=n;j++) scanf("%d",&B[j]);
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        for(int j=1;j<=n;j++){
            for(int k=0;k<=m;k++){
                if(dp[k]!=-1) dp[k]=B[j];
            }
            for(int k=0;k+A[j]<=m;k++){
                if(dp[k]>0){
                    dp[k+A[j]]=max(dp[k+A[j]],dp[k]-1);
                }
            }
        }
        if(dp[m]!=-1) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
