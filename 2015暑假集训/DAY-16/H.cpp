//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015年 CQU_CST_WuErli. All rights reserved.
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
const int N=1500;
int n;
int a[N];
int pos[N];


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n && n){
		int b[N],p[N];
		for (int i=1;i<=n;i++){
			scanf("%d",a+i);
			a[i+n]=a[i];           // a good method for circle
			pos[a[i]]=i;
		}
		int ans=0x3f3f3f;
		for (int i=1;i<=n;i++){
			memcpy(b,a,sizeof(a));
			memcpy(p,pos,sizeof(pos));
			int tmp=0;
			for (int j=0;j<n;j++){
				if (b[j+i]!=j+1){
					int pp=p[j+1];
					if (pp<i) pp+=n;     // 环状向后延伸所以下标不能比i小
					p[b[j+i]]=pp;
					swap(b[pp],b[i+j]);
					tmp++;
				} 
			}
			ans=min(tmp,ans);
		}
		reverse(a+1,a+1+n+n);
		for (int i=1;i<=n;i++){
			pos[a[i]]=i;
		}
		for (int i=1;i<=n;i++){
			memcpy(b,a,sizeof(a));
			memcpy(p,pos,sizeof(pos));
			int tmp=0;
			for (int j=0;j<n;j++){
				if (b[j+i]!=j+1){
					int pp=p[j+1];
					if (pp<i) pp+=n;           
					p[b[j+i]]=pp;
					swap(b[pp],b[i+j]);
					tmp++;
				} 
			}
			ans=min(tmp,ans);
		}
		cout << ans << endl; 
	}
	return 0;
}


