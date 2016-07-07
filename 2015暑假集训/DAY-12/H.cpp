//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015Äê CQU_CST_WuErli. All rights reserved.
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

int n,m;
char mp[25][25];
int maxd;

void init(){
	int cnt=0;
	maxd=0;
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
		cin >> mp[i][j];
		if (isdigit(mp[i][j])) maxd++;
	}   
}

const int dir_odd[4][2]={0,1,1,0,-1,0,0,-1};

bool check_all(){
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) if (mp[i][j]=='.') return false;
	return true;
}

bool check_odd(int x,int y,int d,int num){
	for (int i=0;i<num;i++){
		int nx=x+i*dir_odd[d][0],ny=y+i*dir_odd[d][1];
		if (isdigit(mp[nx][ny]) || isalpha(mp[nx][ny]) || nx<0 || ny<0 || nx>=n || ny>=n) 
			return false;
 	}
 	return true;
}

const int dir_even[4][2]={1,1,1,-1,-1,1,-1,-1};

bool check_even(int x,int y,int r,int c,int d){
	for (int i=x;i<x+r*dir_even[d][0];i++) for (int j=y;j<y+c*dir_even[d][1];j++)
		if (isdigit(mp[i][j]) || isalpha(mp[i][j]) || i<0 || j<0 || i>=n || j>=n) 
			return false;
	return true; 
}

bool dfs(int dep,int cnt,int pos){
//	look(dep);
//	look(cnt);
//	look(pos);
	if (dep==maxd+1){
		if (check_all()) {
			for (int i=0;i<n;i++) {
				for (int j=0;j<n;j++) 
					cout << mp[i][j];
				cout << endl;
			}
			return true;
		}
		return false;
	}
	for (int i=pos;i<n*n;i++){
		int r=i/n,c=i%n;
		if (isdigit(mp[r][c])){       
			int sum=mp[r][c]-'0';
			if (sum%2){                    // ÆæÅ¼·Ö¿ª 
				for (int i=0;i<4;i++){
					if (check_odd(r,c,i,sum)){
						for (int j=0;j<sum;j++) {
							mp[r+j*dir_odd[i][0]][c+j*dir_odd[i][1]]='A'+cnt;
						}
						if (dfs(dep+1,cnt+1,pos+1)) return true;
						mp[r][c]='0'+sum;
						for (int j=0;j<sum;j++) 
							mp[r+j*dir_odd[i][0]][c+j*dir_odd[i][1]]='.';
					}
				}
			}
			else if (sum%2==0){
				for (int i=1;i<sum;i++){
					if (sum%i==0){
						for (int j=0;j<4;j++){
							if (check_even(r,c,i,sum/i,j)) {
								for (int s=r;s<r+i*dir_even[j][0];s++)
									for (int t=c;t<c+sum/i*dir_even[j][1];t++)
										mp[s][t]='A'+cnt;
								if (dfs(dep+1,cnt+1,pos+1)) return true;
								for (int s=r;s<r+i*dir_even[j][0];s++)
									for (int t=c;t<c+sum/i*dir_even[j][1];t++){
										if (s==r && t==c) mp[s][t]='0'+cnt;
										else mp[s][t]='.';
									}
 							}
						}
					}
				}
			}
		}
	}
	return false;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> m){
		getchar();
		init();
//		for (int i=0;i<n;i++) {
//			for (int j=0;j<n;j++) cout << mp[i][j];
//			cout << endl;
//		}  
		dfs(0,0,0);
	}
	return 0;
}


