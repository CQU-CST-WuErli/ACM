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
#include <time.h>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <unordered_map>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int T;

typedef pair<int,int> P;

P m[27];
 
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//  freopen("C:\\Users\\john\\Desktop\\out.txt","r",stdout);
#endif
	while (cin >> T){
		getchar();
		for (int i=0;i<T;i++){
			char c;int x,y;
			scanf("%c%d%d",&c,&x,&y);
			getchar();
		//	cout << c << " " << x << " " << y << endl;
			m[c-'A'].first=x;
			m[c-'A'].second=y;
		}
		string s;int err;
		getchar();
		while (getline(cin,s)){
			err=0;
			if (s.find('(')==s.npos){
				printf("0\n");
				continue;
			} 
			else {
				stack<P> sp;
				ll sum=0;
				for (int i=0;s[i];i++){
					if (isalpha(s[i])){
						P tmp=m[s[i]-'A'];
						sp.push(tmp);
					//	cout << tmp.first << "  " << tmp.second << endl;
					}
					else {
						if (s[i]==')'){
							P tmp1,tmp2;
							tmp2=sp.top();sp.pop();
							tmp1=sp.top();sp.pop();
//							cout << tmp1.first << "  " << tmp1.second << endl;
//							cout << tmp2.first << "  " << tmp2.second << endl;
							if (tmp1.second!=tmp2.first){
								err=1;break;
							}
							else {
								P temp;
								sum+=tmp1.first*tmp2.first*tmp2.second;
					//			cout << tmp1.first*tmp1.second*tmp2.second << endl;
								temp.first=tmp1.first;
								temp.second=tmp2.second;
								sp.push(temp);
							}
						}
					}
				}
				if (err) printf("error\n");
				else cout << sum << endl; 
			}
		}
	}
	return 0;
}


