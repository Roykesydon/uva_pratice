#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000005
int failure[MAXN];
void KMP(string &t, string &p)
{
	if (p.size() > t.size())
		return;

	for (int i = 0, j = -1; i < t.size(); ++i)
	{
		while (j >= 0 && p[j + 1] != t[i])
			j = failure[j];
		if (p[j + 1] == t[i])
			j++;
		if (j == p.size() - 1)
		{
			cout << i - p.size() + 1 << " ";
			j = failure[j];
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	while (cin >> str && str != ".")
	{
		for (int i = 1, j = failure[0] = -1; i < str.size(); ++i)
		{
			while (j >= 0 && str[j + 1] != str[i])
				j = failure[j];
			if (str[j + 1] == str[i])
				j++;
			failure[i] = j;
		}
		for (int i = 0; i < str.size(); i++)
			failure[i]++;
		if (str.size() % (str.size() - failure[str.size() - 1]) != 0)
			cout << "1\n";
		else
			cout << str.size() / (str.size() - failure[str.size() - 1]) << '\n';
	}

	return 0;
}
