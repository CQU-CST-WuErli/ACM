//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015 CQU_CST_WuErli. All rights reserved.
//
// #include<bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define BigInteger bign
using namespace std;

double g[100][100], dist[100];
bool visit[100];
int n, t_id; 

const double eps = 1e-8;
const double inf = 999999999;

struct Point {
    double x, y;
} door[20][2][2], s, t;

double multi(Point p1, Point p2, Point p0) {
    return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
}

bool cross(Point a, Point b, Point c, Point d) {
    if (multi(a, d, c) * multi(b, d, c) > eps) return false;
    return true;
}

double dis(Point a, Point b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool judge(int i, int j, Point a, Point b) {
     for (; i <= j; i++)
         if (cross(door[i][0][0], door[i][0][1], a, b) == false && cross(door[i][1][0], door[i][1][1], a, b) == false)
            return false;
     return true;
}

void make_map() {
     int i, j, k, l, p, q, x, y;

     for (i = 0; i < n-1; i++)
         for (j = 0; j < 2; j++)
            for (k = 0; k < 2; k++) {
                x = 4*i+2*j+k+1;
                for (l = i + 1; l < n; l++)
                    for (p = 0; p < 2; p++)
                        for (q = 0; q < 2; q++) {
                            y = 4*l+2*p+q+1;
                            if (judge(i+1, l-1, door[i][j][k], door[l][p][q]))
                                g[x][y] = dis(door[i][j][k], door[l][p][q]);
                        }
            }
}

double Dikstra() {
    int i, j, cur;
    double tmp;

    memset(visit, false, sizeof (visit));
    for (i = 1; i <= t_id; i++) dist[i] = inf;
    dist[0] = 0;
    for (i = 0; i <= t_id; i++) {
        tmp = inf;
        cur = -1;
        for (j = 0; j <= t_id; j++)
            if (!visit[j] && dist[j] < tmp) {
                tmp = dist[j];
                cur = j;
            }
        visit[cur] = true;
        if (cur == t_id) break;
        for (j = 0; j <= t_id; j++) {
            if (!visit[j] && g[cur][j] > eps && dist[cur] + g[cur][j] + eps < dist[j])
                dist[j] = dist[cur] + g[cur][j];
        }
    }
    return dist[t_id];
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    double x, y1, y2, y3, y4;
    int i, j, k;
    s.x = 0; s.y = 5;
    t.x = 10; t.y = 5;
    while (scanf ("%d", &n) && n != -1) {
        for (i = 0; i < n; i++) {
            scanf ("%lf%lf%lf%lf%lf", &x, &y1, &y2, &y3, &y4);
            door[i][0][0].x = door[i][0][1].x = door[i][1][0].x = door[i][1][1].x = x;
            door[i][0][0].y = y1; door[i][0][1].y = y2;
            door[i][1][0].y = y3; door[i][1][1].y = y4;
        }
        memset(g, 0, sizeof (g));
        t_id = 4 * n + 1;
        if (judge(0, n-1, s, t)) {
            printf ("%.2lf\n", dis(s, t));
            continue;
        }
        int id;
        for (i = 0; i < n; i++) {
            for (j = 0; j < 2; j++) {
                for (k = 0; k < 2; k++) {
                    id = 4*i+2*j+k+1; 
                    if (judge(0, i-1, s, door[i][j][k])) g[0][id] = dis(s, door[i][j][k]);
                    if (judge(i+1, n-1, door[i][j][k], t)) g[id][t_id] = dis(door[i][j][k], t);
                }
            }
        }
        make_map();
        printf ("%.2lf\n", Dikstra());
    }
    return 0;
}

