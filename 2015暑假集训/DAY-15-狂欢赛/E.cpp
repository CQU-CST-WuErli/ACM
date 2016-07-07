//
//This code was copy from JamesQi
//
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <ctime>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#include <complex>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << #x << "= " << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

typedef complex <ll> cll;

bool divis(const cll& a,const cll& b){
	cll C(0,0);
	C=a/b;
	return (b*C==a); 
} 

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	ll x,y;
	cin >> x >> y;
	cll A(x,y);
	cin >> x >> y;
	cll B(x,y);
	cin >> x >> y;
	cll C(x,y);
	cll I(0,1);
	int ans=0;
	if (C.real()==0 && C.imag()==0){
		if (A==B) ans=1;
		else if (-A==B) ans=1;
		else if (B==A*I) ans=1;
		else if (B==-A*I) ans=1; 
	} 
	else {
		if (divis(B-A,C)) ans=1;
		else if (divis(B+A,C)) ans=1;
		else if (divis(B-A*I,C)) ans=1;
		else if (divis(B+A*I,C)) ans=1;
	}
	if (ans) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}


