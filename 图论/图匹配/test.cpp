#include <queue>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define N 200 + 5

using namespace std;

typedef struct
{
   int num ,v;
   double x ,y ,z;
}NODE;

typedef struct
{
   double dis;
   int v ,id;
}ZT;

NODE node1[N] ,node2[N];
ZT zt[N];
int map[N][N] ,G_b[N][N];
int nowb[N] ,nowg[N];
int mark[N][N];

bool camp(ZT a ,ZT b)
{
   return a.dis < b.dis || a.dis == b.dis && a.v > b.v;
}

void Marr(int n)
{
   queue<int>q;
   for(int i = 1 ;i <= n ;i ++)
   q.push(i);
   memset(mark ,0 ,sizeof(mark));
   memset(nowb ,255 ,sizeof(nowb));
   memset(nowg ,255 ,sizeof(nowg));
   while(!q.empty())
   {
      int xin ,tou = q.front();
      q.pop();
      for(int i = 1 ;i <= n ;i ++)
      {
         xin = map[tou][i];
         if(mark[tou][xin]) continue;
         mark[tou][xin] = 1;
         if(nowg[xin] == -1)
         {
            nowg[xin] = tou;
            nowb[tou] = xin;
            break;
         }
         else
         {
            if(G_b[xin][tou] > G_b[xin][nowg[xin]])
            {
               q.push(nowg[xin]);
               nowg[xin] = tou;
               nowb[tou] = xin;
               break;
            }
         }
      }
   }
   return;
}

double get_dis(NODE a ,NODE b)
{
   double xx = (a.x - b.x) * (a.x - b.x);
   double yy = (a.y - b.y) * (a.y - b.y);
   double zz = (a.z - b.z) * (a.z - b.z);
   return xx + yy + zz;
}


int main ()
{
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
   int t ,n ,i ,j;
   scanf("%d" ,&t);
   while(t--)
   {
      scanf("%d" ,&n);
      for(i = 1 ;i <= n ;i ++)
      scanf("%d %d %lf %lf %lf" ,&node1[i].num ,&node1[i].v ,&node1[i].x ,&node1[i].y ,&node1[i].z);
      for(i = 1 ;i <= n ;i ++)
      scanf("%d %d %lf %lf %lf" ,&node2[i].num ,&node2[i].v ,&node2[i].x ,&node2[i].y ,&node2[i].z);
      for(i = 1 ;i <= n ;i ++)
      {
         for(j = 1 ;j <= n ;j ++)
         {
            zt[j].dis = get_dis(node1[i] ,node2[j]);
            zt[j].v = node2[j].v;
            zt[j].id = j;
            // cout << zt[j].dis << endl;
         }
         sort(zt + 1 ,zt + n + 1 ,camp);
         for(j = 1 ;j <= n ;j ++)
         map[i][j] = zt[j].id;
      }
      // for (int i=1;i <= n; i++) {
      // 	for (int j = 1; j <= n; j++) cout << map[i][j] << ' ';
      // 	cout << endl;
      // }
      for(i = 1 ;i <= n ;i ++)
      {
         for(j = 1 ;j <= n ;j ++)
         {
            zt[j].dis = get_dis(node2[i] ,node1[j]);
            // cout << node1[j].num << ' ' << node1[j].v << ' ' << node1[j].x << ' ' << node1[j].y << ' ' << node1[j].z << endl;
           // cout << zt[j].dis << endl;
           zt[j].v = node1[j].v;
            zt[j].id = j;
         }
         sort(zt + 1 ,zt + n + 1 ,camp);
         for(j = 1 ;j <= n ;j ++)
         G_b[i][zt[j].id] = n - j + 1;
      }
      // for (int i = 1; i <= n; i++) {
      // 	for (int j = 1; j <= n; j++) cout << G_b[i][j] << ' ' ;
      // 		cout << endl;
      // }
      Marr(n);
      for(i = 1 ;i <= n ;i ++)
      printf("%d %d\n" ,node1[i].num ,node2[nowb[i]].num);
      puts("");
   }
   return 0;
}