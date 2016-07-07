#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define mem(a) memset(a,0,sizeof a)
typedef long long ll;
int mp[505][505];  //有向图
int con[505][505]; //无向图
int f[505];
int flag[505];
int c ;
void init(int n)
{
        for(int i = 1 ; i <= n ; i ++)
                f[i] = i;
        return ;
}
int find(int x)
{
        int t = x;
        while(t != f[t])
                t = f[t];
        int k = x;
        while(k != t)
        {
                int temp = f[k];
                f[k] = t;
                k = temp;
        }
        return t;
}
void judge(int n,int cur)
{
        int i;
        flag[cur] = 1;
        c ++;
        for( i = 1 ; i <= n; i++ )
                if( con[cur][i] && !flag[i] )
                        judge(n,i);
}

int dfs(int n)  //无向图判断是否欧拉通路
{
        int cnt = 0;
        for(int i = 1 ; i <= n ; i ++)
        {
                int tmp = 0;
                for(int j = 1 ; j <= n ; j ++)
                {
                        if(con[i][j] == 1) //度数
                                tmp ++;
                }
                if(tmp % 2 == 1)
                        cnt++;
        }
        if(cnt == 0 || cnt == 2)
                return 1;
        else
                return 0;
}

int dfs1(int n)  //有向图判断是否欧拉通路
{
        int cnt1 = 0,cnt2 = 0,cnt3 = 0;
        for(int i = 1 ; i <= n ; i ++)
        {
                for(int j = 1 ; j <= n ; j ++)
                {
                        if(mp[i][j] == 1)
                        {
                                flag[i] ++; // 出度
                                flag[j] --; // 入度
                        }
                }
        }
        for(int i = 1 ; i <= n ; i ++)
        {
                if(flag[i] == 0)
                        cnt3 ++;
                else if(flag[i] == 1)
                        cnt1 ++;
                else if(flag[i] == -1)
                        cnt2 ++;

        }
        if(cnt3 == n-2 && cnt1 == 1 && cnt2 == 1)
                return 1;
        else if( cnt3 == n)
                return 1;
        else
                return 0;
}
int main()
{
        int t;
        scanf("%d",&t);
        while(t--)
        {
                memset(mp,0,sizeof mp);
                mem(con);
                int m,n;
                scanf("%d %d",&n,&m);
                mem(flag);
                init(n);
                for(int i = 0 ; i < m ; i ++)
                {
                        int a,b;
                        scanf("%d %d",&a,&b);
                        mp[a][b] = 1;
                        con[a][b] = con[b][a] = 1;
                        if(a > b)
                                f[a] = b;
                        else
                                f[b] = a ;
                }
                int ans1,ans2;
                c = 0;
                judge(n,1);
                c -= n;
                mem(flag);
                ans1 = dfs(n); //无向图
                ans2 = dfs1(n);//有向图
                if(ans1 && c == 0) // 无向图
                       printf("Yes ");
                else
                        printf("No ");
                if(ans2 && c == 0) //有向图
                        printf("Yes\n");
                else
                        printf("No\n");
        }
        return 0;
}
/*
1
9 9
1 2
2 3
4 5
3 4
7 8
6 7
5 6
9 1
8 9
Yes No
*/
