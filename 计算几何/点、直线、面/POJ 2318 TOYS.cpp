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
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for(int flag=start;flag>=end;flag--)
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

//================二维计算几===================//

//	点的定义及相关函数
struct Point
{
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
// 	点积
double Dot(const Vector& A,const Vector& B) {	return A.x*B.x+A.y*B.y;	}
// 	长度
double Length(const Vector& A) {	return sqrt(Dot(A,A));	}
//	夹角
double Angle(const Vector& A, const Vector& B) {	return acos(Dot(A,B)/Length(A)/Length(B));	}
//	叉积
double Cross(const Vector& A, const Vector& B) {	return A.x*B.y-A.y*B.x;	}
//	三角形面积的两倍
double Area2(const Point& A, const Point& B, const Point& C) {	return Cross(B-A,C-A);	}
//	旋转，rad是弧度,逆时针
Vector Rotate(const Vector& A,const double rad) {
	return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}
//	法向量
Vector Normal(const Vector& A) {
	double L=Length(A);
	return Vector(-A.y/L,A.x/L);
}
//两直线交点，确保只有一个交点
Point GetLineIntersection(const Point& P,const Vector& v,const Point& Q,const Vector& w) {
	Vector u=P-Q;
	double t=Cross(w,u)/Cross(v,w);
	return P+v*t;
}
//	点到直线距离 P到AB的距离
double DistanceToLine(const Point& P,const Point& A,const Point& B) {
	Vector v1=B-A,v2=P-A;
	return fabs(Cross(v1,v2))/Length(v1);	//	不取绝对值就是有向距离
}
//	点到线段距离 P到|AB|的距离
double DistanceToSegment(const Point& P,const Point& A,const Point& B) {
	if (A==B) return Length(P-A);
	Vector v1=B-A,v2=P-A,v3=P-B;
	if (dcmp(Dot(v1,v2))<0) return Length(v2);
	else if (dcmp(Dot(v1,v3))>0) return Length(v3);
	else return fabs(Cross(v1,v2))/Length(v3);
}
//	点在直线上的投影，P到AB的投影
Point GetLineProjection(const Point& P,const Point& A,const Point& B) {
	Vector v=B-A;
	return A+v*(Dot(v,P-A)/Dot(v,v));
}
//	线段规范相交
bool SegmentProperIntersection(const Point& a1,const Point& a2,const Point& b1,const Point& b2) {
	double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1);
	double c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
	return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}
// 点在线段上
bool OnSegment(const Point& P,const Point& A,const Point& B) {
	return dcmp(Cross(A-P,B-P))==0 && dcmp(Dot(A-P,B-P))<0;
}
// 线段普通相交
bool SegmentIntersection(const Point& a1,const Point& a2,const Point& b1,const Point& b2) {
	double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1);
	double c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
	if (dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0) return true;
	else if (dcmp(c1)==0 && OnSegment(b1,b2,a1)) return true;
	else if (dcmp(c2)==0 && OnSegment(b1,b2,a2)) return true;
	else if (dcmp(c3)==0 && OnSegment(a1,a2,b1)) return true;
	else if (dcmp(c4)==0 && OnSegment(a1,a2,b2)) return true;
	return false;
}
//	凸多边形面积 *p是数组   n是点数
double ConvexPolygonArea(Point* p,int n) {
	double area=0;
	for (int i=1;i<n-1;i++)
		area+=Cross(p[i]-p[0],p[i+1]-p[0]);
	return area/2.0;
}
//	多边形面积 *p是数组   n是点数
double PolygonArea(Point* p,int n) {
	double area=0;
	for (int i=1;i<n-1;i++)
		area+=Cross(p[i]-p[0],p[i+1]-p[0]);
	return area/2.0;
}
//==================二维计算几何结束======================//

int n,m;
double X1,X2,Y1,Y2;
Point up[1050],down[1050];
int ans[1050];

bool check(int i,int j,Point& tt) {
	Vector aa=up[i]-down[i],bb=up[j]-down[j];
	Vector cc=tt-down[i],dd=tt-down[j];
	if (Cross(cc,aa)>=0 && Cross(dd,bb)<=0 && tt.y<=Y1 && tt.y>=Y2) return true;
	return false;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int kase=1;
    while(SII(n,m)==2 && n) {
    	if (kase!=1) cout << endl; kase++;
    	scanf("%lf%lf%lf%lf",&X1,&Y1,&X2,&Y2);
    	up[0]=Point(X1,Y1);down[0]=Point(X1,Y2);
    	up[n+1]=Point(X2,Y1);down[n+1]=Point(X2,Y2);
    	rep(i,1,n) {
    		double u,l;
    		scanf("%lf%lf",&u,&l);
    		up[i]=Point(u,Y1);
    		down[i]=Point(l,Y2);
    	}
    	// for (int i=0;i<=n+1;i++) {
    	// 	cout << up[i].x << ' ' << up[i].y << ' ' << down[i].x << ' ' << down[i].y << endl;
    	// }
        CLR(ans);
        Point tt;
        int Max=0;
        rep(i,1,m) {
        	tt.read();
        	rep(j,0,n) {
        		if (check(j,j+1,tt)) {
        			ans[j]++;
        			Max=max(Max,ans[j]);
        			break;
        		}
        	}
        }
        puts("Box");
        for (int i=1;i<=Max;i++) {
        	int tt=0;
        	for (int j=0;j<=n;j++) if (ans[j]==i) tt++;
        	if (tt!=0) printf("%d: %d\n",i,tt);
        }
    }
	return 0;
}