//
//  Created by  CQUWEL
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.
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

const int MAX=110;
char a[MAX], b[MAX];
int n[MAX];
int main()
{
#ifdef LOCAL
	  freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
    while(scanf("%s%s", a, b) == 2)
    {
        bool ok = true;
        memset(n, 0, sizeof(n));
        for(int i = 'A'; i <= 'Z'; i ++)
        {
            int cnt = 0;
            for(int j = 0; a[j]; j ++) if(a[j] == i) ++ cnt;
            ++ n[cnt];
            cnt = 0;
            for(int j = 0; b[j]; j ++) if(b[j] == i) ++ cnt;
            -- n[cnt];
        }
        for(int i = 1; i <= 100; i ++) if(n[i]) ok = false;
        puts(ok ? "YES" : "NO");
    }
    return 0;
}
