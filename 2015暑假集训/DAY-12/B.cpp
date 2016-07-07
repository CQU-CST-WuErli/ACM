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
#include <ctime>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << #x << "= " << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;


int n,m;
int mp[12][12];
int r[30],c[30];
int ldig[30],rdig[30];     // ldig[r+c]   rdig[r-c+12]
int maxd;
int kase;
void init(){
	CLR(mp);
	char ch;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            do{scanf("%c", &ch);}while(!isprint(ch));
            if(ch=='X') {
                mp[i][j] = 1;
            }
        }
    }
	kase=0;
}

bool check(){
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (mp[i][j] && !r[i] && !c[j] && !ldig[i+j] && !rdig[n+j-i]) return false;
	return true;
}

bool dfs(int pos,int dep){
	if (dep==maxd){
		if (check()){
			cout << dep << endl;
			return true;
		}
		return false;
	}
	else {
		for (int i=pos;i<m*n;i++){
			int row=i/m,col=i%m;
			int tmp1=r[row],tmp2=c[col],tmp3=ldig[row+col],tmp4=rdig[n+col-row];
			r[row]=1;c[col]=1;ldig[row+col]=1;rdig[n+col-row]=1;
			if (dfs(pos,dep+1)) return true;
			r[row]=tmp1;c[col]=tmp2;ldig[row+col]=tmp3;rdig[n+col-row]=tmp4;
		}	
	} 
	return false;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> m && (n || m)){
		getchar();
		init();
		cout << "Case " << ++kase << ": ";
		for (maxd=0;;maxd++){
			CLR(r);CLR(c);CLR(ldig);CLR(rdig); 
			if (dfs(0,0)) break;
		}
	}
	return 0;
}


