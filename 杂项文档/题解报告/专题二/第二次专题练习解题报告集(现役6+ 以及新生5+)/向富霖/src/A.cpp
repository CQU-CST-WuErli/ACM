#include <set>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

template <typename E>
class Matrix {
public:
	Matrix(){}		
	
	Matrix(int r, int c) {
		initialize(r, c);
	}
	
	Matrix(int r, int c, E* a) {
		m_row = r, m_col = c;
		m_pdata = new E[m_row * m_col + 5];
		for(int i = 0; i < m_row; i++)
		for(int j = 0; j < m_col; j++)
			m_pdata[i * m_col + j] = a[i * m_col + j];
	}
	
	~Matrix() { delete[] m_pdata; }
	
	void initialize(int r, int c) {
		m_row = r, m_col = c;
		m_pdata = new E[m_row * m_col + 5];
	}
	
	void output() {
		for(int i = 0; i < m_row; i++) {
			for(int j = 0; j < m_col; j++)
				cout << m_pdata[i * m_col + j] << ' ';
			cout << endl;
		}
		cout << endl;
	}
	
	void operator = (const Matrix& a) {	
		int row = a.m_row, col = a.m_col;
		for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++) {
			int id = i * col + j;		
			m_pdata[id] = a.m_pdata[id];	
		}
	}
	
	E& at(int r, int c) {
		return m_pdata[m_col * r + c];
	}

	friend Matrix operator + (const Matrix& a, const Matrix& b) {
		Matrix c(a.m_row, a.m_col, a.m_pdata);	
		int row = a.m_row, col = a.m_col;
		for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++) {
			int id = i * col + j;		
			c.m_pdata[id] = (a.m_pdata[id] + b.m_pdata[id]) % mod;	
		}
		return c;
	}
	
	friend Matrix operator * (const Matrix& a, const Matrix& b) {
		Matrix c(a.m_row, a.m_col, a.m_pdata);	
		int row = a.m_row, col = a.m_col;
		for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++) {
			int id = i * col + j;
			c.m_pdata[id] = 0;
			for(int k = 0; k < row; k++)
				c.m_pdata[id] = (c.m_pdata[id] + a.m_pdata[i * col + k] * b.m_pdata[k * col + j] % mod) % mod;	
		}
		return c;
	}
	
	friend Matrix operator ^ (const Matrix& a, ll p) {
		Matrix b(a.m_row, a.m_col, a.m_pdata);	
		Matrix c(a.m_row, a.m_col, a.m_pdata);	
		int row = a.m_row, col = a.m_col;
		for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
		c.m_pdata[i * col + j] = (i == j);
			
		while(p) {
			if(p & 1) c = c * b; 
			b = b * b;
			p >>= 1;		
		}
		return c;
	}
	
	int m_row, m_col;	
	E* m_pdata;
};

ll x[555], dp[5];

int main() {
#ifdef NEKO
	freopen("Nya.txt", "r", stdin);
#endif	
	int t; scanf("%d", &t);
	while(t--) {
		ll n, m; cin >> n >> m;
		memset(dp, 0, sizeof dp);
		for(int i = 1; i <= m; i++) {
			cin >> x[i];
			if(x[i] <= 3) dp[x[i]] = -1;
		}
		Matrix<ll> m1(3, 3);
		for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++) {
			if(!i) m1.at(i, j) = 1; 
			else if(i == 1 and !j) m1.at(i, j) = 1;
			else if(i == 2 and j == 1) m1.at(i, j) = 1; 
			else m1.at(i, j) = 0;
		}
		ll pre = 3, ans = 0;
		dp[0] = 1;
		if(dp[1] == -1) dp[1] = 0;
		else dp[1] = dp[0];
		if(dp[2] == -1) dp[2] = 0;
		else dp[2] = dp[1] + dp[0];
		if(dp[3] == -1) dp[3] = 0;
		else dp[3] = dp[2] + dp[1] + dp[0];
		if(n <= 3) { cout << dp[n] << endl; continue; }
		Matrix<ll> m2(3, 3);
		for(int i = 1; i <= m; i++) {
			ll l, m, r;
			if(x[i] <= pre) continue;
			m2 = m1 ^ (x[i] - pre); 
			l = 0; 
			m = (m2.at(1, 0) * dp[3] % mod) + (m2.at(1, 1) * dp[2] % mod) + (m2.at(1, 2) * dp[1] % mod);
			r = (m2.at(2, 0) * dp[3] % mod) + (m2.at(2, 1) * dp[2] % mod) + (m2.at(2, 2) * dp[1] % mod);
			dp[3] = l % mod, dp[2] = m % mod, dp[1] = r % mod;
			pre = x[i];
		}	
		m2 = m1 ^ (n - pre);
		if(x[m] == n) cout << "0\n";
		else {
			ans = (m2.at(0, 0) * dp[3] % mod) + (m2.at(0, 1) * dp[2] % mod) + (m2.at(0, 2) * dp[1] % mod);
			cout << ans % mod << endl;
		}
	}
	return 0;
}
