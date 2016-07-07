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
int a[110];
vector<int> vc;

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	string s;
	while(getline(cin,s)){ 
		stringstream ss(s);
		int x;
		int cnt = 0;
		while(ss >> x){ 
			a[cnt++] = x;
			vc.push_back(x);
		}
		sort(a,a+cnt);
		cout << s << endl;
		for(int i=vc.size()-1;i>=0;i--){ 
			for(int j=0;j<i;j++){ 
				if(vc[j]==a[i]){ 
					if(j==0){ 
						cout << vc.size()-i << " ";
						reverse(vc.begin(),vc.begin()+i+1);
					}
					else{ 
						cout << vc.size()-j << " ";
						reverse(vc.begin(),vc.begin()+j+1);
						i++;
					}
					break;
				}
			}
		}
		cout << "0\n";
		vc.clear();
	}
	return 0;
}
