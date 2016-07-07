//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015Äê CQU_CST_WuErli. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <time.h>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <unordered_map>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;


const int maxn=20+5;

int mp[maxn][maxn],vis[maxn][maxn][maxn];
int m,n,k,ans;

int dir[4][2]={1,0,0,1,-1,0,0,-1};

struct Node{
    int x,y;
    int cnt;
    int k;
};


int bfs(){
    queue<Node> q;
    Node u;
    u.x=0;u.y=0;u.cnt=0;u.k=k;
    vis[0][0][k]=1;
    q.push(u);
    while (!q.empty()){
        u=q.front();q.pop();
        if (u.x==n-1&&u.y==m-1){
            ans=u.cnt;
            return 0;
        }
        Node v;
        if (u.k>=0)   
        for (int i=0;i<4;i++){
            v.x=u.x+dir[i][0];
            v.y=u.y+dir[i][1];
            v.cnt=u.cnt+1;
            if (mp[v.x][v.y]) v.k=u.k-1;
                    else v.k=k;  
            if (v.x>=0&&v.x<n&&v.y>=0&&v.y<m&&!vis[v.x][v.y][v.k]){
                if (v.k>=0) {q.push(v);vis[v.x][v.y][v.k]=1;}
            }
        }
    }
    if (q.empty()) ans=-1;
}
int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//  freopen("C:\\Users\\john\\Desktop\\out.txt","r",stdout);
#endif
    int T;
    cin>>T;
    while (T--){
        memset(mp,0,sizeof(mp));
  	 	memset(vis,0,sizeof(vis));
   		cin>>n>>m>>k;
   		for (int i=0;i<n;i++)
       		for (int j=0;j<m;j++)
            	cin>>mp[i][j];
        bfs();
        cout<<ans<<endl;
    }
}
