#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<utility>
#include<sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int inf = 0x3f3f3f3f;
const int maxn = 1000100;
const int emaxn = 3200100;
int tot,ans;
int a[maxn],b[maxn];
int ch[emaxn][2];
void add(int x){
    int root = 0;
    for(int i = 30;i >= 0;i--){
        int b = (x >> i)&1;
        if(ch[root][b] == -1)
            ch[root][b] = tot++;
        root = ch[root][b];
    }
}
int query(int x){
    int root = 0,cur = 0;
    for(int i = 30;i >= 0;i--){
        int b = (x >> i)&1;
        if(ch[root][b^1] != -1){
            cur = cur + (1 << i);
            if(cur + (1 << i) <= ans)return 0;
            //cout<<cur<<endl;
            //cout<<i<<" "<<(1 << i)<<endl;
            root = ch[root][b^1];
        }
        else
            root = ch[root][b];
    }
    return cur;
}
int main()
{
	#ifdef LOCAL
	freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
	#endif // LOCAL
	int t,n,m;
	scanf("%d",&t);
	tot = 3000000;
	while(t--){
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        for(int i = 1;i <= m;i++)
            scanf("%d",&b[i]);
        for(int i = 0;i < tot;i++)
            ch[i][0] = ch[i][1] = -1;
        tot = 1;
        for(int i = 1;i <= n;i++)
            add(a[i]);
        ans = -1;
        for(int i = 1;i <= m;i++){
            ans = max(ans,query(b[i]));
        }
        printf("%d\n",ans);
	}
	return 0;
}
