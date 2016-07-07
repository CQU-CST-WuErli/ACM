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
#define LL long long
using namespace std;
struct node{
    int A[4][4];
};
bool operator == (node &a,node &b){
    for(int j=0;j<4;j++){
        for(int k=0;k<4;k++){
            if(a.A[j][k]!=b.A[j][k]) return 0;
        }
    }
    return 1;
}
vector<node>ans;
void init(){
    int A[10];
    for(int j=0;j<9;j++) A[j]=j;
    do{
        node now;
        for(int j=0;j<9;j++){
            int x=A[j]/3,y=A[j]%3;
            for(int k=0;k<=1;k++){
                for(int i=0;i<=1;i++){
                    now.A[x+k][y+i]=A[j]+1;
                }
            }
        }
        ans.push_back(now);
    }while(next_permutation(A,A+9));
}
int main(){
    init();
    int T;
    scanf("%d",&T);
    while(T--){
        node now;
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                scanf("%d",&now.A[j][k]);
            }
        }
        int ok=0;
        for(int j=0;j<ans.size();j++){
            if(ans[j]==now){
                ok=1;
                break;
            }
        }
        if(ok) printf("Lucky dog!\n");
        else printf("BOOM!\n");
    }
    return 0;
}
