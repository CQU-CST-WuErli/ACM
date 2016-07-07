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
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;
const int MAX=2e5+100;
int n;
int a[MAX];
int ans[MAX];
int l[MAX],r[MAX];
stack<pair<int,int> > s;

int main ( )
{
    while ( ~scanf ( "%d" , &n ) )
    {
        memset ( ans , 0 , sizeof ( ans ) );
        for ( int i = 0 ; i < n ; i++ )
            scanf ( "%d" , &a[i] );
        //s.clear();
        while ( !s.empty() ) s.pop();
        l[0] = 0;
        s.push( make_pair ( a[0] , 0 ) );
        for ( int i = 1 ; i < n ; i++ )
        {
            while ( !s.empty() && s.top().first >= a[i] )
                s.pop();
            //cout << "YES : " << i  << endl;
            if ( !s.empty() ) l[i] = s.top().second+ 1;
            else l[i] = 0;
            s.push ( make_pair ( a[i] , i ) );
        }
        //cout << "YES" << endl;
        //s.clear();
        while ( !s.empty() ) s.pop();
        r[n-1] = n-1;
        s.push ( make_pair ( a[n-1] , n-1 ) );
        for ( int i = n-2 ; i >= 0 ; i-- )
        {
            while ( !s.empty() && s.top().first >= a[i] )
                s.pop();
            if ( !s.empty() ) r[i] = s.top().second - 1;
            else r[i] = n-1;
            s.push ( make_pair ( a[i] , i ) );
        }
        for ( int i = 0 ; i < n ; i++ )
            ans[r[i]-l[i]+1] = max ( a[i] , ans [r[i]-l[i]+1] );
        for ( int i = n-1 ; i >= 1 ; i-- )
            ans[i] = max ( ans[i] , ans[i+1] );
        for ( int i = 1; i <= n ; i++ )
            printf ( "%d " , ans[i] );
        puts("");
    }
}
