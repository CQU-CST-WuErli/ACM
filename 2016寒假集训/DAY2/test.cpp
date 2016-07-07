#include<bits/stdc++.h>
using namespace std;

string s;
int check(char c)
{
    if(c=='(')return 1;
    if(c==')')return 2;
    if(c==' ')return 3;
    if(c<='Z'&&c>='A')return 3;
    if(c<='z'&&c>='a')return 3;
    return 4;
}
int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    getline(cin,s);
    int ans = 0;
    int flag = 0;
    for(int i=0;i<s.size();i++)
    {
        if(check(s[i])==2)
        {
            if(flag == 1)
                flag = 0;
            else
                ans += 1;
        }
        else if(check(s[i])==1)
        {
            if(flag==1)
                ans++;
            flag = 1;
        }
        else if(check(s[i])==3)
            continue;
        else if(check(s[i])==4)
        {
            if(flag==1)
                ans++;
            flag = 0;
        }
    }
    cout<<ans+flag<<endl;
}
