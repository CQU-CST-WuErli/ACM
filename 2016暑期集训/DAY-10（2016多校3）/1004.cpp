//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
//#pragma comment(linker, "/STACK:102400000,102400000")
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
#include <bitset>
#include <cassert>
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
const int MOD=3;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n, m;
int mp[33][33];
int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

int getID(int i, int j) {
	return (i - 1) * m + j;
}

pair<int, int> getPOS(int id) {
	int x, y;
	if (id % m == 0)
		return make_pair(id / m, m);
	else return make_pair(id / m + 1, id % m);
}

int a[1000][1000];
int x[1000];
int free_x[1000];

int gcd(int a, int b) {
	return __gcd(a, b);
}
int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}
int inv(int a, int m) {
	if (a == 1) return 1;
	return inv(m % a, m) * (m - m / a) % m;
}

int Gauss(int equ, int var) {
	CLR(x);
	for (int i = 1; i <= var; i++) free_x[i] = 1;
	int max_r;
	int row = 1;
	int free_index = -1;
	int free_x_num;
	for (int col = 1; row <= equ && col <= var; row++, col++) {
		max_r = row;
		for (int i = row + 1; i <= equ; i++) {
			if (abs(a[i][col]) > abs(a[max_r][col]))
				max_r = i;
		}
		if(max_r != row) {
			for(int i = 1; i <= var + 1; i++)
                swap(a[row][i], a[max_r][i]);
		}
		if (a[row][col] == 0) {
			row--;
			continue;
		}
		for (int i = row + 1; i <= equ; i++) {
			if (a[i][col]) {
				int LCM = lcm(abs(a[i][col]), abs(a[row][col]));
                int tp1 = LCM / abs(a[i][col]), tp2 = LCM / abs(a[row][col]);
                if(a[row][col] * a[i][col] < 0)
                    tp2 = -tp2;
                for(int j = col; j <= var + 1; j++) {
                    a[i][j] = tp1 * a[i][j] - tp2 * a[row][j];
                    a[i][j] = (a[i][j] % 3 + 3) % 3;
                }
			}
		}
	}
    // for(int i=row; i<equ; i++)
    //     if(a[i][var]).
    //         return -1;///无解
	// if(row <= var) {
 //        for(int i = row - 1; i >= 1; i--) {
 //            free_x_num = 0;
 //            for(int j = 1; j <= var; j++) {
 //            	if(a[i][j] && free_x[j]) {
 //                    free_x_num++;
 //                    free_index = j;
 //                }
 //            }
 //            if(free_x_num > 1 || free_index == -1) continue;
 //            int tmp = a[i][var + 1];
 //            for(int j = 1; j <= var; j++)
 //                if(a[i][j] && j!=free_index)
 //                {
 //                    tmp -= a[i][j]*x[j];
 //                    tmp = (tmp%3+3)%3;
 //                }
 //            x[free_index] = (tmp*a[i][free_index]);/// 求出该变元.
 //            x[free_index] %= 3;
 //            free_x[free_index] = 0; /// 该变元是确定的.
 //        }
 //        return var - row + 1;///自由变元的个数
 //    }
    for(int i = var; i >= 1; i--) {
        int tmp = a[i][var + 1];
        for(int j=i + 1; j <= var; j++)
            if (a[i][j]) {
                tmp -= a[i][j] * x[j];
                tmp = (tmp % 3 + 3) % 3;
            }
        if (!a[i][i]) x[i] = tmp * a[i][i];
        else x[i] = tmp * inv(a[i][i], 3) % 3;
        x[i] %= 3;
    }
    return 0;
}

void debug() {
	for (int i = 1; i <= n * m; i++) {
    	for (int j = 1; j <= n * m + 1; j++) {
    		cout << a[i][j] << ' ';
    	}
    	puts("");
    }
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while (t--) {
    	SII(n, m);
    	CLR(mp);
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= m; j++) {
    			SI(mp[i][j]);
    		}
    	}
    	CLR(a);
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= m; j++) {
    			int id = getID(i, j);
    			a[id][id] = 2;
    			for (int s = 0; s < 4; s++) {
    				int tx = i + dir[s][0], ty = j + dir[s][1];
    				if (tx < 1 || ty < 1 || tx > n || ty > m) continue;
    				int pos = getID(tx, ty);
    				a[id][pos] = 1;
    			}
    			a[id][n * m + 1] = (3 - mp[i][j]) % 3;
    		}
    	}
    	// debug();
    	int ans = Gauss(n * m, n * m);
    	vector<pair<int, int> > op;
    	for (int i = 1; i <= n * m; i++) if (x[i]) {
    		while (x[i]) {
    			pair<int, int> tmp = getPOS(i);
    			op.push_back(tmp);
    			x[i]--;
    		}
    	}
    	cout << op.size() << endl;
    	for (auto& it : op) {
    		printf("%d %d\n", it.first, it.second);
    	}
    }
	return 0;
}