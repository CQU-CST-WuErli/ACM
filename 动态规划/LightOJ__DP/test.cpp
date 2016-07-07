#include <iostream>
#include <cstdio>

using namespace std;
template <typename T>
struct dog{
	T x, y;
/*	dog(T a, T b){
		this->x = a+b;
		this->y = b;
	};*/
	dog(T a, T b):x(a+b),y(b){
	};
};
template <typename T>
T gcd(T a, T b){
	return b == 0 ? a : gcd(b, a%b);
}
int main(){
//	dog<int> dogone(1,2);
//	dog<double> dogtwo(1.2, 3.7);
//	printf("%d\n", dogone.x);
//	printf("%.3f\n", dogtwo.x);
	int m, n;
	printf("point1\n");
	scanf("%d%d\n", &m, &n);
	printf("%d\n", gcd(m, n));
	printf("point2\n");
	long long dog1, dog2;
	scanf("%lld%lld", &dog1, &dog2);
	printf("%lld\n", gcd(dog1, dog2));
	return 0;
}
