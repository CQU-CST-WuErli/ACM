#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <string>
#include <math.h>
using namespace std;

struct Point
{
    int x,y;
    Point(int _x = 0,int _y = 0)
    {
        x = _x,y = _y;
    }
    Point operator - (const Point &b)const
    {
        return Point(x-b.x,y-b.y);
    }
    int operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
    void input()
    {
        scanf("%d%d",&x,&y);
    }
};
struct Line
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e)
    {
        s = _s;
        e = _e;
    }
};
bool onSeg(Point P,Line L)
{
    return
    ((L.s-P)^(L.e-P)) == 0 &&
    (P.x-L.s.x)*(P.x-L.e.x) <= 0 &&
    (P.y-L.s.y)*(P.y-L.e.y) <= 0;
}
int sqdis(Point a,Point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

const int MOD = 10007;
int INV[MOD];
//求ax = 1( mod m) 的x值，就是逆元(0<a<m)
long long inv(long long a,long long m)
{
    if(a == 1)return 1;
    return inv(m%a,m)*(m-m/a)%m;
}
struct Matrix
{
    int mat[330][330];
    void init()
    {
        memset(mat,0,sizeof(mat));
    }
    int det(int n)//求行列式的值模上MOD，需要使用逆元
    {
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                mat[i][j] = (mat[i][j]%MOD+MOD)%MOD;
        int res = 1;
        for(int i = 0;i < n;i++)
        {
            for(int j = i;j < n;j++)
                if(mat[j][i]!=0)
                {
                    for(int k = i;k < n;k++)
                        swap(mat[i][k],mat[j][k]);
                    if(i != j)
                        res = (-res+MOD)%MOD;
                    break;
                }
            if(mat[i][i] == 0)
            {
                res = -1;//不存在(也就是行列式值为0)
                break;
            }
            for(int j = i+1;j < n;j++)
            {
                //int mut = (mat[j][i]*INV[mat[i][i]])%MOD;//打表逆元
                int mut = (mat[j][i]*inv(mat[i][i],MOD))%MOD;
                for(int k = i;k < n;k++)
                    mat[j][k] = (mat[j][k]-(mat[i][k]*mut)%MOD+MOD)%MOD;
            }
            res = (res * mat[i][i])%MOD;
        }
        return res;
    }
    void print(int n) {
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) cout << mat[i][j] << ' ' ;
                cout << endl;
        }
    }
};

Point p[330];
int n,R;
bool check(int k1,int k2)//判断两点的距离小于等于R，而且中间没有点阻隔
{
    if(sqdis(p[k1],p[k2]) > R*R)return false;
    for(int i = 0;i < n;i++)
        if(i!=k1 && i!=k2)
            if(onSeg(p[i],Line(p[k1],p[k2])))
                return false;
    return true;
}
int g[330][330];
int main()
{
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&R);
        for(int i = 0;i < n;i++)
            p[i].input();
        memset(g,0,sizeof(g));
        for(int i = 0;i < n;i++)
            for(int j = i+1;j <n;j++)
                if(check(i,j))
                    g[i][j] = g[j][i] = 1;
        Matrix ret;
        ret.init();
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                if(i != j && g[i][j])
                {
                    ret.mat[i][j] = -1;
                    ret.mat[i][i]++;
                }
        // ret.print(n);
        printf("%d\n",ret.det(n-1));
    }
    return 0;
}