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
#define BUG() printf("In here\n")
#define seevalue(x) printf("x=%d\n",x)
#define INF 0x3f3f3f3f
const double eps=1e-9;
typedef long long  ll;
using namespace std;

string m[5];

int check(int x,int y){
	if (x<0 || y<0 || x>=5 || y>=5) return 1;
	else return 0;
}

int main(){
#ifdef LOCAL
	  freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	string s;
	int cnt=0;int kase=1;
	while (getline(cin,s)){
		if (s[0]=='Z') break;
		else {
			if (kase!=1) printf("\n");
		}
		m[0]=s;
		printf("Puzzle #%d:\n",kase++);
		for (int i=1;i<5;i++) getline(cin,m[i]);
		string op;
		char o;
		while (cin >> o){
			op+=o;
			if (o=='0') break;
		}
	//	cout << op << endl;
		getchar();
		int x,y;
		for (int i=0;i<5;i++) for (int j=0;j<5;j++) if (m[i][j]==' '){
			x=i;y=j;
		}
		int flag=0;
		for (int i=0;op[i];i++){
			int tx,ty;
			if (op[i]=='A'){
				tx=x-1;ty=y;
				if (check(tx,ty)){
					flag=1;
					break;
				}
				char cc=' ';
				m[x][y]=m[tx][ty];m[tx][ty]=cc;
			}
			else if(op[i]=='B'){
				tx=x+1;ty=y;
				if (check(tx,ty)){
					flag=1;
					break;
				}
				char cc=' ';
				m[x][y]=m[tx][ty];m[tx][ty]=cc;
			}
			else if (op[i]=='L'){
				tx=x;ty=y-1;
				if (check(tx,ty)){
					flag=1;
					break;
				}
				char cc=' ';
				m[x][y]=m[tx][ty];m[tx][ty]=cc;
			}
			else if(op[i]=='R'){
				tx=x,ty=y+1;
				if (check(tx,ty)){
					flag=1;
					break;
				}
				char cc=' ';
				m[x][y]=m[tx][ty];m[tx][ty]=cc;
			}
			x=tx;y=ty;
		}
		if (flag) printf("This puzzle has no final configuration.\n");
		else {
			for (int i=0;i<5;i++){
				for (int j=0;j<5;j++){
					cout << m[i][j];
					if (j<4) cout << ' ';
					else cout << "\n";
				}
			}	
			
		}
	}
	return 0;
}

