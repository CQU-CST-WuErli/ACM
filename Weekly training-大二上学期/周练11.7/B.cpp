#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

char ram[1100][10];
int rig[1100];

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T;
	scanf("%d", &T);
	getchar();getchar();
	int kase=1;
	while(T--)
	{
		memset(rig, 0, sizeof(rig));
		memset(ram, 0, sizeof(ram));
		int adlen = 0;
		while(1)
		{
			gets(ram[adlen]);
			if(ram[adlen][0]=='\0')  break;
			adlen++;
		}
		int cary = 0;
		int inp = 0;
		int a,b;
		while(1)
		{
			cary++;
			//printf("c:%d r8:%d r9:%d	", cary, rig[8], rig[9]);
			//puts(ram[inp]);
			//system("pause");
			a = ram[inp][1]-'0';
			b = ram[inp][2]-'0';
			if(ram[inp][0] == '1') break;
			if(ram[inp][0] == '2')
			{
				rig[a] = b;
			}
			if(ram[inp][0] == '3')
			{
				rig[a] += b;
				rig[a] %= 1000;
			}
			if(ram[inp][0] == '4')
			{
				rig[a] *= b;
				rig[a] %= 1000;
			}
			if(ram[inp][0] == '5')
			{
				rig[a] = rig[b];
			}
			if(ram[inp][0] == '6')
			{
				rig[a] += rig[b];
				rig[a] %= 1000;
			}
			if(ram[inp][0] == '7')
			{
				rig[a] *= rig[b];
				rig[a] %= 1000;
			}
			if(ram[inp][0] == '8')
			{
				int tem=0;
				for (int i=0;i<3;i++) tem=tem*10+ram[rig[b]][i]-'0';
				rig[a] = tem;
			}
			if(ram[inp][0] == '9')
			{
				int tmp =rig[a];
				ram[rig[b]][2]=tmp%10+'0';
				tmp/=10;
				ram[rig[b]][1]=tmp%10+'0';
				tmp/=10;
				ram[rig[b]][0]=tmp%10+'0';
			}
			if(ram[inp][0] == '0' && rig[b])
			{
				inp = rig[a];
			}
			else
			{
				inp++;
			}

		}
		printf("%d\n", cary);
		if (T) cout << endl;
	}
	
	return 0;
}
