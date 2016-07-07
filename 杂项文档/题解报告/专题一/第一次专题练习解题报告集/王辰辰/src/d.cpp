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
const int maxn = 1005;
int n,cnt;
int num[4][20],vis[50],dd[50][50];
bool leap[40];
struct Node{
    int l,r,u,d;
}node[40],d[6][6];
void sub(int id){
    num[0][node[id].u]--;
    num[1][node[id].r]--;
    num[2][node[id].d]--;
    num[3][node[id].l]--;
}
void add(int id){
    num[0][node[id].u]++;
    num[1][node[id].r]++;
    num[2][node[id].d]++;
    num[3][node[id].l]++;
}
bool check(int st){
    int y = (st + n - 1)/n;
    int x = st - (y - 1)*n;
    if(y < n){
        for(int i = 1;i <= x;i++)
            if(num[3][d[i][y].r] == 0)return false;
    }
    if(x != n)
        if(num[0][d[x][y].d] == 0)return false;
    if(y > 1){
        for(int i = x + 1;i <= n;i++)
            if(num[3][d[i][y - 1].r] == 0)return false;
    }
    return true;
}
bool dfs(int st){
    bool ok[30];
    memset(ok,false,sizeof(ok));
    if(st == n*n + 1)return true;
    int y = (st + n - 1)/n;
    int x = st - (y - 1)*n;
    for(int i = 1;i <= n*n;i++){
        if(leap[i])continue;
        if(ok[vis[i]])continue;
        if(x > 1){
            if(d[x - 1][y].d != node[i].u)continue;
        }
        if(y > 1){
            if(d[x][y - 1].r != node[i].l)continue;
        }
        leap[i] = true;
        sub(i);
        d[x][y] = node[i];
        //if(check(st)){
            if(dfs(st + 1))return true;
        //}
        ok[vis[i]] = true;
        add(i);
        leap[i] = false;
    }
    return false;
}
void edfs(int st,int tot){
    vis[st] = tot;
    for(int i = 1;i <= n*n;i++){
        if(!dd[st][i])continue;
        if(vis[i])continue;
        edfs(i,tot);
    }
}
bool same(int x,int y){
    if(node[x].d != node[y].d) return false;
    if(node[x].u != node[y].u) return false;
    if(node[x].l != node[y].l) return false;
    if(node[x].r != node[y].r) return false;
    return true;
}
int main()
{
	#ifdef LOCAL
	freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
	#endif // LOCAL
	int t;
	scanf("%d",&t);
	while(t--){
        scanf("%d",&n);
        memset(num,0,sizeof(num));
        for(int i = 1;i <= n*n;i++){
            scanf("%d%d%d%d",&node[i].u,&node[i].r,&node[i].d,&node[i].l);
            num[0][node[i].u]++;
            num[1][node[i].r]++;
            num[2][node[i].d]++;
            num[3][node[i].l]++;
        }
        memset(dd,0,sizeof(dd));
        for(int i = 1;i <= n*n;i++){
            for(int j = i + 1;j <= n*n;j++){
                if(same(i,j))
                    dd[i][j] = 1;
            }
        }
        for(int k = 1;k <= n*n;k++)
            for(int i = 1;i <= n*n;i++)
                for(int j = 1;j <= n*n;j++)
                    dd[i][j] = dd[i][j] | (dd[i][k] && dd[k][j]);
        int tot = 1;
        memset(vis,0,sizeof(vis));
        for(int i = 1;i <= n*n;i++){
            if(vis[i])continue;
            edfs(i,tot);
            tot++;
        }
        int sum = 0;
        /*for(int i = 1;i <= n*n;i++){
            sub(i);
            if(num[0][node[i].d] == 0){
                sum++;
            }
            else if(num[1][node[i].l] == 0){
                sum++;
            }
            else if(num[2][node[i].u] == 0){
                sum++;
            }
            else if(num[3][node[i].r] == 0){
                sum++;
            }
            add(i);
        }*/
        memset(leap,false,sizeof(leap));
        if(/*sum <= n*4 - 4 && */dfs(1))
            printf("Possible\n");
        else
            printf("Impossible\n");
	}
	return 0;
}
