#include<iostream>  
#include<cstdio>  
#include<cstring> 
#include <cmath> 
#include<stack>
#include<vector>
#include<map> 
#include<set>
#include<queue> 
#include<algorithm>  
using namespace std;

#define foreach(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

typedef long long LL;
const int INF = (1<<30)-1;
const int mod=1000000007;
const int maxn=1000005;

int p[maxn],q[maxn];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int T;
    scanf("%d",&T);
    int kase=0;
    while(T--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++) cin>>p[i];
        for(int i=0;i<n;i++) cin>>q[i];
        
        int pos;
        int i=0,flag;
        while(i<n){
            int ans=0;
            flag=1;
            
            for(int j=0;j<n;j++){
                pos=(j+i)%n;
        
                ans+=p[pos];
                ans-=q[pos];
                if(ans<0){
                    flag=0;
                    break;
                }
            }
            
            if(flag) break;
            if(pos<i) {//重复了，说明已经枚举完一圈可能的，都还是没有找到可能的起点，跳出 
                flag=0;break;
            }
            i=pos+1;
        }
    
        printf("Case %d: ",++kase);
        if(flag) printf("Possible from station %d\n",i+1);
        else printf("Not possible\n");    
    }
    return 0;
}
