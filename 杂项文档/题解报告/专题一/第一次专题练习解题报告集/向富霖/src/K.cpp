#include <set>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 15;
const int maxm = 1e6 + 15;
const int inf = 0x3f3f3f3f;
typedef long long ll;

int s[3 * maxn];

int MinimumRepresentation(int* s, int l) {  
	int i = 0, j = 1, k = 0, t;  
    while(i < l && j < l && k < l) {
        t = s[(i + k) % l] - s[(j + k) % l];  
        if(!t) k++;  
        else{  
            if(t > 0) i = i + k + 1;  
            else j = j + k + 1;  
            if(i == j) j++;  
            k = 0;  
        }  
    }  
    return min(i, j);  
}  

int main() {
#ifdef NEKO
	freopen("Nya.txt", "r", stdin);
#endif	
	int t; scanf("%d", &t);
	while(t--) {
		int n; scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", s + i);
		int ans = MinimumRepresentation(s, n);
		for(int i = ans; i < n; i++)
			printf("%d%c", s[i], " \n"[i == ans - 1]);
		for(int i = 0; i < ans; i++)
			printf("%d%c", s[i], " \n"[i == ans - 1]);
	}	
	return 0;
}
