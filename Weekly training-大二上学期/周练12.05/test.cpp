#include<bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	freopen("C:\\Users\\john\\Desktop\\in.txt","w",stdout);
#endif
	srand(time(0));
	cout << 10 << endl;
	for (int t=1;t<=10;t++) {
		int n=rand()%10+1;
		cout << n << endl;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				int x=rand()%2;
				if (x==1) cout << '*';
				else cout << '.';
			}
			cout << endl; 
		}
	}
}
