// SOJ 双剑合并.cpp : 定义控制台应用程序的入口点。
//
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN = 1e6 + 10;
const int MAXX = 3e6 + 10;//字典树大小
int t;
int n, m;
int a[MAXN];
int b[MAXN];

int na[MAXN];
int tot;
int maxlen;
//字典树=============================================
const int MAX = 2;
typedef struct TrieNode {
	int nCount;
	struct TrieNode *next[MAX];

}TrieNode;
TrieNode Memory[MAXX];
int allocp = 0;
TrieNode *CreateTrieNode() {
	int i;
	TrieNode *p;
	p = &Memory[allocp++];
	p->nCount = -1;
	for (i = 0; i < MAX; i++) {
		p->next[i] = NULL;
	}
	return p;
}
void InsertTrie(TrieNode * &pRoot, char*s, int num) {
	int i, k;
	TrieNode *p;
	if (!(p = pRoot)) {
		p = pRoot = CreateTrieNode();
	}
	i = 0;
	while (s[i]) {
		k = s[i++] - '0';
		if (!(p->next[k]))
			p->next[k] = CreateTrieNode();
		p = p->next[k];
	}
	if (p->nCount != -1)return;
	na[tot] = num;
	p->nCount = tot++;
}
int SearchTrie(TrieNode * &pRoot, char*s, int num) {//返回最大匹配值
	TrieNode *p;
	int i, k;
	if (!(p = pRoot)) {
		return 0;
	}
	i = 0;
	while (s[i]) {
		k = s[i++] - '0';
		if (p->next[1 - k] != NULL){//存在不同
			p = p->next[1 - k];
		}
		else if (p->next[k] != NULL) //否则进行相同查找
		{
			p = p->next[k];
		}
		else { //错误
			return 0;
		}
	}
	return num^na[p->nCount];//匹配完成
}
//=============================================================
char tmp[40];
void setTmp(int n){
	for (int i = 31; i >= 0; --i){
		tmp[i] = n % 2 + '0';
		n /= 2;
	}
	tmp[32] = '\0';
}
//
//思路:先搜索第一个开始不同的位置
//以及连续几个不同来进行减枝
//dfs可以直接选用最优策略而不需要遍历
int main()
{
	scanf("%d", &t);
	while (t--){
		tot = 0;
		maxlen = 0;
		scanf("%d%d", &n, &m);
		memset(Memory, 0, sizeof Memory);
		TrieNode* root = NULL;
		for (int i = 1; i <= n; ++i){
			scanf("%d", a + i);
			setTmp(a[i]);
			InsertTrie(root, tmp, a[i]);
		}
		int ans = 0;
		for (int i = 1; i <= m; ++i){
			scanf("%d", b + i);
			setTmp(b[i]);
			ans = max(ans, SearchTrie(root, tmp, b[i]));
		}
		printf("%d\n", ans);
	}
	return 0;
}

