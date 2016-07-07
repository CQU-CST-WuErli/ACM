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
const int inf = 0x3f3f3f3f;
const int maxn = 1005;
int stx,sty,dx,dy,n,m,k,t;
int dir[4][2] = {0,1,0,-1,1,0,-1,0};
char s[700][700];
int leap[700][700],dis[200][200];
struct Node{
    int x,y;
    Node(int x = 0,int y = 0) : x(x),y(y){}
};
vector<Node>vt;
void init(int id){
    memset(leap,-1,sizeof(leap));
    leap[vt[id].x][vt[id].y] = 0;
    queue<Node>p;
    p.push(Node(vt[id].x,vt[id].y));
    while(p.size()){
        Node temp = p.front();p.pop();
        if(leap[temp.x][temp.y] == k - 1)continue;
        for(int i = 0;i < 4;i++){
            int tempx = temp.x + dir[i][0];
            int tempy = temp.y + dir[i][1];
            if(tempx < 0 || tempx >= n || tempy < 0 || tempy >= m)continue;
            if(s[tempx][tempy] == 'W')continue;
            if(leap[tempx][tempy] != -1)continue;
            leap[tempx][tempy] = leap[temp.x][temp.y] + 1;
            p.push(Node(tempx,tempy));
        }
    }
    /*for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++)
            cout<<leap[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;*/
    for(int i = 0;i < vt.size();i++){
        Node temp = vt[i];
        if(leap[temp.x][temp.y] == -1)
            dis[id][i] = inf;
        else
            dis[id][i] = leap[temp.x][temp.y];
    }
}
int main()
{
	#ifdef LOCAL
	freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
	#endif // LOCAL
	scanf("%d",&t);
	t++;
	while(t--){
        vt.clear();
        scanf("%d%d%d",&n,&m,&k);
        for(int i = 0;i < n;i++)
            scanf("%s",s + i);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(s[i][j] == 'S'){
                    stx = i;sty = j;
                }
                else if(s[i][j] == 'R')
                    vt.push_back(Node(i,j));
                else if(s[i][j] == 'E'){
                    dx = i;dy = j;
                }
            }
        }
        vt.push_back(Node(stx,sty));
        vt.push_back(Node(dx,dy));
        for(int i = 0;i < vt.size();i++){
            for(int j = 0;j < vt.size();j++){
                if(i == j)
                    dis[i][j] = 0;
                else
                    dis[i][j] = inf;
            }
        }
        for(int i = 0;i < vt.size();i++)
            init(i);
        for(int k = 0;k < vt.size();k++)
            for(int i = 0;i < vt.size();i++)
                for(int j = 0;j < vt.size();j++)
                    dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
        /*for(int i = 0;i < vt.size();i++){
            for(int j = 0;j < vt.size();j++){
                cout<<dis[i][j]<<" ";
            }
            cout<<endl;
        }*/
        int ans = dis[vt.size() - 2][vt.size() - 1];
        if(ans == inf)
            printf("Poor RunningPhoton!\n");
        else
            printf("%d\n",ans);
	}
	return 0;
}
