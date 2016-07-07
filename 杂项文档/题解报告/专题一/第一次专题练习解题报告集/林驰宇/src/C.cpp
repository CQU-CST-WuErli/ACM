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
#define LL long long
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
using namespace std;
const int M =1e3+5;
int A[M];
pair<int,int> dp[M][505];
bool mark[M];
void print(pair<int,int> a){
    printf("first = %d second = %d\n",a.first,a.second);
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("C.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        A[0]=1;
        for(int j=1;j<=M-5;j++){
            A[j]=A[j-1]*10%n;
        }
        //printf("%d\n",A[1]);
        memset(dp,-1,sizeof(dp));
        memset(mark,0,sizeof(mark));
        int st=0;
        //printf("1\n");
        for(int j=0;j<=M-5;j++){
            dp[j][0]=make_pair(-2,-2);
            for(int k=0;k<n;k++){
                if(dp[j][k]!=make_pair(-1,-1)){
                    if(j&&k) dp[j+1][k]=dp[j][k];
                }
            }
            for(int k=0;k<n;k++){
                if(dp[j][k]!=make_pair(-1,-1)){
                    if(dp[j+1][(k+A[j])%n]==make_pair(-1,-1)) dp[j+1][(k+A[j])%n]={j,k};
                }
            }
            if(dp[j+1][0]!=make_pair(-1,-1)){
                st=j+1;
                break;
            }
        }
        pair<int,int> now=dp[st][0];
        int t=now.first;
        while(now.first!=-2){
            mark[now.first]=1;
            now=dp[now.first][now.second];
        }
        for(int j=t;j>=0;j--){
            if(mark[j]) printf("1");
            else printf("0");
        }
        printf("\n");
    }
    return 0;
}
