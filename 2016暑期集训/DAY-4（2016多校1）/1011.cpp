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
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

struct Point {
	double x, y, z;
	Point() {}
	Point(double x, double y, double z):x(x), y(y), z(z){}
	void read() {
		scanf("%lf%lf%lf",  &x, &y,  &z);
	}
	void print() {
		printf("(%f, %f, %f)\n", x, y, z);
	}
	Point operator - (const Point& rhs) {
		Point ret;
		ret.x = x - rhs.x;
		ret.y = y - rhs.y;
		ret.z = z - rhs.z;
		return ret;
	}
	Point operator + (const Point& rhs) {
		Point ret;
		ret.x = x + rhs.x;
		ret.y = y + rhs.y;
		ret.z = z + rhs.z;
		return ret;
	}
	double length() {
		return sqrt(x * x + y * y + z * z);
	}
	double operator * (const Point& rhs) {
		return x * rhs.x + y * rhs.y + z * rhs.z;
	}
	Point operator * (double d) {
		return Point(x * d, y * d, z * d);
	}
	Point operator / (double d) {
		return Point(x / d, y / d, z / d);
	}
};
Point a, b, c, d;

Point Cross(Point& a, Point& b) {
	Point ret;
	ret.x = a.y * b.z - b.y * a.z;
	ret.y = a.z * b.x - b.z * a.x;
	ret.z = a.x * b.y - b.x * a.y;
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    double x, y, z;
    while (scanf("%lf%lf%lf", &x, &y, &z) == 3) {
    	a.x = x, a.y = y, a.z = z;
    	b.read(); c.read(); d.read();
    	Point ab = b - a;
    	Point ac = c - a;
    	Point ad = d - a;
    	Point bc = c - b;
    	Point bd = d - b;
    	if (Cross(ab, ac) * ad == 0) {
    		puts("O O O O");
    		continue;
    	}
    	double sa = Cross(ab, ac).length();
    	double sb = Cross(ab, ad).length();
    	double sc = Cross(ac, ad).length();
    	double sd = Cross(bc, bd).length();
    	Point O = d * sa + c * sb +  b * sc + a * sd;
    	O = O / (sa + sb + sc + sd);
    	// O.print();
    	double A = (b - a).length(); A *= A;
    	double B = (d - a).length(); B *= B;
    	double C = (c - a).length(); C *= C;
    	double D = (d - c).length(); D *= D;
    	double E = (b - c).length(); E *= E;
    	double F = (b - d).length(); F *= F;
    	double V = sqrt(A * D * (B + C + E + F - A - D) + B * E * (A+C+D+F-B-E) + C * F * (A+B+D+E-C-F) - A*B*F -B*C*D - C*A*E-D*E*F) / 12;
    	double r = 3 * V / (sa + sb + sc + sd) * 2.0;
    	printf("%.4f %.4f %.4f %.4f\n", O.x, O.y, O.z, r);
    };
	return 0;
}