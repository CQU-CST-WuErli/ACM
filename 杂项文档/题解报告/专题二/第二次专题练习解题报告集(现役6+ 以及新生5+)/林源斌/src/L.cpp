#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 1e5 + 4;
int x[maxn], n;
vector<int> v;
int div(int num){
//	cout << num << " help\n";
	v.clear();
	int limit = sqrt(num+1), i, j;
	for (i = 1; i <= limit; ++i){
		if (num % i == 0){
			v.push_back(i);
			if (i * i == num) break;
			v.push_back(num / i);
		}
	}
	sort(v.begin(), v.end(), greater<int>());
	for (i = 0; i < v.size(); ++i){
		for (j = 1; j <= n; ++j) if (x[j] % v[i] != 0) break;
		if (j == n + 1){
//			cout << "gcd = " << v[i] << endl;
			return v[i];
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	int i, j, k, kase;
	cin >> kase;
	while(kase--){
		cin >> n;
		for (i = 1; i <= n; ++i) cin >> x[i];
		sort(x+1, x+1+n);
		int total;
		if (x[1] == 0){
			total = x[n] / div(x[2]) + 1;
		}
		else total = x[n] / div(x[1]);
		double sum = total - n;
//		cout << total - n << endl;
		for (i = 1; i <= total; ++i) sum += total * 1.0 / (total + 1 - i);
		int temp = floor(sum);
		cout << temp << endl;
	}
	return 0;
} 

/*
floor居然是以科学计数法输出的
忘记0了
*/ 
