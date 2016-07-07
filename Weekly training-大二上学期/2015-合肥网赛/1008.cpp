/********************************************
Author         :Crystal
Created Time   :
File Name      :
********************************************/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cctype>
using namespace std;
typedef long long ll;
typedef pair<int ,int> pii;
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a);
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
//#define LOCAL
int a[60];
ll get(int cnt){
	ll res = 0;
	for(int i=0;i<cnt;i++){
		res = res + (1<<i)*a[i];
	}
	return res;
}

int main()
{
#ifdef LOCAL
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	int t;cin >> t;
	int kase = 1;
	while(t--){
		printf("Case #%d: ",kase++);
		int l,s1,s2;
		scanf("%d%d%d",&l,&s1,&s2);
		int x = l;
		CLR(a);
		int cnt = 0;
		int cnt1 = 0;
		while(x){
			a[cnt++]=x%2;
			if(x%2)cnt1++;
			x/=2;
		}
		if(cnt<s1 || (cnt==s1 && cnt1==cnt)){
			if(cnt<s1)printf("%lld\n",(ll)((1<<((ll)s1+1))-1));
			else{
				cnt++;
				CLR(a);
				a[cnt-1]=1;
				cnt1 = 1;
				for(int i=0;i<cnt && cnt1<s1;i++){
					if(!a[i]){
						a[i]=1;
						cnt1++;
					}
				}
				printf("%lld\n",get(cnt));
			}
		}
		else {
			if(cnt1 < s1){
				for(int i=0;i<cnt && cnt1 < s1;i++){
					if(!a[i]){
						a[i]=1;
						cnt1++;
					}
				}
				printf("%lld\n",get(cnt));
			}
			else if(cnt1 <= s2-1){
				if(cnt!=cnt1){
					int pos = 0;
					for(int i=0;i<cnt;i++){
						if(!a[i]){
							a[i]=1;
							cnt1++;
							pos = i;
							break;
						}
					}
					for(int i=pos-1;i>=0 && cnt1 >= s1;i--){
						if(a[i]){
							a[i]=0;
							cnt1--;
						}
					}
					printf("%lld\n",get(cnt));
				}
				else{
					cnt++;
					CLR(a);
					a[cnt-1]=1;
					cnt1 = 1;
					for(int i=0;i<cnt && cnt1<s1;i++){
						if(!a[i]){
							a[i]=1;
							cnt1++;
						}
					}
					printf("%lld\n",get(cnt));
				}
			}
			else{
				if(cnt1!=s2){
					int pos = 0;
					for(int i=0;i<cnt;i++){
						if(a[i]){
							a[i]=0;
							cnt1--;
						}
						if(cnt1<=s2-1){
							pos = i+1;
							break;
						}
					}
					while(a[pos]){
						pos++;
					}
					a[pos]=1;
					//cnt = max(pos+1,cnt);
					for(int i=0;i<pos;i++){
						if(a[i]){
							a[i]=0;
						}
					}
					for(int i=0;i<pos && cnt1<s1;i++){
						if(!a[i]){
							a[i]=1;
							cnt1++;
						}
					}
					printf("%lld\n",get(cnt));
				}
				else{
					cnt++;
					CLR(a);
					a[cnt-1]=1;
					cnt1 = 1;
					for(int i=0;i<cnt && cnt1<s1;i++){
						if(!a[i]){
							a[i]=1;
							cnt1++;
						}
					}
					printf("%lld\n",get(cnt));
				}
				
			}
		}
	}
	return 0;
}
