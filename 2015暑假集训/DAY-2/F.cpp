//
//  Created by  CQUWEL
//  Copyright (c) 2015Äê CQUWEL. All rights reserved.
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
#include <numeric>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define filetest
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

struct Stu{
	string sid;
	int cid;
	string name;
	int chi,mat,eng,pro;
	bool in;
	int pas;
	int tot;
	double ave;
}stu[1100];

int cnt;

void print_main_menu(){
	printf("Welcome to Student Performance Management System (SPMS).\n\n");
	printf("1 - Add\n");
	printf("2 - Remove\n");
	printf("3 - Query\n");
	printf("4 - Show ranking\n");
	printf("5 - Show Statisticsn\n");
	printf("0 - Exit\n\n"); 
}

void add_stu(){
	int op;
	while (1){
		printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
		string sid;int cid;string name;int chi;int mat;int eng;int pro;
		cin >> sid;
		if (sid=="0") break;
		cin >> cid >> name >> chi >> mat >> eng >> pro;
		int flag=0;
		for (int i=0;i<cnt;i++) {
			if (stu[i].in && stu[i].cid==cid){
				printf("Duplicated SID.\n");
				flag=1;
				break;
			}
		}
		if (flag) continue;
		stu[cnt].sid=sid; stu[cnt].cid=cid;
		stu[cnt].name=name;stu[cnt].chi=chi;stu[cnt].mat=mat;stu[cnt].eng=eng;stu[cnt].pro=pro;
		stu[cnt].in=true;stu[cnt].pas=0;stu[cnt].tot=stu[cnt].chi + stu[cnt].mat + stu[cnt].eng + stu[cnt].pro;
		stu[cnt].ave=(double) stu[cnt].tot/4.00;
		cnt++;
	}
} 

int rem_stu(){
	int rem_n;
	while (1){
		printf("Please enter SID or name. Enter 0 to finish.\n");
		string s;
		cin >> s;
		rem_n=0;
		if (s=="0") break;
		for (int i=0;i<cnt;i++){
			if (stu[i].in && (stu[i].name==s || stu[i].sid==s)){
				stu[i].in=false;
				rem_n++;
			}
		}
		printf("%d student(s) removed.\n",rem_n);
	}
}
bool cmp(Stu a, Stu b){
	return a.tot>b.tot;
} 

int get_rank(string s){
	Stu temp[1100];
	int ccnt=0;
	for (int i=0;i<cnt;i++){
		if (stu[i].in) temp[ccnt++]=stu[i];
	}
	sort(temp,temp+ccnt,cmp);
	
	
}
void query_stu(){
	while (1){
		printf("Please enter SID or name. Enter 0 to finish.\n");
		string s;
		cin >> s;
		if (s=="0") break;
		for (int i=0;i<cnt;i++){
			if (stu[i].in && (stu[i].name==s || stu[i].sid==s)){
				int rank=get_rank(stu[i].sid);
				cout << rank << " ";
				cout << stu[i].sid << " ";
				cout << stu[i].cid  << " ";
				cout << stu[i].name << " ";
				cout << stu[i].chi << " " << stu[i].mat << " " << stu[i].eng << " " << stu[i].pro << " ";
				cout << stu[i].tot << " " ;
				printf("%.2lf\n",stu[i].ave+(1e-5));
			}
		}
	}
}

int main(){
#ifdef LOCAL
//	  freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
#endif
	cnt=0;
	int op;
	while (1){
		print_main_menu();
		cin >> op;
		if (op==0) break;
		else if(op==1) add_stu();
		else if(op==2) rem_stu();
		else if(op==3) query_stu();
	}
}


