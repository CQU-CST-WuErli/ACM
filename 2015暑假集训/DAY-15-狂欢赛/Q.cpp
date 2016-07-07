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

int n,m,k;

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> m >> k){
		string op;
		string s;
		getchar();
		getline(cin,op);
		cin >> s;
//		cout << op << endl;
//		cout << s << endl;
		int flag;
		flag=(op[3]=='h'?-1:1);
//		cout << flag << endl;
		int stow=m,cont=k;
		int ok=0;
		int i;
		for (i=0;s[i];i++){
//			cout << flag << endl; 
			cont+=flag;
			if (cont==0){
				flag=0-flag;
				cont=2;
			}
			else if (cont==n+1){
				flag=0-flag;
				cont=n-1;
			}
			if (s[i]=='1') stow=cont-flag;
			else if (cont==stow) stow+=flag;
			if (stow==0 || stow==n+1) {
				ok=1;break;
			} 
//			cout << "cont: " << cont << "   " << "stow: " << stow << endl;
		} 
		if (ok) cout << "Controller " << i+1 << endl;
		else cout << "Stowaway" << endl; 
	}
	return 0;
}


