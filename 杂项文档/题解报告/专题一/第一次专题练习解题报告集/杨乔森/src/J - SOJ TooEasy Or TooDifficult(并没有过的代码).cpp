// SOJ TooEasy Or TooDifficult.cpp : 定义控制台应用程序的入口点。
//
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cstring>
using namespace std;
typedef long long ll;
//Manacher--------------------------
const int MAXN = 2e5 + 10;
char ma[MAXN];
int mp[MAXN];
int Min(int a, int b){ return a < b ? a : b; }
int Max(int a, int b){ return a > b ? a : b; }
void Manacher(char s[]){
	int len = strlen(s);
	int l = 0;
	ma[l++] = '$';
	ma[l++] = '#';
	for (int i = 0; i < len; ++i){
		ma[l++] = s[i];
		ma[l++] = '#';
	}
	ma[l] = 0;
	int mx = 0;
	int id = 0;
	for (int i = 0; i < l; ++i){
		mp[i] = mx>i ? Min(mp[2 * id - i], mx - i) : 1;
		while (ma[i + mp[i]] == ma[i - mp[i]])mp[i]++;
		if (i + mp[i] > mx){
			mx = i + mp[i];
			id = i;
		}
	}
}
//------------------------------------
//计算a^bmodn     
#define MASK 0xffffffff
ll mod(ll x, ll y, ll k)
{
	int tx = x;
	int modRes = 1;
	tx %= k;
	while (y&MASK) {
		if (y & 1)
			modRes = modRes * tx % k;
		y = (y >> 1);
		tx = tx * tx % k;
	}
	return modRes;
}
//----------------------------

//字典树=============================================
int na[MAXN];
int tot;
const int MAX = 2;
const int MAXX = 2e6 + 10;
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
void init(){
	allocp = 0;
	memset(na, 0, sizeof na);
	tot = 0;
}
char tmp[40];
void setTmp(int n){
	for (int i = 6; i >= 0; --i){
		tmp[i] = n % 2 + '0';
		n /= 2;
	}
	tmp[7] = '\0';
}
//=============================================================
int t;
int k;
const int MAXK = 1e5 + 10;
char s[MAXK];
int pi[MAXK];
int maxs;
double cntJD(){
	ll mods = maxs / 3 * 5 + 1;
	ll k3 = k*k*k;
	ll tmp = mod(maxs, k3, mods) + maxs * 4 / 5;
	return tmp;
}
int main()
{
	cin >> t;
	while (t--){
		init();
		TrieNode* root = NULL;
		setTmp(0);
		InsertTrie(root, tmp, 0);
		scanf("%s", s);
		int len = strlen(s);
		Manacher(s);
		int i = 0;
		int ans = 0;
		maxs = 0;
		k = len;
		while (s[i]){
			pi[i] = mp[2 * i + 2] - 1;
			setTmp(pi[i]);
			ans = max(ans, SearchTrie(root, tmp, pi[i]));
			maxs = max(maxs, pi[i]);
			setTmp(ans);
			InsertTrie(root, tmp, ans);
			++i;
		}
		ll ans2 = cntJD();
		if (ans2 > ans)printf("liujc\n");
		else printf("luoxinchen\n");
	}
	return 0;
}

