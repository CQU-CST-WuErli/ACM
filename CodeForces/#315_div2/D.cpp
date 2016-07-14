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
#include <ctime>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <functional>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define for_uva if (kase!=1) cout << endl
#define BUG(x) cout << "I am in line" << x << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int INF=0x3f3f3f3f;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;
const int MOD=1e9+7;
long long  a[5000][5000];
int main()
{
    int n;
    while(cin>>n)
    {
        CLR(a);
        a[1][1]=1;
        for (int i=2;i<=n+1;i++){
        	a[i][1]=a[i-1][i-1];
//        	cout << a[i][1] << endl;
        	for (int j=2;j<=i;j++){
        		a[i][j]=(a[i][j-1]+a[i-1][j-1])%MOD;
        	}
        }
        cout << a[n+1][n] << endl;
    }
    return 0;
}
