#include<stdio.h>
#include<string.h>

int t;
char s[15];
int main()
{
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	cin >> t;
	scanf("%d",&t);
	getchar();
	while (t--){
		gets(s);
		strcpy(s,s+2);
	//	puts(s);
		long long x=0,temp=1;
		strrev(s);
		for (int i=0;s[i];i++){
			x+=(s[i]-'0')*temp;
			temp*=10;
		}
	//	cout << x<< endl;
	//	cout << temp << endl;
		for (int i=2;i<=x;i++){
			while(x%i==0 && temp%i==0) {
				x/=i;
				temp/=i;
			}
		}
//		cout << x << "/" << temp << endl;
		printf("%d",x);
		printf("/");
		printf("%d\n",temp);
	}
	return 0;
}

