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
#define BUG(x) cout << "I am in line" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int main(){
#ifdef LOCAL
	  freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	int round;
	while (cin >> round && round!=-1){
		getchar();
		printf("Round %d\n",round);
		string s,t;
		string tmp;
		cin >> tmp;
		int num[26]={0};
		for (int i=0;tmp[i];i++){
			if (!num[tmp[i]-'a']){
				num[tmp[i]-'a']++;
				s+=tmp[i];
			}
		}
		CLR(num);
		cin >> tmp;
		for (int i=0;tmp[i];i++){
			if (!num[tmp[i]-'a']){
				num[tmp[i]-'a']++;
				t+=tmp[i];
			}
		}
	//	cout << s << endl;
	//	cout << t << endl;
		CLR(num);
		int suc=0,drw=0;
		int ls=s.size();
		int ans=0;
		for (int i=0;s[i];i++) num[s[i]-'a']++;
		for (int i=0;t[i];i++){
			if (num[t[i]-'a']) suc++;
			else drw++;
			if (drw==7 || suc==ls) {
				break;
			}
		}
		if (drw==7){
			printf("You lose.\n");
		} 
		else if(suc==ls){
			printf("You win.\n");
		}
		else printf("You chickened out.\n");
	}
	return 0;
}


