// SOJ 奶牛合影.cpp : 定义控制台应用程序的入口点。
//
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
int t;
const int MAXN = 3e5 + 10;
const int INF = 0x3f3f3f3f;
int s[MAXN];
int l;
void add(int& i){
	++i;
	while (i >= l)i -= l;
}
void output(int i){//从下标i开始打印
	for (int t = 1; t <= l; ++t){
		if (t != 1)printf(" ");
		printf("%d", s[i]);
		add(i);
	}
	printf("\n");
}
int MinimumRepresentation()
{
	int i = 0, j = 1, k = 0, t;
	while (i < l && j < l && k < l) {
		t = s[(i + k) >= l ? i + k - l : i + k] - s[(j + k) >= l ? j + k - l : j + k];
		if (!t) k++;
		else{
			if (t > 0) i = i + k + 1;
			else j = j + k + 1;
			if (i == j) ++j;
			k = 0;
		}
	}
	return (i < j ? i : j);
}
int main()
{
	scanf("%d", &t);
	while (t--){
		scanf("%d", &l);
		for (int i = 0; i < l; ++i){
			scanf("%d", s + i);
		}
		int ans = MinimumRepresentation();
		output(ans);
	}
	return 0;
}

