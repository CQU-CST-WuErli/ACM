#include<cstdio>
#include<string.h>

using namespace std;
char M_msg[1000], key[100], C_msg[1000];
int getNum(int a, int b)
{
	if (b>96)b -= 32;
	bool big = true;
	if (a>96)
	{
		big = false;
		a -= 32;
	}
	a = a - 65, b = b - 65;
	int e = a + b;
	if (e>25)e -= 25;
	if (!big)e += 32;
	return e + 65;
}
void change()
{
	int i = 0;
	for (int j = 0; M_msg[i] != '\0'; ++i, ++j)
	{
		if (key[j] == '\0')j = 0;
		C_msg[i] = (char)getNum((int)M_msg[i], (int)key[j]);
	}
	C_msg[i] = '\0';
}
int main()
{
	scanf("%s", key,sizeof(key));
	scanf("%s", M_msg,sizeof(M_msg));
	change();
	printf("%s", C_msg,sizeof(C_msg));
	return 0;
}
