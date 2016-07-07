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
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	int n ;
	string s;
	cin >> n;
	getchar();
	for (int t=1;t<=n;t++){
		cin >> s;
	//	cout << s << endl;
		double sum=0.00;
		int C,N,H,O;
		C=0;N=0;H=0;O=0;
		int tp=0;
		int cnt=0;
		for (int i=0;s[i];i++){
			if (isalpha(s[i])){
				if (isalpha(s[i+1]) || s[i+1]=='\0'){
					if (s[i]=='C') C++;
					else if (s[i]=='H') H++;
					else if (s[i]=='O') O++;
					else if (s[i]=='N') N++;
				}
				else if (isdigit(s[i+1]) && (isalpha(s[i+2]) || s[i+2]=='\0')){
					if (s[i]=='C') C+=s[i+1]-'0';
					else if (s[i]=='H') H+=s[i+1]-'0';
					else if (s[i]=='O') O+=s[i+1]-'0';
					else if (s[i]=='N') N+=s[i+1]-'0';
				}
				else if (isdigit(s[i+1]) && isdigit(s[i+2])){
					if (s[i]=='C') C+=(s[i+1]-'0')*10+(s[i+2]-'0');
					else if (s[i]=='H') H+=(s[i+1]-'0')*10+(s[i+2]-'0');
					else if (s[i]=='O') O+=(s[i+1]-'0')*10+(s[i+2]-'0');
					else if (s[i]=='N') N+=(s[i+1]-'0')*10+(s[i+2]-'0');
				}
			}
		}
//		cout << C <<" "  << H <<" " <<O << " "<< N << endl; 
		sum=C*12.01+H*1.008+O*16.00+N*14.01;
		printf("%.3lf\n",sum);
	}
	return 0;
}

