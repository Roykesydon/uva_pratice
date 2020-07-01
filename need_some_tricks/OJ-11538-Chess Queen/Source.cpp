#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main(void)
{
	long long int a, b,ca,cb,cb3;
	long long int ans;
	while (scanf("%lld %lld", &a, &b) && (a + b))
	{
		if (b > a)
		{
			b = a + b;
			a = b - a;
			b = b - a;
		}
		if (a == 2)
			ca = 1;
		else
			ca = a *(a - 1) / 2;
		if (b == 2)
			cb = 1;
		else
			cb = b *(b - 1) / 2;
		if (b == 2)
			cb3 = 0;
		else if (b == 3)
			cb3 = 1;
		else
			cb3 = b * (b - 1) * (b - 2) / 6;
		ans = ca * 2 * b+cb*2*a + cb * 2 * (1 + (a - b)) * 2 + 2 * 2 * 2 * cb3;
		printf("%lld\n",ans);
	}

	return 0;
}
