// SOJ DNA����.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int t;
int n;
const int MAXN = 10;
char s[MAXN][10];
int len[MAXN];//����
int tn[MAXN];//ÿһλƥ�䵽����
char ss[100];//��ǰ����
char rc[] = { 'A', 'C', 'G', 'T' };
bool over(){
	for (int i = 1; i <= n; ++i){
		if (tn[i] < len[i])return false;
	}
	return true;
}
int countH(){
	int maxs = 0;
	for (int i = 1; i <= n; ++i){
		if (len[i] - tn[i] > maxs){
			maxs = len[i] - tn[i];
		}
	}
	return maxs;
}
int maxH;
bool dfs(int i){//��iλdfs
	if (i > maxH)return false;
	if (over())return true;
	for (int j = 0; j < 4; ++j){
		bool vis[MAXN];// �Ƿ�ƥ���
		memset(vis, 0, sizeof vis);
		bool flag = false;
		for (int k = 1; k <= n; ++k){
			if (tn[k] >= len[k])continue;
			if (rc[j] == s[k][tn[k]]){
				++tn[k];
				vis[k] = 1;
				flag = true;
			}
		}
		if (over())return true;
		if (!flag)continue;
		if (countH() + i <= maxH)
			if (dfs(i + 1))return true;
		for (int k = 1; k <= n; ++k){
			if (vis[k] == 1){
				vis[k] = 0;
				--tn[k];
			}
		}
	}
	return false;
}
int main()
{
	cin >> t;
	while (t--){
		int maxl = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i){
			cin >> s[i];
			len[i] = strlen(s[i]);
			maxl = max(maxl, len[i]);
		}
		memset(tn, 0, sizeof tn);
		for (maxH = maxl; maxH <= 50; ++maxH){
			if (dfs(1))break;
		}
		cout << maxH << endl;
	}
	return 0;
}

