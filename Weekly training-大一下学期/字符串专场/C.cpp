//  Created by  CQUWEL
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
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
#define INF 0x3f3f3f3f
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
typedef long long  ll;
using namespace std;
string s;
 
int main()
{
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	while (getline(cin,s)){
//		cout << s << endl;
		int p,q,mid,ans=-1,tp,tq;
		int l=s.size();
		p=0;q=l-1;mid=l/2+(l%2==0?0:1)-1;
//		cout << mid << endl;
		for (int i=0;i<=mid;i++){
			p=i;
			q=l-1-i;
			if (s[p]!=s[q]) break;
		}
		if (p==mid && s[p]==s[q]){
			cout << ans << endl;
			continue; 
		}
		int flag=1;
		while (q-p>0){
			if (s[p]==s[q]){
				p++;q--;
			}
			else{
				flag=0;
				break;
			}
		}
		if (!flag){
			flag=1;
			ans=p;
			tp=p;tq=q;
			tp++;
			while (tq-tp>0){
				if (s[tp]==s[tq]){
					tp++;tq--;
				}
				else {
					flag=0;
					break;
				}
			}
		}
		if (!flag){
			flag=1;
			ans=q;
			q--;
			while (q-p>0){
				if (s[p]==s[q]){
					p++;q--;
				}
				else{
					flag=0;
					break;
				}
			}
		}
		if (flag) cout << ans << endl;
		else cout << "-1\n";
	}
	return 0;
}


