/*
SCU - 4504
给定一个循环串，问从哪个位置剖分能使得字典序最小

最小表示法裸题，后缀数组裸题
然而后缀数组我还不太会构造
所以转而学习了一下最小表示法

朴素算法：
将原数组复制一遍
枚举两个串的开头 p_1, p_2，依次比较两个串的每一位
每当 S[p_1+k] != S[p_2+k] 时，字典序较大的头指针向后移一位
时间复杂度 O(N^2)

最小表示法：
与朴素算法大致相同
就是在发现 S[p_1+k] != S[p_2+k]时，字典序较大的头指针向后移动 k位

证明如下：
1. 不妨设 S[p_1+k] > S[p_2+k]，则 \forall i \in [p-1,k)都不可能成为最小串的头
因为如果其为最小串的头，那么可以在第二个串中对应找一个位置
使得 S_{i_1->i_1+k} > S_{i_2->i_2+k}
所以 \forall i \in [p-1,k)都不可能成为最小串的头
 
2. 同理 S[p_1+k] < S[p_2+k]，\forall i \in [p-2,k) 都不可能成为最小串的头
所以在发生失配时，头指针直接向后移动 k+1位

3. S[p_1+k] = S[p_2+k]，则 k就自增，不断比较，直到失配
或者当 k==N时，此时就得到了最小串
p_1 != p_2 不妨设 p_2 > p_1
由 1和 2可知，p_1->p_2的字符都不可能是最小串的开头
由于 S_1 == S_2，所以相同结论可以映射到 S_2上
所以就可得出 p_1即最小串的开头

最后 p_1，p_2中较小的那个就是最小串的头指针
如果 p_1，p_2都小于 N，最小串不唯一，任意一个都行
如果最小串唯一，那么有一个势必滑动出 N了，所以取最小的
显然尾指针最多移动 4*N次，所以算法时间复杂度 O(N)
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

const int maxn=3e5+10;
int N;
int inpt[2*maxn];

int main()
{
	int T;
	scanf("%d", &T);
	for(int ck=1; ck<=T; ck++)
	{
		scanf("%d", &N);
		for(int i=0; i<N; i++)
		{
			scanf("%d", &inpt[i]);
			inpt[i+N]=inpt[i];
		}
		int p1=0,p2=1;
		while(p1<N&&p2<N)
		{
			int len=0;
			while(inpt[p1+len]==inpt[p2+len]&&len<N) len++;
			if(len==N) break;
			if(inpt[p1+len]>inpt[p2+len]) p1+=len+1;
			else p2+=len+1;
			if(p1==p2) p2++;
		}
		int ansp=min(p1, p2);
		for(int i=ansp; i<ansp+N; i++) printf("%d ", inpt[i]);
		puts("");
	}
	return 0;
}

