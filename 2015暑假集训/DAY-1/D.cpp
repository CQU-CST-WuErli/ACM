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
#define filetest freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin)
#define BUG() printf("In here\n")
#define seevalue(x) printf("x=%d\n",x)
#define INF 0x3f3f3f3f
const double eps=1e-9;
typedef long long  ll;
using namespace std;
string s,t;
int vis[1010*3];
int c1,c2;


int main(){
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	int n;
	int kase=1;
	while (cin >> n && n){
		getchar();
		int flag=0;
		printf("Game %d:\n",kase++);
		getline(cin,s);
	//	cout << s << endl;
		while (getline(cin,t)){
		//	cout << t << endl;
			if (t[0]=='0'){
				flag=1;
				break;
			}
			memset(vis,0,sizeof vis);
			c1=0;c2=0;
			for (int i=0;t[i];i++){
				if (s[i]==t[i]){
					if (s[i]!=' ')	c1++;
					vis[i]=1;
				} 		
 			}
 			for (int i=0;t[i];i++){
 				if (s[i]==t[i]) continue;
 				else {
 					for (int j=0;s[j];j++){
 						if (s[j]==t[i] && !vis[j]){
 							c2++;
 							vis[j]=1;
 							break;
 						}
 					}
 				}
 			}
 		//	for (int i=0;s[i] ;i++) if (s[i]!=' ') cout << vis[i] << " " ;
			printf("    (%d,%d)\n",c1,c2);
		}
		if (flag) continue;
	}
	return 0;
}

