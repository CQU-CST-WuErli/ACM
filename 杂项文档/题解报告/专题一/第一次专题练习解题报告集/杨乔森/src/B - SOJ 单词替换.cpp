// SOJ 单词替换.cpp : 定义控制台应用程序的入口点。
//
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int T;
const int MAXN = 5e6 + 10;
char s[MAXN];
char a[MAXN];
char b[MAXN];

void preKMP(char x[], int kmpNext[]){
	int i, j;
	int m = strlen(x);
	j = kmpNext[0] = -1;
	i = 0;
	while (i < m){
		while (-1 != j&&x[i] != x[j])j = kmpNext[j];
		if (x[++i] == x[++j])kmpNext[i] = kmpNext[j];
		else kmpNext[i] = j;
	}
}
int Next[MAXN];

int tp = 0;
void printTil(int ti){
	for (int i = tp; i < ti; ++i){
		printf("%c", s[i]);
	}
	tp = ti;
}
void KMP_Count(char x[], char y[]) {
	//x是模式串，y是主串  
	int m = strlen(x);
	int n = strlen(y);
	int i, j;
	preKMP(x, Next);
	//kmp_pre(x,m,next);
	i = j = 0;
	while (i < n){
		while (-1 != j && y[i] != x[j]){ 
			j = Next[j];
			//printTil(i);
		}
		i++; j++;
		if (j >= m)
		{
			printTil(i - m);
			printf("%s", b);
			tp = i;
			j = 0;
		}
	}
}

int main()
{
	scanf("%d", &T);
	while (T--){
		tp = 0;
		scanf("%s%s%s", s, a, b);
		KMP_Count(a, s);
		printTil(strlen(s));
		printf("\n");
	}
	return 0;
}

