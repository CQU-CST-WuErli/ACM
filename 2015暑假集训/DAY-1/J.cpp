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

int main(){
#ifdef LOCAL
	  freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	int n;
	char s[100];
	cin >> n;
	getchar();
	getchar();
	for (int t=1;t<=n;t++){
		gets(s);
	//	puts(s);
		getchar();
		int len;
		int ls=strlen(s);
		char tmp[100];
		for (len=1;len<=ls;len++){
			if (ls%len==0){
				int flag=0,j;
				for (j=0;j<len;j++)	tmp[j]=s[j]; tmp[j]='\0';
			//	puts(tmp);
				int cnt=0;
				for (j=0;s[j];j++){
					if (s[j]==tmp[cnt]){
						cnt++;
						if (cnt==len) cnt=0;
					}
					else {
						flag=1;
						break;
					}
				}
				if (flag) continue;
				else break;
			}		
		}
		if (t==1) printf("%d\n",len);
		else if (t==n) printf("\n%d\n",len);
		else printf("\n%d\n",len);
	}
	return 0;
}

