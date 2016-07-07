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
int A[26][5];
int B[] = {2, 3, 0, 1};
int C[5][5];
int edge[26][5];
int sum[26];
int rx[] = { -1, 0, 1, 0};
int ry[] = {0, 1, 0, -1};
int n, nn;
bool mark[5][5];
int flag=0;
bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}
bool check1(int a, int b) {
    return a & (1 << b);
}
void dfs(int x,int y,int cnt){
    if(cnt==nn-1){
        for(int j=0;j<nn;j++){
            if(!sum[j]||
               !check1(C[x][y],j)) continue;
            flag=1;
        }
        return;
    }
    mark[x][y]=1;
    int _back[5][5]={};
    for(int j=0;j<nn;j++){
        if(!sum[j]||!check1(C[x][y],j)) continue;
        //printf("%d %d %d %d %d\n",x,y,C[x][y],j,sum[j]);
        sum[j]--;
        for(int k=0;k<4;k++){
            int x1=x+rx[k],y1=y+ry[k];
            if(!check(x1,y1)||mark[x1][y1]) continue;
            _back[x1][y1]=C[x1][y1];
            C[x1][y1]&=edge[j][k];
        }
        for(int k=0;k<4;k++){
            int x1=x+rx[k],y1=y+ry[k];
            if(!check(x1,y1)||mark[x1][y1]) continue;
            //printf("%d %d %d %d\n",x,y,x1,y1);
            dfs(x1,y1,cnt+1);
            break;
        }
        if(flag) return;
        for(int k=0;k<4;k++){
            int x1=x+rx[k],y1=y+ry[k];
            if(!check(x1,y1)||mark[x1][y1]) continue;
            C[x1][y1]=_back[x1][y1];
        }
        sum[j]++;
    }
    mark[x][y]=0;
}
int main() {
//    freopen("data.in","r",stdin);
    //freopen("D.out","w",stdout);
    //printf("%d\n",__builtin_popcount(10));
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(mark,0,sizeof(mark));
        scanf("%d", &n);
        nn = n * n;
        for(int j = 0; j < nn; j++) {
            for(int k = 0; k < 4; k++) {
                scanf("%d", &A[j][k]);
                edge[j][k] = 0;
            }
            sum[j]=1;
        }
        for(int j=0;j<nn;j++){
            int t=0;
            for(int k=j+1;k<nn;k++){
                int ok=1;
                for(int i=0;i<4;i++){
                    if(A[j][i]!=A[k][i]) ok=0;
                }
                if(ok) t=k;
            }
            if(t){
                //printf("%d %d\n",j,t);
                sum[t]++;
                sum[j]=0;
            }
        }
        //printf("%d\n",sum[nn-1]);
        for(int j = 0; j < nn; j++) {
            for(int k = 0; k < 4; k++) {
                for(int i = 0; i < nn; i++) {
                    //if(j == i) continue;
                    if(A[j][k] == A[i][B[k]]) edge[j][k] |= (1 << i);
                }
            }
        }
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) {
                C[j][k] = (1 << nn) - 1;
            }
        }
        //printf("%d\n",edge[3][2]);
        flag = 0;
        dfs(n / 2, n / 2, 0);
        if(flag) printf("Possible\n");
        else printf("Impossible\n");
    }
    return 0;
}
