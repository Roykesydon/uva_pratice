#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int num;
	int sum;
	int st;
	int *s;
	s = (int*)malloc(sizeof(int) * 30000);
	cin >> num;
	while (num--)
	{
		cin >> st;
		for (int i = 0; i < st; i++)
			cin >> s[i];
		sort(s, s + st);
		sum = 0;
		for (int i = 0; i < st; i++)
			sum += abs(s[i] - s[(int)st / 2]);
		cout << sum << "\n";
	}

	return 0;
}