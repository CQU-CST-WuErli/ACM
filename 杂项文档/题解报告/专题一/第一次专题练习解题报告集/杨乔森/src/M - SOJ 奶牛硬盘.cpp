// SOJ 奶牛硬盘.cpp : 定义控制台应用程序的入口点。
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int t;
const int MAXN = 1e6 + 10;
char s[MAXN];
int main()
{
	cin >> t;
	int cases = 0;
	while (t--){
		++cases;
		cin >> s;
		int len = strlen(s);
		int k = 0;
		for (int i = 0; i < len; ++i){
			if (s[i] == '['){
				switch (s[i+1])
				{
				case 'Y':++k;
				case 'Z':++k;
				case 'E':++k;
				case 'P':++k;
				case 'T':++k;
				case 'G':++k;
				case 'M':++k;
				case 'K':++k;
				case 'B':
				default:
					break;
				}
				if (s[i + 1] == 'B')--i;
				i += 3;
				break;
			}
		}
		double ans = 1 - (pow(1000.0, k) / pow(1024.0, k));
		ans *= 100;
		printf("Case #%d: %.2f%%\n", cases, ans);
	}
	return 0;
}

