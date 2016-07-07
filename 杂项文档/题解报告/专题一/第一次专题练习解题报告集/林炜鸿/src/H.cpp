/*
SCU - 4501
给定若干个 DNA序列，求最短包含所有序列的长度
包含不一定是连续包含，可以不是子串

状压DP
依次构造每一位
把每个字符串走到的位置标记一下，压成 6进制数
然后每个状态拓展一个字符串
然后同时拓展其他所有下一位与其相同的串
然后把状态丢到队列里转移，当每个串都走到结尾时输出答案
可以保证答案最多不超过 40
时间复杂度 O(ans*len^N)
*/
#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef pair<int,int> Pii;
typedef long long LL;
typedef unsigned long long ULL;
typedef double DBL;
typedef long double LDBL;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) (a*a)

struct data
{
	int mask,res;
	data(int tm,int tr):mask(tm),res(tr){}
};
int N;
char inpt[10][10];
int tlen[10];
int buff[10];

int encode(int*);
int* decode(int);
bool check(int*);

int main()
{
	int T;
	scanf("%d", &T);
	for(int ck=1; ck<=T; ck++)
	{
		scanf("%d", &N);
		for(int i=0; i<N; i++)
		{
			scanf(" %s", inpt[i]);
			tlen[i]=strlen(inpt[i]);
		}
		queue<data> que;
		set<int> vis;
		que.push(data(0,0));
		while(que.size())
		{
			data &u=que.front();
			int *used=decode(u.mask);
			if(check(used)){printf("%d\n", u.res);break;}
			bool ban[10]={0};
			for(int i=0; i<N; i++)
			{
				int temp[10];
				if(used[i]>=tlen[i]||ban[i]) continue;
				char nxt=inpt[i][used[i]];
				for(int j=0; j<N; j++)
				{
					temp[j]=used[j];
					if(temp[j]>=tlen[j]) continue;
					if(inpt[j][temp[j]]==nxt)
					{
						temp[j]++;
						ban[j]=1;
					}
				}
				int nm=encode(temp);
				if(vis.find(nm)!=vis.end()) continue;
				que.push(data(nm, u.res+1));
				vis.insert(nm);
			}
			que.pop();
		}
		while(que.size()) que.pop();
	}
	return 0;
}

int encode(int buff[])
{
	int res=0;
	for(int i=N-1; i>=0; i--) res=res*6+buff[i];
	return res;
}

int* decode(int num)
{
	for(int i=0; i<N; i++)
	{
		buff[i]=num%6;
		num/=6;
	}
	return buff;
}

bool check(int cntc[])
{
	for(int i=0; i<N; i++) if(cntc[i]<tlen[i]) return 0;
	return 1;
}

