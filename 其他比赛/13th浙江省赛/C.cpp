//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d", &a)
#define SII(a,b) scanf("%d%d", &a, &b)
#define SIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int d;
int b[5];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int t;
	SI(t);
	while (t--) {
		int pos[6];
		int label[6];
		for (int i = 1; i <= 5; i++) {
			SI(d);
			for (int j = 1; j <= 4; j++) SI(b[j]);
			// for (int j = 1; i <= 4; j++) cout << b[j] <<  ' ';
			if (i == 1) {
				switch(d) {
					case 1: {
						printf("1 %d\n", b[1]);
						pos[1] = 1;
						label[1] = b[1];
						break;
					}
					case 2: {
						printf("2 %d\n", b[2]);
						pos[1] = 2;
						label[1] = b[2];
						break;
					}
					case 3: {
						printf("3 %d\n", b[3]);
						pos[1] = 3;
						label[1] = b[3];
						break;
					}
					case 4: {
						printf("4 %d\n", b[4]);
						pos[1] = 4;
						label[1] = b[4];
						break;
					}
				}
			}
			else if (i == 2) {
				switch(d) {
					case 1: {
						for (int j = 1; j <= 4; j++) if (b[j] == 4) {
							pos[2] = j;
							break;
						}
						label[2] = b[pos[2]];
						printf("%d %d\n", pos[2], b[pos[2]]);
						break;
					}
					case 2: {
						pos[2] = pos[1];
						label[2] = b[pos[2]];
						printf("%d %d\n", pos[2], b[pos[2]]);
						break;
					}
					case 3: {
						pos[2] = 1;
						label[2] = b[pos[2]];
						printf("1 %d\n", b[pos[2]]);
						break;
					}
					case 4: {
						pos[2] = pos[1];
						label[2] = b[pos[2]];
						printf("%d %d\n", pos[2], b[pos[2]]);
						break;
					}
				}
			}
			else if (i == 3) {
				switch(d) {
					case 1: {
						for (int j = 1; j <= 4; j++) if (b[j] == label[2]) {
							pos[3] = j;break;
						}
						label[3] = b[pos[3]];
						printf("%d %d\n", pos[3], b[pos[3]]);
						break;
					}
					case 2: {
						for (int j = 1; j <= 4; j++) if (b[j] == label[1]) {
							pos[3] = j;break;
						}
						label[3] = b[pos[3]];
						printf("%d %d\n", pos[3], b[pos[3]]);
						break;
					}
					case 3: {
						pos[3] = 3;
						label[3] = 3;
						printf("%d %d\n", pos[3], b[pos[3]]);
						break;
					}
					case 4: {
						for (int j = 1; j <= 4; j++) if (b[j] == 4) {
							pos[3] = j;break;
						}
						label[3] = b[pos[3]];
						printf("%d %d\n", pos[3], b[pos[3]]);
						break;
					}
				}
			}
			else if (i == 4) {
				switch(d) {
					case 1: {
						pos[4] = pos[1];
						label[4] = b[pos[4]];
						printf("%d %d\n", pos[4], b[pos[4]]);
						break;
					}
					case 2: {
						pos[4] = 1;
						label[4] = b[pos[4]];
						printf("%d %d\n", pos[4], b[pos[4]]);
						break;
					}
					case 3: {
						pos[4] = pos[2];
						label[4] = b[pos[4]];
						printf("%d %d\n", pos[4], b[pos[4]]);
						break;
					}
					case 4: {
						pos[4] = pos[2];
						label[4] = b[pos[4]];
						printf("%d %d\n", pos[4], b[pos[4]]);
						break;
					}
				}
			}
			else if (i == 5) {
				switch(d) {
					case 1: {
						for (int j = 1; j <= 4; j++) if (b[j] == label[1]) {
							pos[5] = j;
							break;
						}
						label[5] = b[pos[5]];
						printf("%d %d\n", pos[5], b[pos[5]]);
						break;
					}
					case 2: {
						for (int j = 1; j <= 4; j++) if (b[j] == label[2]) {
							pos[5] = j;
							break;
						}
						label[5] = b[pos[5]];
						printf("%d %d\n", pos[5], b[pos[5]]);
						break;
					}
					case 3: {
						for (int j = 1; j <= 4; j++) if (b[j] == label[4]) {
							pos[5] = j;
							break;
						}
						label[5] = b[pos[5]];
						printf("%d %d\n", pos[5], b[pos[5]]);
						break;
					}
					case 4: {
						for (int j = 1; j <= 4; j++) if (b[j] == label[3]) {
							pos[5] = j;
							break;
						}
						label[5] = b[pos[5]];
						printf("%d %d\n", pos[5], b[pos[5]]);
						break;
					}
				}
			}
		}
	}
	return 0;
}