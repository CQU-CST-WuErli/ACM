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
void BUG(int _testnumber){
	printf("I am in line %d\n",_testnumber);
} 
const double eps=1e-9;
typedef long long  ll;
using namespace std;


int c,r;
char m[11][11];
int flag[11][11];
int num[11][11];
int cnt;

int check(int i,int j){
	if (m[i][j-1]=='*' || j-1<0) flag[i][j]+=1;
	if (m[i-1][j]=='*' || i-1<0) flag[i][j]+=2;
	if (flag[i][j]>0) return 1;
	else return 0;
}

int main(){
#ifdef LOCAL
	  freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	int kase=1;
	while (cin >> r >> c && r && c){
		CLR(flag);
		CLR(num);
		cnt=0;
		for (int i=0;i<r;i++)
			for (int j=0;j<c;j++){
				cin >> m[i][j];
				if (m[i][j]=='*') flag[i][j]=-1;
			}
		
		for (int i=0;i<r;i++)
			for (int j=0;j<c;j++){
				if (m[i][j]!='*'){
					if (check(i,j)) num[i][j]=++cnt;
				}
			}
	//	for (int i=0;i<r;i++){
	//		for (int j=0;j<c;j++){
	//			printf("%4d ",flag[i][j]);
	//		}
	//		cout << endl;
	//	}
		if (kase!=1) printf("\n");
		printf("puzzle #%d:\n",kase++);
		printf("Across\n");
		for (int i=0;i<r;i++)
			for (int j=0;j<c;j++){
				string tmp;
				if (flag[i][j]==3 || flag[i][j]==1){
					for (int k=j;;k++){
						if (k>=c || m[i][k]=='*') break;
						char c=m[i][k];
						tmp+=c;
					}
				}
				if (tmp.size()){
					printf("%3d.",num[i][j]);
					cout << tmp << endl;
				}
			}
		printf("Down\n");
		for (int i=0;i<r;i++)
			for (int j=0;j<c;j++){
				string tmp;
				if (flag[i][j]==3 || flag[i][j]==2){
					for (int k=i;;k++){
						if (k>=r || m[k][j]=='*') break;
						char c=m[k][j];
						tmp+=c;
					}
				}
				if (tmp.size()){
					printf("%3d.",num[i][j]);
					cout << tmp << endl;
				}
			}
	}
	return 0;
}

