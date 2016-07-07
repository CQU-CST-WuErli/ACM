//  Created by  CQUWEL			                       
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.  

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>           
#include <algorithm>
#include <cctype>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <set>
#include <vector>
#define INF 0x3f3f3f3f
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
typedef long long  ll;
using namespace std;

int n,m,y;
int x[1010];
struct rob{
	double k1;
	int k2;
	double dk;
	int cnt;
}r[1010];

int k[1010];

bool cmp(const rob&a,const rob&b)
{
	return a.dk<b.dk;
}
int main()
{
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	while (scanf("%d%d%d",&n,&m,&y)!=EOF)
	{
		int sum=0;
		for(int i=1;i<=n;i++){
			cin >> x[i];
			r[i].k1=(double)x[i]/(double)y*m;
			r[i].k2=(int)r[i].k1;
			r[i].dk=fabs(r[i].k1-r[i].k2);
			r[i].cnt=i;
			k[i]=r[i].k2;
			sum+=r[i].k2;
		}
//		cout << "sum=" << sum << endl;
//		for (int i=1;i<=n;i++)
//			cout << r[i].k1<<" " << r[i].k2 << "¡¡"<< r[i].dk<< " "<< r[i].cnt<<endl;
//		for (int i=1;i<=n;i++)
//			cout << "k[" << i<< "]="<< k[i]<< endl;
		sort(r+1,r+1+n,cmp);
//		cout << "------------------------"<< endl;
//		for (int i=1;i<=n;i++)
//			cout << r[i].k1<<" " << r[i].k2 << "¡¡"<< r[i].dk<< " "<< r[i].cnt<<endl;
		if (sum==m){
			for (int i=1;i<=n;i++)
				cout << k[i] << " "<< endl;
		}
		else if (sum<m){
			int temp=m-sum;
			int flag=n;
//			cout << "temp=" << temp<< endl;
			while (temp){
				k[r[flag--].cnt]++;
				temp--;
			}
		}
		for (int i=1;i<=n;i++){
			cout << k[i] << " ";
		}
		cout << endl;
		
	}
	return 0;
}
