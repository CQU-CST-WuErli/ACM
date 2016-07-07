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
const int M = 5e6 + 5;
int f[M];
void getfail(char* P, int *f) {
    int m = strlen(P);
    int j;
    f[0] = f[1] = 0;
    for(j = 1; j < m; j++) {
        int t = f[j];
        while(t && P[t] != P[j]) t = f[t];
        f[j + 1] = P[t] == P[j] ? t + 1 : 0;
    }
}
char A[M], B[M], C[M];
bool mark[M];
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(mark,0,sizeof(mark));
        scanf("%s%s%s",A,B,C);
        int a=strlen(A),b=strlen(B),c=strlen(C);
        getfail(B,f);
        int t=0;
        for(int j=0;j<a;j++){
            while(t&&A[j]!=B[t]) t=f[t];
            if(A[j]==B[t]) t++;
            if(t==b){
                mark[j-b+1]=1;
                t=0;
            }
        }
        for(int j=0;j<a;){
            if(mark[j]){
                printf("%s",C);
                j+=b;
            }
            else printf("%c",A[j++]);
        }
        printf("\n");
    }
    return 0;
}
