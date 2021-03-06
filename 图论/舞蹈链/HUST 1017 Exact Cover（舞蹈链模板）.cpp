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
#include <list>
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
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=1010;

int n,m;

struct Node {
	int right,left,down,up;
	int size;
	int x,y;
};

struct DLX {
	const static int maxn=1000010; // 节点总数
	Node p[maxn];
	int size;						// 节点标记
	int head[maxn];					// 行标指针
	int vis[maxn];
	stack<int> Ans;
	int ans;
	void init(int m) {
		for (int i=0;i<=m;i++) {
			p[i].up=p[i].down=i;
			p[i].left=i-1;p[i].right=i+1;
			p[i].size=0;
		}
		p[0].left=m;p[m].right=0;
		OFF(head);
		size=m+1;
		ans=-1;
		while (Ans.size()) Ans.pop();
	}
	void link(int row,int col) {
		p[size].x=row;p[size].y=col;p[col].size++;
		p[size].up=p[col].up;p[p[col].up].down=size;
		p[col].up=size;p[size].down=col;
		if (head[row]<0) head[row]=p[size].left=p[size].right=size;
		else {
			p[size].right=p[head[row]].right;p[p[head[row]].right].left=size;
			p[size].left=head[row];p[head[row]].right=size;
		}
		size++;
	}
	// exact cover
	void remove(int c) {
		p[p[c].right].left=p[c].left;
		p[p[c].left].right=p[c].right;
		for (int i=p[c].down;i!=c;i=p[i].down) {
			for (int j=p[i].right;j!=i;j=p[j].right) {
				p[p[j].down].up=p[j].up;
				p[p[j].up].down=p[j].down;
				p[p[j].y].size--;
			}
		}
	}
	void resume(int c) {
		p[p[c].left].right=c;
		p[p[c].right].left=c;
		for (int i=p[c].up;i!=c;i=p[i].up) {
			for (int j=p[i].left;j!=i;j=p[j].left) {
				p[p[j].down].up=j;
				p[p[j].up].down=j;
				p[p[j].y].size++;
			}
		}

	}
	bool dfs(int cnt) {
		if (ans!=-1) return true;
		if (p[0].right==0) {
			ans=cnt;
			return true;
		}
		int c=0;
		int Min=INF_INT;
		for (int i=p[0].right;i!=0;i=p[i].right)
			if (Min>p[i].size) Min=p[i].size,c=i;
		remove(c);
		for (int i=p[c].down;i!=c;i=p[i].down) {
			Ans.push(p[i].x);
			for (int j=p[i].right;j!=i;j=p[j].right) {
				remove(p[j].y);
			}
			if (dfs(cnt+1)) return true;
			for (int j=p[i].left;j!=i;j=p[j].left) {
				resume(p[j].y);
			}
			Ans.pop();
		}
		resume(c);
		return false;
	}
	// exact cover ends;
	// multiple cover
	void del(int c) {
		for (int i=p[c].down;i!=c;i=p[i].down) {
			p[p[i].right].left=p[i].left;
			p[p[i].left].right=p[i].right;
		}
	}
	void rec(int c) {
		for (int i=p[c].up;i!=c;i=p[i].up) {
			p[p[i].right].left=i;
			p[p[i].left].right=i;
		}
	}
	int h() {
		int ret=0;
		CLR(vis);
		for (int i=p[0].right;i!=0;i=p[i].right) if (!vis[i]) {
			ret++;vis[i]=1;
			for (int j=p[i].down;j!=i;j=p[j].down)
				for (int k=p[j].right;k!=j;k=p[k].right)
					vis[p[k].y]=1;
		}
		return ret;
	}
	void DFS(int cnt) {
		if (p[0].right==0) ans=min(ans,cnt);
		else if (h()+cnt<ans) {
			int c=0;
			int Min=INF_INT;
			for (int i=p[c].right;i!=0;i=p[i].right){
				if (p[i].size<Min) Min=p[i].size,c=i;
			}
			// lookln(c);
			for (int i=p[c].down;i!=c;i=p[i].down) {
				del(i);
				for (int j=p[i].right;j!=i;j=p[j].right) del(j);
				DFS(cnt+1);
				// BUG;
				for (int j=p[i].left;j!=i;j=p[j].left) rec(j);
				rec(i);
			}
		}
		return;
	}
	// multiple cover ends;
}dlx;
/*
0 1  2  3  4  5  6  7
  8  0  0  9  0  0  10
  11 0  0  12 0  0  0
  0  0  0  13 14 0  15
  0  0  16 0  17 18 0
  0  19 20 0  0  21 22
  0  23 0  0  0  0  24
*/

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SII(n,m)==2) {
    	dlx.init(m);
    	for (int i=1;i<=n;i++){
    		int x;SI(x);
    		while (x--) {
    			int tmp;SI(tmp);
    			dlx.link(i,tmp);
    		}
    	}
    	if (dlx.dfs(0)) {
    		cout << dlx.ans;
    		while (dlx.Ans.size()) {
    			cout << ' ' << dlx.Ans.top();
    			dlx.Ans.pop();
       		}
       		cout << endl;
    	}
    	else puts("NO");
    }
	return 0;
}