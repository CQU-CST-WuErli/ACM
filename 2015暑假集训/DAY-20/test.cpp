//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015�� CQU_CST_WuErli. All rights reserved.
//
// #include<bits/stdc++.h>
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
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define At(i,v) for (auto &i:v)
#define for_uva if (kase!=1) cout << endl
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << #x << "= " << x << endl
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;
const int N=500005;

long d[N],a[N];  //d[N]�����������������

long find(long a,long left,long right)  //���ֲ��ҷ�
{
	long mid;
	while(left<=right)
	{
		mid=(left+right)/2;
       if(a>d[mid])
		   left=mid+1;
	   else
		   right=mid-1;
	}
	return left;
}


int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	long n,i,j,len,p,t,k=0;
	while(scanf("%d",&n)!=EOF)
	{
		k++;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&j,&p);
			a[j]=p;
		}
		d[1]=a[1];
		len=1;
		for(i=2;i<=n;i++)   
		{
			t=find(a[i],1,len);   //�ҳ�a[i]��λ��
			d[t]=a[i];            //����d[t],ʹd[t]��������С��,��������в�һ������ȷ�ģ�
            if(t>len)            //����Ϊd[len]�������ģ����Գ�������ȷ��
				len++;
		}
   if(len==1)
     printf("Case %d:\nMy king, at most %d road can be built.\n\n",k,len);  //����
   else
     printf("Case %d:\nMy king, at most %d roads can be built.\n\n",k,len);  //������ϸ�ĵ�
	}
	return 0;
}
