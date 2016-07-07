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
#include<cmath>
#define LL long long
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
using namespace std;
string A[]={"B","KB","MB","GB","TB","PB","EB","ZB","YB"};
int main(){
    int T,cas=1;
    scanf("%d",&T);
    while(T--){
        char B[5];
        int c;
        scanf("%d[%s",&c,B);
        double a=1000.0/1024.0;
        int n=strlen(B);
        B[n-1]='\0';
        //printf("%s\n",B);
        for(int j=0;j<9;j++){
            if(A[j]==B){
                //printf("j = %d\n",j);
                a=pow(a,j);
                break;
            }
        }
        printf("Case #%d: %.2f%%\n",cas++,(1-a)*100);
    }
    return 0;
}
