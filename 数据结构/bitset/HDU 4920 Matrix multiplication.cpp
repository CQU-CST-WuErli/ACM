//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <stdio.h>
#include <ctype.h>
const int N = 805;
int a[N][N], b[N][N];
int n;
int c[N][N];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (scanf("%d", &n) == 1) {
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= n; j++) {
    			scanf("%d", &a[i][j]);
    			a[i][j] %= 3;
    		}
    	}
    	for (int j = 1; j <= n; j++) {
    		for (int i = 1; i <= n; i++) {
    			scanf("%d", &b[i][j]);
    			b[i][j] %= 3;
    		}
    	}
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= n; j++) {
    			c[i][j] = 0;
    			for (int k = 1; k <= n; k++) {
    				c[i][j] += a[i][k] * b[j][k];
    			}
    		}
    	}
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= n; j++) {
    			if (j > 1) printf(" ");
    			printf("%d", c[i][j] % 3);
    		}
    		puts("");
    	}
    }
	return 0;
}