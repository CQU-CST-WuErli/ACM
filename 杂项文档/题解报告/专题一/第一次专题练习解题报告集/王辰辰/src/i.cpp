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
int sx,sy,dx,dy,n,m;
int d[60][60][4][5];
char s[60][60];
int dir[4][2] = {-1,0,0,1,1,0,0,-1};
int edir[2] = {-1,1};
struct Node{
    int x,y,dir,b;
    Node(int x = 0,int y = 0,int dir = 0,int b = 0) : x(x),y(y),dir(dir),b(b){}
};
void work(){
    memset(d,-1,sizeof(d));
    d[sx][sy][0][0] = 0;
    queue<Node>p;
    p.push(Node(sx,sy,0,0));
    while(p.size()){
        Node temp = p.front();p.pop();
        int& pre = d[temp.x][temp.y][temp.dir][temp.b];
        for(int i = 0;i < 2;i++){
            int di = (temp.dir + edir[i] + 4)%4;
            int& now = d[temp.x][temp.y][di][temp.b];
            if(now == -1){
                now = pre + 1;
                p.push(Node(temp.x,temp.y,di,temp.b));
            }
        }
        int tempx = temp.x + dir[temp.dir][0];
        int tempy = temp.y + dir[temp.dir][1];
        if(tempx < 0 || tempx >= n || tempy < 0 || tempy >= m)continue;
        if(s[tempx][tempy] == '#')continue;
        int& now = d[tempx][tempy][temp.dir][(temp.b + 1)%5];
        if(now != -1)continue;
        now = pre + 1;
        p.push(Node(tempx,tempy,temp.dir,(temp.b + 1)%5));
    }
    int ans = inf;
    for(int i = 0;i < 4;i++)
        ans = min(ans,d[dx][dy][i][0]);
    if(ans == inf)
        printf("-1\n");
    else
        printf("%d\n",ans);
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
        scanf("%d%d",&n,&m);
        for(int i = 0;i < n;i++)
            scanf("%s",s + i);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(s[i][j] == 'S'){
                    sx = i;sy = j;
                }
                else if(s[i][j] == 'T'){
                    dx = i;dy = j;
                }
            }
        }
        work();
	}
	return 0;
}
