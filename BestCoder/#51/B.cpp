#include <iostream>
#include <string.h>
using namespace std;
int gcd(int a,int b)
{   
 	return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b)
{    
	return a/gcd(a,b)*b;
}
const int maxn=3000005;
int num[maxn];
int visit[maxn];
#define mod 3221225473
int main()
{    
	int n; 
	int kase = 1; 
	//freopen("in.txt","r",stdin);
	int t;cin >> t;    
	while(t--)   
	{      
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&num[i]);        
		memset(visit,0,sizeof(visit));        
			int res=1,flag;        
			for(int i=1;i<=n;i++)        
			{            
				int count=0;         
				flag=i;           
				while(!visit[flag])         
				{    
					//cout << flag << ' ' << num[flag] <<'\n';            
					count++;                
					visit[flag]=1;                
					flag=num[flag];    
					//cout << flag << ' ' << num[flag] <<'\n';              
				}  
				if(count)res=lcm(count,res)%mod;        
			}        
			cout<<res<<endl;    
		}    
		return 0;
}

