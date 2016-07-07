#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <sstream>
#include <stack>
using namespace std;

#define cls(x) memset(x,0,sizeof x)
#define inf(x) memset(x,0x3f,sizeof x)
#define neg(x) memset(x,-1,sizeof x)
#define ninf(x) memset(x,0xc0,sizeof x)
#define st0(x) memset(x,false,sizeof x)
#define st1(x) memset(x,true,sizeof x)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define bug cout<<"here"<<endl;
//#define debug

int area[16][4]={{1,0,0,0},{1,2,0,0},{2,3,0,0},{3,0,0,0},
                 {1,4,0,0},{1,2,4,5},{2,3,5,6},{3,6,0,0},
                 {4,7,0,0},{4,5,7,8},{5,6,8,9},{6,9,0,0},
                 {7,0,0,0},{7,8,0,0},{8,9,0,0},{9,0,0,0}};
bool G[10][10];
int T;
int visit[10];

bool dfs(int x)
{
    visit[x]=-1;
    for(int i=1;i<=9;++i)
    {
        if(G[x][i])
        {
            if(visit[i]==-1)
                return false;
            if(!visit[i]&&!dfs(i))
                return false;
        }
    }
    visit[x]=1;
    return true;
}

bool toposort()
{
    cls(visit);
    for(int i=1;i<=9;++i)
        if(!visit[i]&&!dfs(i))
            return false;
    return true;
}

int main()
{
    #ifdef debug
        freopen("E:\\Documents\\code\\input.txt","r",stdin);
        freopen("E:\\Documents\\code\\output.txt","w",stdout);
    #endif
    scanf("%d",&T);
    int a=0;
    bool chk=0;
    while(T--)
    {
        int a=0;
        st0(G);
        for(int i=0;i<16;++i)
        {
            scanf("%d",&a);
            chk=0;
            for(int j=0;j<4;++j)
            {
                G[area[i][j]][a]=1;
                if(area[i][j]==a)
                {
                    chk=1;
                    G[a][a]=0;
                }
            }
            if(!chk)
                break;
        }
        if(chk&&toposort())
            printf("Lucky dog!\n");
        else
            printf("BOOM!\n");
    }

    return 0;
}
