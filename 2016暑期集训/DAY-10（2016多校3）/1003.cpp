//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#include <bitset>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d", &a)
#define SII(a,b) scanf("%d%d", &a, &b)
#define SIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n, m, type;
int king[1100][1100];
int knight[1100][1100];

int KING(int x,int y)
{
    if(king[x][y]!=-1 || king[y][x]!=-1 ) return king[x][y];
    if(x>1) if( !KING(x-1,y) ) return king[x][y] = king[y][x] = 1;
    if(y>1) if( !KING(x,y-1) ) return king[x][y] = king[y][x] = 1;
    if(x>1 && y>1) if( !KING(x-1, y-1) ) return king[x][y] = king[y][x] = 1;
    return king[x][y]=king[y][x]=0;
}

int KNIGHT(int x,int y)
{
    if(~knight[x][y] || ~knight[y][x]) return knight[x][y];
    if( (x-1<=0 || y-2<=0) && (x-2<=0 || y-1<=0) ) return knight[y][x] = knight[x][y] = 2;

    int ok0=2, ok1=2;
    if(x-1>0 && y-2>0) ok0 = KNIGHT(x-1, y-2);
    if(x-2>0 && y-1>0) ok1 = KNIGHT(x-2, y-1);
    if(ok0==0 || ok1==0 ) return knight[x][y] = knight[y][x] = 1;
    if( ok0==1 && ok1==1 ) return knight[y][x] = knight[x][y] = 0;
    return knight[y][x] = knight[x][y] = 2;
}
int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    OFF(king);
    king[1][1]=0;
    for(int i=1000; i>=1; i--) for(int j=i; j>=1; j--) if(king[i][j]==-1)
        KING(i,j);

    OFF(knight);
    knight[1][1]=0;
    for(int i=1000; i>=1; i--) for(int j=i; j>=1; j--) if(knight[i][j]==-1)
        KNIGHT(i,j);
    int t; SI(t);
    while (t--) {
    	SIII(type, n, m);
    	if (type == 1) {
    		if (king[n][m]) puts("B");
    		else puts("G");
    	}
    	else if (type == 2) {
    		if (n ^ m) puts("B");
    		else puts("G");
    	}
    	else if (type == 3) {
    		if (knight[n][m] == 1) puts("B");
    		else if (knight[n][m] == 2) puts("D");
    		else puts("G");
    	}
    	else {
    		if (n > m) swap(n, m);
    		double t = m - n;
    		m--, n--;
    		if (n == (int)(t * (1 + sqrt(5.0)) / 2.0)) puts("G");
    		else puts("B");
    	}
    }
	return 0;
}