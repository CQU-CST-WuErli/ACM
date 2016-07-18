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
const double eps=1e-8;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

//	点的定义及相关函数
struct Point {
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
	void read() {
		scanf("%lf%lf",&x,&y);
	}
	void print() {
		printf("x=%lf y=%lf\n",x,y);
	}
};
typedef Point Vector;
//	向量相加或点和向量相加
Vector operator + (const Vector& A, const Vector& B) {	return Vector(A.x+B.x,A.y+B.y);	}
//	点-点=向量
Vector operator - (const Vector& A, const Vector& B) {	return Vector(A.x-B.x,A.y-B.y);	}
//	向量和数乘除
Vector operator * (const Vector& A, const double p) {	return Vector(A.x*p,A.y*p);	}
Vector operator / (const Vector& A, const double p) {	return Vector(A.x/p,A.y/p);	}
// 比较相关
bool operator < (const Point& A, const Point& B) {
	return A.x<B.x || (A.x==B.x && A.y<B.y);
}
//	判断与0关系
int dcmp(double x) {
	if (fabs(x)<eps) return 0;
	else return x<0?-1:1;
}
//	相等
bool operator == (const Point& A, const Point& B) {
	return dcmp(A.x-B.x)==0 && dcmp(A.y-B.y)==0;
}
double Cross(const Vector& A, const Vector& B) {	return A.x*B.y-A.y*B.x;	}
// 凸包
// 输入点p，个数n，输出ch
// 点不能重复
// 原来点的顺序会被破坏
// 有精度要求用dcmp比较
int ConvexHull(Point *p,int n,Point* ch) {
	sort(p + 1, p + 1 + n);
	int m = 1;
	for (int i = 1; i <= n; i++) {
		while(m > 2 && dcmp(Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2])) <= 0) m--;
		ch[m++] = p[i];
	}
	int k=m;
	for (int i = n - 1;i >= 1; i--) {
		while (m > k && dcmp(Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2])) <= 0) m--;
		ch[m++] = p[i];
	}
	if (n > 1) m--;
	return m;
}

int n, k;
Point farm[200020], barn[200020];
Point poly[200020];
int ans[200200];

bool check(Point& A, Point& B, Point& C, Point& D) {
	Vector AC = C - A, AD = D - A, AB = B - A;
	Vector DA = A - D, DB = B - D, DC = C - D;
	return dcmp(Cross(AB, AC)) * dcmp(Cross(AB, AD)) <= 0 && dcmp(Cross(DB, DA)) * dcmp(Cross(DB, DC)) <= 0;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T; SI(T);
	while (T--) {
		SI(n);
		for (int i = 1; i <= n; i++)
			farm[i].read();
		farm[n + 1] = farm[1];
		SI(k);
		for (int i = 1; i <= k; i++)
			barn[i].read();
		k = ConvexHull(barn, k, poly);
		// lookln(k);
		// for (int i = 1; i < k; i++)
		// 	poly[i].print();
		Point O = (poly[1] + poly[3]) / 2.0;
		if (k == 4) O = (O + poly[2]) / 2.0;
		int id = 0;
		int cnt = 1;
		for (int i = 1; i < k; i++) {
			while (1) {
				if (check(O, poly[i], farm[cnt], farm[cnt + 1])) {
					ans[id++] = cnt > n ? cnt - n : cnt;
					ans[id++] = cnt + 1 > n ? cnt + 1 - n : cnt + 1;
					break;
				}
				cnt++;
				if (cnt > n) cnt -= n;
			}
		}
		puts("Yes");
		sort(ans, ans + id);
		id = unique(ans, ans + id) - ans;
		printf("%d\n", id);
		for (int i = 0; i < id; i++) {
			if (i) printf(" ");
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \|     |//  `.
            /  \|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
			佛祖保佑		永无BUG
*/