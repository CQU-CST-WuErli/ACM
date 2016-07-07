#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int maxd, n, len[10], pos[10];
char s[10][10];

int h() {
	int res = 0; 
	for(int i = 1; i <= n; i++) {
		if(res < len[i] - pos[i])
			res = len[i] - pos[i];
	}
	return res;
}

char dna[4] = {'A', 'C', 'G', 'T'}; 

bool IDAstar(int dep = 0) {
	if(dep + h() > maxd) return false;
	if(dep == maxd) return true;
	int temp[10];
	memcpy(temp, pos, sizeof pos);	
	for(int j = 0; j < 4; j++) {
		bool flag = false;
		for(int i = 1; i <= n; i++) {
			if(pos[i] == len[i]) continue;
			if(s[i][pos[i]] == dna[j])
				pos[i]++, flag = true;
		}
		if(!flag) continue;
		if(IDAstar(dep + 1)) return true;
		memcpy(pos, temp, sizeof temp);
	}
	return false;
}

int main() {
#ifdef NEKO
	freopen("Nya.txt", "r", stdin);
	//freopen("out.txt", "w+", stdout);
#endif	
	int t; scanf("%d", &t);
	while(t--) {
		scanf("%d", &n); maxd = 0;
		cout << n << endl;
		for(int i = 1; i <= n; i++) {
			scanf("%s", s[i]);
			len[i] = strlen(s[i]);
			maxd = max(maxd, len[i]);
		}
		memset(pos, 0, sizeof pos);
		while(!IDAstar()) maxd++;
		printf("%d\n", maxd);
	}
	return 0;
}
