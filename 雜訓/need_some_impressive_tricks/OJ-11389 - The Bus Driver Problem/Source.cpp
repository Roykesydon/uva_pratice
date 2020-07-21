#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, d, r;
	int morn[100], even[100];
	int ans;
	while (scanf("%d %d %d", &n, &d, &r) && (n && (d && r)))
	{
		ans = 0;
		for (int i = 0; i < 100; i++)
		{
			morn[i] = 0;
			even[i] = 0;
		}

		for (int i = 0; i < n; i++)
			scanf("%d", morn + i);
		for (int i = 0; i < n; i++)
			scanf("%d", even + i);

		sort(morn, morn + n);
		sort(even, even + n);

		for (int i = 0; i < n; i++)
		{
			if(morn[i] + even[n - i - 1] > d)
			ans+=((morn[i] + even[n - i - 1] - d)* r);
		}
		cout << ans << endl;
	}


	return 0;
}