/*
ID: meixiny1
PROG: test
LANG: C++11
*/
#include <stdio.h>
#include <string.h>
int stak[2000005];
int a[2000005];
int main()
{
	//freopen("in.txt", "r", stdin);
	int n,m,i,j;
	int end,top;
	int l;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		end = 1, top = 1;
		stak[top] = a[1];
		for(i=2;i<=m;i++){
			while(end >= top && stak[end]>a[i]){
				end--;
			}
			end++;
			stak[end]=a[i];
		}
		printf("%d",stak[top]);
		for(i=m+1;i<=n;i++){
			l = a[i-m];
			if(l==stak[top])top++;
			while(end >= top && stak[end]>a[i]){
				end--;
			}
			end++;
			stak[end]=a[i];
			printf(" %d",stak[top]);
		}
		end = 1, top = 1;
		stak[top] = a[1];
		for(i=2;i<=m;i++){
			while(end >= top && stak[end]<a[i]){
				end--;
			}
			end++;
			stak[end]=a[i];
		}
		printf("\n");
		printf("%d",stak[top]);
		for(i=m+1;i<=n;i++){
			l = a[i-m];
			if(l==stak[top])top++;
			while(end >= top && stak[end]<a[i]){
				end--;
			}
			end++;
			stak[end]=a[i];
			printf(" %d",stak[top]);

		}
		printf("\n");
	}
	return 0;
}