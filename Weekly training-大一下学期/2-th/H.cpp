///////////////////////////////////////////////////////// 
//                           //                        //
//  Created by 吴尔立 			                       //
//  Copyright (c) 2015年 吴尔立. All rights reserved.  //
/////////////////////////////////////////////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>           
#include <algorithm>
#include <cctype>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <set>
#include <vector>
#define ll long long;
#define INF 1<<31
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
using namespace std;
const int maxn = 10005;
int N, M;  //N个路口M条路； 
int A, B, C;   //A到B用时为C
int pnt[maxn], pre[maxn], head[maxn], d[maxn], dis[maxn]; //d[i] 表示从起点到 i 但的最短路 
int counter[maxn], vis[maxn];
int cnt = 0;
 
void addedge(int u, int v, int w) {
    pnt[cnt] = v; pre[cnt] = head[u]; dis[cnt] = w; head[u] = cnt++;
}
 
int spfa(int s) {
    queue<int> q;
    memset(d, -1, sizeof(d));
    CLR(vis);
    d[s] = 0;
    q.push(s);
    vis[s] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i != -1; i = pre[i])   //遍历邻接表 
        {
            int y =  pnt[i];
            if (d[y] == -1 || d[x] + dis[i] < d[y]) {
                d[y] = d[x] + dis[i];
                if (!vis[y]) {
                    vis[y] = 1;
                    q.push(y);
                }
            }
        }
        vis[x] = 0;
    }
    return 0;
}
 
int main() {
    while (scanf("%d%d", &N, &M) != EOF && N != 0 && M != 0) {
        cnt = 0;
        CLR(dis);
        memset(head, -1, sizeof(head));
        cir(i, 1, M) {
            scanf("%d %d %d", &A, &B, &C);
            addedge(A, B, C);
            addedge(B, A, C);
        }
        spfa(1);
        cout << d[N] << endl;
    }
    return 0;
}
