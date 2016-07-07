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
const int M =1e7+5;
struct trie{
    int ch[M][2];
    int root,L;
    int newnode(){
        ch[L][0]=ch[L][1]=-1;
        return L++;
    }
    void init(){
        L=0;
        root=newnode();
    }
    void insert(int x){
        int now=root;
        for(int j=30;j>=0;j--){
            int go=(x&(1<<j))?1:0;
            if(ch[now][go]==-1){
                ch[now][go]=newnode();
                now=ch[now][go];
            }
            else now=ch[now][go];
        }
    }
    int query(int x){
        int now=root;
        int ans=0;
        for(int j=30;j>=0;j--){
            int go=(x&(1<<j))?1:0;
            //printf("%d %d %d\n",j,go,ch[now][!go]);
            if(ch[now][!go]!=-1) ans|=(1<<j),now=ch[now][!go];
            else now=ch[now][go];
        }
        //printf("ans = %d\n",ans);
        return ans;
    }
}trie;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        trie.init();
        int n,m;
        scanf("%d%d",&n,&m);
        for(int j=1;j<=n;j++){
            int a;
            scanf("%d",&a);
            trie.insert(a);
        }
        int ans=0;
        for(int j=1;j<=m;j++){
            int a;
            scanf("%d",&a);
            ans=max(ans,trie.query(a));
        }
        printf("%d\n",ans);
    }
    return 0;
}
