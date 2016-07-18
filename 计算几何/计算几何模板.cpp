//================二维计算几===================//

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

//	点之间距离
double DistanceToPoint(const Point& a,const Point& b) {
	double dx=a.x-b.x;
	double dy=a.y-b.y;
	return sqrt(dx*dx+dy*dy);
}
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
// 凸包
// 输入点p，个数n，输出ch
// 点不能重复
// 原来点的顺序会被破坏
// 有精度要求用dcmp比较
int ConvexHull(Point *p,int n,Point* ch) {
	sort(p + 1, p + 1 + n);
	int m = 1;
	for (int i = 1; i <= n; i++) {
		while(m > 2 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
		ch[m++] = p[i];
	}
	int k=m;
	for (int i = n - 1;i >= 1; i--) {
		while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
		ch[m++] = p[i];
	}
	if (n > 1) m--;
	return m;
}
// 直线
struct Line {
  Point p;
  Vector v;
  Line(const Point& p,const Vector& v):p(p),v(v) { }
  Point point(double t) {
    return p + v * t;
  }
  Line move(double d) {
    return Line(p + Normal(v) * d, v);
  }
};
// 构造直线
Line getLine(double x1, double y1, double x2, double y2) {
  Point p1(x1,y1);
  Point p2(x2,y2);
  return Line(p1, p2 - p1);
}
// 圆
struct Circle {
    Point c;    //圆心
    double r;   //半径

    Circle() {}
    Circle(const Circle& rhs): c(rhs.c), r(rhs.r) { }
    Circle(const Point& c, const double& r): c(c), r(r) { }

    Point point(double ang) const { return Point(c.x + cos(ang)*r, c.y + sin(ang)*r); } //圆心角所对应的点
    double area(void) const { return pi * r * r; }
};
//直线和圆的交点
int getLineCircleIntersection(Line& L,const Circle& C,vector<Point>& sol){
	double t1,t2;
	double a = L.v.x, b = L.p.x - C.c.x, c = L.v.y, d = L.p.y - C.c.y;
	double e = a*a + c*c, f = 2*(a*b + c*d), g = b*b + d*d - C.r*C.r;
	double delta = f*f - 4*e*g; // 判别式
	if(dcmp(delta) < 0) return 0; // 相离
	if(dcmp(delta) == 0) { // 相切
    	t1 = t2 = -f / (2 * e); sol.push_back(L.point(t1));
    	return 1;
  	}
  	// 相交
  	t1 = (-f - sqrt(delta)) / (2 * e); sol.push_back(L.point(t1));
  	t2 = (-f + sqrt(delta)) / (2 * e); sol.push_back(L.point(t2));
  	return 2;
}
// 计算极角
double angle(const Vector& v) {return atan2(v.y,v.x); }
// 两圆相交
int getCircleCircleIntersection(Circle& C1, Circle& C2, vector<Point>& sol) {
  double d = Length(C1.c - C2.c);
  if(dcmp(d) == 0) {
    if(dcmp(C1.r - C2.r) == 0) return -1; // 重合，无穷多交点
    return 0;
  }
  if(dcmp(C1.r + C2.r - d) < 0) return 0;
  if(dcmp(fabs(C1.r-C2.r) - d) > 0) return 0;
  double a = angle(C2.c - C1.c);
  double da = acos((C1.r*C1.r + d*d - C2.r*C2.r) / (2*C1.r*d));
  Point p1 = C1.point(a-da), p2 = C1.point(a+da);

  sol.push_back(p1);
  if(p1 == p2) return 1;
  sol.push_back(p2);
  return 2;
}
// 过点p到圆的切线，v[i]是第i条切线，返回切线条数
int getTangents(const Point& p,const Circle& C,Vector* v) {
	Vector u=C.c-p;
	double dist=Length(u);
	if (dist<C.r) return 0;
	else if (dcmp(dist-C.r)==0) {
		v[0]=Rotate(u,pi/2);
		return 1;
	}
	else {
		double ang=asin(C.r/dist);
		v[0]=Rotate(u,-ang);
		v[1]=Rotate(u,ang);
		return 2;
	}
}
// 两圆切线，-1无穷
// a[i]和b[i]分别是第i条切线在圆A和圆B上的切点
int getTangents(Circle& A,Circle& B,Point* a,Point* b) {
	int cnt=0;
	if (A.r<B.r) {swap(A,B);swap(a,b);}
	int d2=(A.c.x-B.c.x)*(A.c.x-B.c.x)+(A.c.y-B.c.y)*(A.c.y-B.c.y);
	int rdiff=A.r-B.r;
	int rsum=A.r+B.r;
	if (d2<rdiff*rdiff) return 0;
	double base=atan2(B.c.y-A.c.y,B.c.x-A.c.x);
	if (d2==0 && A.r==B.r) return -1;
	if (d2==rdiff*rdiff) {
		a[cnt]=A.point(base);b[cnt]=B.point(base);cnt++;
		return 1;
	}
	// 外切
	double ang=acos((A.r-B.r)/sqrt(d2));
	a[cnt]=A.point(ang+base);b[cnt]=B.point(ang+base);cnt++;
	a[cnt]=A.point(base-ang);b[cnt]=B.point(base-ang);cnt++;
	if (d2==rsum*rsum) {
		a[cnt]=A.point(base);b[cnt]=B.point(acos(-1)+base+ang);cnt++;
	}
	else if (d2>rsum*rsum) {
		double ang=acos((A.r+B.r)/sqrt(d2));
		a[cnt]=A.point(base+ang);b[cnt]=B.point(pi+base+ang);cnt++;
		a[cnt]=A.point(base-ang);b[cnt]=B.point(pi+base-ang);cnt++;
	}
	return cnt;
}
// 外接圆
Circle circumscribedCircle(const Point& p1,const Point& p2,const Point& p3) {
	double Bx=p2.x-p1.x,By=p2.y-p1.y;
	double Cx=p3.x-p1.x,Cy=p3.y-p1.y;
	double D=2*(Bx*Cy-By*Cx);
	double cx=(Cy*(Bx*Bx+By*By)-By*(Cx*Cx+Cy*Cy))/D+p1.x;
	double cy=(Bx*(Cx*Cx+Cy*Cy)-Cx*(Bx*Bx+By*By))/D+p1.y;
	Point p=Point(cx,cy);
	return Circle(p,Length(p1-p));
}
// 内切圆
Circle inscribedCircle(const Point& p1,const Point& p2,const Point& p3) {
	double a=Length(p2-p3);
	double b=Length(p3-p1);
	double c=Length(p1-p2);
	Point p=(p1*a+p2*b+p3*c)/(a+b+c);
	return Circle(p,DistanceToLine(p,p1,p2));
}
// 点在多边形内
int isPointInPolygon(Point& p,vector<Point>& poly) {
	int wn=0;
	int n=poly.size();
	for (int i=0;i<n;i++) {
		if (OnSegment(p,poly[i],poly[(i+1)%n])) return -1;
		int k=dcmp(Cross(poly[(i+1)%n]-poly[i],p-poly[i]));
		int d1=dcmp(poly[i].y-p.y);
		int d2=dcmp(poly[(i+1)%n].y-p.y);
		if (k>0 && d1<=0 && d2>0) wn++;
		if (k<0 && d2<=0 && d1>0) wn--;
	}
	if (wn!=0) return 1;
	return 0;
}

// 角度转弧度
double torad(double deg) {
	return deg/180*acos(-1);
}
//==================二维计算几何结束======================//