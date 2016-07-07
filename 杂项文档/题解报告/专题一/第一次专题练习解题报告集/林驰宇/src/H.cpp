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
struct node{
    int len;
    short A[9];
    node(){
        len=0;
        memset(A,0,sizeof(A));
    }
};
char dna[]={'A','C','G','T'};
char A[10][10];
int len[10];
int dp[1680000];
queue<node>Q;
int n;
int bfs(){
    while(!Q.empty()) Q.pop();
    node now;
    Q.push(now);
    while(!Q.empty()){
        now=Q.front();Q.pop();
        for(int j=0;j<4;j++){
            int ok=0,ok1=1;
            node nxt=now;
            int cnt=0;
            for(int k=0;k<n;k++){
                if(nxt.A[k]<len[k]){
                    if(A[k][nxt.A[k]]==dna[j]){
                         nxt.A[k]++;
                         ok=1;
                    }
                }
                cnt=cnt*6+nxt.A[k];
                if(nxt.A[k]<len[k]) ok1=0;
            }
            //printf("cnt = %d\n",cnt);
            if(now.len+1>=dp[cnt]) continue;
            dp[cnt]=now.len+1;
            //printf("%d %d\n",now.len,nxt.A[0]);
            nxt.len=now.len+1;
            if(ok1) return nxt.len;
            if(ok) Q.push(nxt);
        }
    }
    return -1;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(dp,63,sizeof(dp));
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            scanf("%s",&A[j]);
            len[j]=strlen(A[j]);
        }
        printf("%d\n",bfs());
    }
    return 0;
}
