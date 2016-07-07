//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015Äê CQU_CST_WuErli. All rights reserved.
//	Fuck weidiao's  contest
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

//  This code is created from Rujia Liu's code, so do not care some details.
/*
      00    01
      02    03
04 05 06 07 08 09 10
      11    12
13 14 15 16 17 18 19
      20    21
      22    23
*/

int line[8][7]={
  { 0, 2, 6,11,15,20,22}, // A
  { 1, 3, 8,12,17,21,23}, // B
  {10, 9, 8, 7, 6, 5, 4}, // C
  {19,18,17,16,15,14,13}, // D
};

const int rev[8]={5,4,7,6,1,0,3,2};
const int center[8]={6,7,8,11,12,15,16,17};

int a[24];
char ans[1000];
int maxd;

void init(){
  for(int i=4;i<8;i++)
    for(int j=0;j<7;j++) line[i][j]=line[rev[i]][6-j];
}

bool is_ok(){
	for (int i=0;i<8;i++)
		if (a[center[i]]!=a[center[0]]) return false;
	return true;
}

int sum_diff(int x){
	int sum=0;
	for (int i=0;i<8;i++) 
		if (a[center[i]]!=x) sum++;
	return sum;
}

inline int access_h(){
	return min(min(sum_diff(1),sum_diff(2)),sum_diff(3));
}

inline void move_block(int i){
	int tmp=a[line[i][0]];
	for (int j=0;j<6;j++) a[line[i][j]]=a[line[i][j+1]];
	a[line[i][6]]=tmp;
}

bool dfs(int d){
	if (is_ok()){
		ans[d]='\0';
		printf("%s\n",ans);
		return true;
	}
	if (d+access_h()>maxd) return false;
	for (int i=0;i<8;i++){
		ans[d]='A'+i;
		move_block(i);
		if (dfs(d+1)) return true;
		move_block(rev[i]);
	}
	return false;
}
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	init();
	while (scanf("%d",&a[0])==1 && a[0]){
		for (int i=1;i<24;i++) scanf("%d",a+i);
//		for(int i=0;i<24;i++) if(!a[i]) return 0;
		if (is_ok()) printf("No moves needed\n");
		else {
			for (maxd=1;;maxd++){
				if (dfs(0)) break;
			} 
		}
		printf("%d\n",a[6]);
	}
	return 0;
}


