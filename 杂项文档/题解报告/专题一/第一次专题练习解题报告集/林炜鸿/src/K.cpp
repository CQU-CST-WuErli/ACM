/*
SCU - 4504
����һ��ѭ�������ʴ��ĸ�λ���ʷ���ʹ���ֵ�����С

��С��ʾ�����⣬��׺��������
Ȼ����׺�����һ���̫�ṹ��
����ת��ѧϰ��һ����С��ʾ��

�����㷨��
��ԭ���鸴��һ��
ö���������Ŀ�ͷ p_1, p_2�����αȽ���������ÿһλ
ÿ�� S[p_1+k] != S[p_2+k] ʱ���ֵ���ϴ��ͷָ�������һλ
ʱ�临�Ӷ� O(N^2)

��С��ʾ����
�������㷨������ͬ
�����ڷ��� S[p_1+k] != S[p_2+k]ʱ���ֵ���ϴ��ͷָ������ƶ� kλ

֤�����£�
1. ������ S[p_1+k] > S[p_2+k]���� \forall i \in [p-1,k)�������ܳ�Ϊ��С����ͷ
��Ϊ�����Ϊ��С����ͷ����ô�����ڵڶ������ж�Ӧ��һ��λ��
ʹ�� S_{i_1->i_1+k} > S_{i_2->i_2+k}
���� \forall i \in [p-1,k)�������ܳ�Ϊ��С����ͷ
 
2. ͬ�� S[p_1+k] < S[p_2+k]��\forall i \in [p-2,k) �������ܳ�Ϊ��С����ͷ
�����ڷ���ʧ��ʱ��ͷָ��ֱ������ƶ� k+1λ

3. S[p_1+k] = S[p_2+k]���� k�����������ϱȽϣ�ֱ��ʧ��
���ߵ� k==Nʱ����ʱ�͵õ�����С��
p_1 != p_2 ������ p_2 > p_1
�� 1�� 2��֪��p_1->p_2���ַ�������������С���Ŀ�ͷ
���� S_1 == S_2��������ͬ���ۿ���ӳ�䵽 S_2��
���ԾͿɵó� p_1����С���Ŀ�ͷ

��� p_1��p_2�н�С���Ǹ�������С����ͷָ��
��� p_1��p_2��С�� N����С����Ψһ������һ������
�����С��Ψһ����ô��һ���Ʊػ����� N�ˣ�����ȡ��С��
��Ȼβָ������ƶ� 4*N�Σ������㷨ʱ�临�Ӷ� O(N)
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

