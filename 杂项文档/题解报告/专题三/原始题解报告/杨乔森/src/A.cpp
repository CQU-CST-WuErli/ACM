// SOJ Euler.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAXN = 600;
int n, m;
int fa[MAXN];
void init(){
	for (int i = 1; i <= n; ++i){
		fa[i] = i;
	}
}
int find(int x){
	while (x != fa[x])x = fa[x];
	return x;
}
bool same(int a, int b){
	return find(a) == find(b);
}
void un(int a, int b){
	a = find(a);
	b = find(b);
	if (a != b){
		fa[a] = b;
	}
}
int num;
bool has[MAXN];
int chu[MAXN];
int ru[MAXN];
int du[MAXN];
int ji;
int main()
{
	int t;
	cin >> t;
	while (t--){
		cin >> n >> m;
		init();
		//memset(has, 0, sizeof has);
		ji = 0;
		num = 0;
		memset(chu, 0, sizeof chu);
		memset(ru, 0, sizeof ru);
		memset(du, 0, sizeof du);
		for (int i = 1; i <= m; ++i){
			int t1, t2;
			cin >> t1 >> t2;
			un(t1, t2);
			has[t1] = has[t2] = 1;
			chu[t1]++;
			ru[t2]++;
			du[t1]++;
			du[t2]++;
		}
		for (int i = 1; i <= n; ++i){
			if (du[i] % 2)++ji;
		//	if (has[i]){
				if (i == find(i)){
					++num;
				}
		//	}
		}
		bool f1, f2;
		if (num > 1){//不联通
			f1 = f2 = false;
		}
		else{
			if (ji == 0 || ji == 2){
				f1 = true;
			}
			else f1 = false;

			int ts = 0;
			int te = 0;
			int el = 0;
			for (int i = 1; i <= n; ++i){
				if (ru[i] - chu[i] == 1)++te;
				else if (chu[i] - ru[i] == 1)++ts;
				else if (chu[i] != ru[i])++el;
			}
			if (el != 0 || ts > 1 || te > 1)f2 = false;
			else if (ts == 1 && te == 0)f2 = false;
			else if (ts == 0 && te == 1)f2 = false;
			else f2 = true;
		}
		if (f1)cout << "Yes ";
		else cout << "No ";
		if (f2)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}

