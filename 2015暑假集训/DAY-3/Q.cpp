//
//  Created by  CQUWEL
//  Copyright (c) 2015年 CQUWEL. All rights reserved.
//
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
#include <numeric>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define filetest
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int len=1e6+100;
int ele[len];
int totv;

int main(){
#ifdef LOCAL
	   freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
    int m,n;
    int cnt = 1;
    while(cin >> m >> n && m && n){
        printf("Region %d\n",cnt++);
        int N=m*n;
        for(int i=0; i<N;i++) scanf("%d",&ele[i]);
        sort(ele,ele+N);
        scanf("%d",&totv);
        int check=0;
        double meters=ele[0];//水平面海拔
        int i;
        for(i=1;i<m*n;i++){
            int v = totv;
            if(v == 0) break;
            v -= (ele[i]-ele[i-1])*i*100;
            if(v >= 0){ 
                totv=v;
                meters=ele[i];
            }
            else{ 
                meters += ( (totv*1.0)/(100*i) );
                totv=0;
            }
            check++;
        }
        if(i == N){ 
            check++;
            meters += ( (totv*1.0)/(100*i) );
        }
        printf("Water level is %.2lf meters.\n",meters);
        printf("%.2lf percent of the region is under water.\n\n",(check*1.0)/(m*n)*100);
    }
    return 0;
}
